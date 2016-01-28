#ifndef M_TIME_H
#define M_TIME_H

#include <stdint.h>
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "misc.h"
#include "PWM_tools.h"

#ifdef __cplusplus
extern "C"{
#endif

#define SysTickReload	0xFFFFFF
extern uint32_t SystemCoreClock;

typedef struct system_timer_struct{
	uint64_t num_interrupts;
	int32_t num_ticks;
} system_timer_typedef;

extern volatile system_timer_typedef SYSTEM_TIMER;

static inline __attribute__((always_inline))
void system_timer_update(system_timer_typedef *p_DEST){
	(p_DEST)->num_interrupts = SYSTEM_TIMER.num_interrupts;
	(p_DEST)->num_ticks = (SysTickReload-SysTick->VAL);
}

/*
 * @brief
 * 	Получаем разницу времени [system_tymer_typedef] между двумя моментами времени представленными структурой system_tymer_typedef.
 *  Для заполнения соответствующих структур следует воспользоваться system_tymer_get_time-макросом.
 * @param
 *  p_next - указатель на более свежий момент времени. [pointer system_tymer_typedef]
 * @param
 *  p_prev - указатель на прошлый момент времени. [pointer system_tymer_typedef]
 * @param
 *  p_dest - указатель , в котором сохраняется разница. [pointer system_tymer_typedef]
 * */
static inline __attribute__((always_inline))
void system_timer_get_diff(system_timer_typedef *p_next, system_timer_typedef *p_prev, system_timer_typedef *p_dest){
	p_dest->num_interrupts = (p_next->num_interrupts - p_prev->num_interrupts);
	/* Системный таймер считает в сторону уменьшения тиков,
	 * Но функции system_timer_update число тиков вычитается из максимального
	 * и получаем увеличивающийся счётчик. Поэтому здесь уменьшаемое - будущий
	 * счётчик, а вычитаемое - прошлый.*/
	p_dest->num_ticks = p_next->num_ticks - p_prev->num_ticks;
}

static inline __attribute__((always_inline))
float system_timer_get_time(system_timer_typedef *p_timer){
	return p_timer->num_interrupts*(((float)SysTickReload)/SystemCoreClock) +
			((float)p_timer->num_ticks)/SystemCoreClock;
}

static inline __attribute__((always_inline))
float system_timer_get_system_time(){
	system_timer_update((system_timer_typedef *)&SYSTEM_TIMER);
	return system_timer_get_time((system_timer_typedef *)&SYSTEM_TIMER);
}

static inline __attribute__((always_inline))
float system_timer_get_delta(){
	system_timer_typedef current_timer;
	static system_timer_typedef previous_timer = {
			.num_interrupts = 0,
			.num_ticks = SysTickReload
	};
	system_timer_typedef delta_timer;

	float delta_time;

	system_timer_update(&current_timer);
	system_timer_get_diff(&current_timer, &previous_timer, &delta_timer);
	delta_time = system_timer_get_time(&delta_timer);
	previous_timer = current_timer;

	return delta_time;
}

/*
 * @brief
 *	Инициализация периферии таймера.
 * */
void TIME_init();

/*
 * @brief
 *	Приостанавливает выполнение текущего потока до завершения
 *	необходимого интервала [в микросекундах].
 * @param
 * 	us - число микросекунд, которое необходимо выждать, прежде
 * 	чем выполнение потока возобновится. [float]
 * */
void m_usleep(float us);

void system_timer_test();


#ifdef __cplusplus
}
#endif

#endif
