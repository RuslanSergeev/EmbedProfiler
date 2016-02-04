/**
  **************************************************************************************************************************
  * @file    PROFILING_tools.h
  * @author  Sergeev Ruslan. 
  * 	OOO SPUTNIX, 
  * 	MIPT High-Precision Attitude Control Systems Laboratory 
  * @version V1.0.0
  * @date    23-January-2016
  * @brief   Файл PROFILING_tools.h является частью библиотеки EmbedPROFILER - библиотеки профилировщика времени вызовов.
        Профилировщик времени вызовов - средство анализа исходного кода программ, представляющее
        программистам и инженерам анализировать время, затраченное на выполнение того или
        иного участка кода в процентном соотношении (относительно общего времени работы профилировщика).
  **************************************************************************************************************************
  * @attention
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, OOO SPUTNIX, MIPT High-Precision Attitude Control Systems Laboratory 
  * SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES 
  * WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH FIRMWARE 
  * AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
  * IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2016 RUSLAN SERGEEV</center></h2>
  **************************************************************************************************************************
  */


#ifndef PROFILING_TOOLS_H
#define PROFILING_TOOLS_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*!
 * @example profiler_example.cpp
 * Пример работы с профилировщиком.
 * */

/*! 
 * @addtogroup Портируемая_секция
 * @{
 * @brief Эти функции необходимо определить для вашей платформы.
 *        Остальная часть кода профилировщика является платформо-независимой.
 *
 * EmbedPROFILER проектировался для исполнения во встраиваемых системах независимо от аппаратной платформы.
 * Для того, чтобы EmbedPROFILER можно было перенести на интересующую вас платформу, необходимо реализовать
 * на данной платформе определённые в этой секции процедуры и макросы.
 * */


/*!
 * @typedef PROFILER_timestruct
 * @brief Тип переменной для хранения измерений времени.
 *
 * Для оптимальной работы не рекомендуется хранение
 * времени в целочисленных типах.
 * */

#ifndef PLATFORM
#define PLATFORM STM32F4XX
#include "stm32f4xx.h"
#endif


#include <mtime.h>
typedef system_timer_typedef PROFILER_timestruct;

 
/*!
 * @}
 * */

/*!
 * @def PROFILER_TOTAL_PROFILERS
 * @brief Максимальное число работающих профилировщиков времени вызова.
 *
 * Это число определяет размеры массивов для хранения указателей на
 * названия функций, имена файлов, номера строк и число вызовов.
 * */	
#define PROFILER_TOTAL_PROFILERS                1024


/*!
 * @def PROFILER_GLOBAL_PROFILE_INDEX
 * @brief Индекс "глобального профиллировщика" - начального и главного профилировщика времени вызовов.

 * Этот профилировщик должен быть вызван в начале работы с системой профилирования времени вызовов.
 * Измеренное глобальным профилировщиком время будет считаться временем работы системы.
 * Проценты потреблённого времени, рассчитанные остальными профилировщиками представляют собой
 * отношение времени работы конкретного профилировщика к времени работы глобального профилировщика:
 * @f[
 *      average[i] = \frac{PROFILER\_total\_times[i]}{PROFILER\_total\_times[0]}
 * @f]
 * */
#define PROFILER_GLOBAL_PROFILE_INDEX           0


/*!
 * @def PROFILER_LOCAL_PROFILES_BEGIN
 * @brief Начальный индекс локальных профилировщиков.
 *
 * С данного индекса будут следовать локальные профилировщики - замеряющие время выполнения
 * конкретного локального вызова.
 * */
#define PROFILER_LOCAL_PROFILES_BEGIN           ((PROFILER_GLOBAL_PROFILE_INDEX)+1)

/*!
 * @def PROFILER_INSTANCE_NOT_INITIALIZED
 * @brief Определяет неинициализированный индекс.
 *
 * Используется для определения того является ли данный профилировщик инициализированным
 * или он был вызван впервые и его ещё необходимо инициализировать.
 * */	
#define PROFILER_INSTANCE_NOT_INITIALIZED       -1

extern int32_t PROFILER_instance_last_index;
extern const char* PROFILER_files_names[PROFILER_TOTAL_PROFILERS];
extern const char* PROFILER_procedures_names[PROFILER_TOTAL_PROFILERS];
extern uint32_t PROFILER_lines_numbers[PROFILER_TOTAL_PROFILERS];
extern uint32_t PROFILER_times_called[PROFILER_TOTAL_PROFILERS];
extern PROFILER_timestruct PROFILER_total_times[PROFILER_TOTAL_PROFILERS];

static inline __attribute__((always_inline))
void PROFILER_refresh_time_consumed(PROFILER_timestruct PROFILER_begin_time, PROFILER_timestruct PROFILER_end_time, int32_t PROFILER_instance_index);

static inline __attribute__((always_inline))
void PROFILER_get_current_time(PROFILER_timestruct *PROFILER_timestruct_instance);

static inline __attribute__((always_inline))
void PROFILER_refresh_times_called(int32_t PROFILER_instance_index);

static inline __attribute__((always_inline))
int32_t PROFILER_get_free_instance_index();

static inline __attribute__((always_inline))
void PROFILER_instance_init(const char *file, const char *function, const int32_t line, const int32_t PROFILER_instance_index);

static inline __attribute__((always_inline))
uint8_t PROFILER_instance_is_not_initialized(int32_t PROFILER_instance_index);

/*!
 * @addtogroup Портируемая_секция
 * @{
 * */

/*!
 * @fn void PROFILER_log()
 * @brief Вывести отчёт о работе профилировщика.
 *
 * Сообщает затраченное на работу каждого профилировщика время, имена файлов, номера строк, названия функций где был создан данный профилировщик.
 * Также сообщает число вызовов данного профилировщика.
 * */
void PROFILER_log();

/*!
 * @fn PROFILER_get_current_time(PROFILER_timestruct *PROFILER_timestruct_instance)
 * @brief Получить текущее время в системе.
 * @param [out] PROFILER_timestruct *PROFILER_timestruct_instance
 * \n Указатель на структуру, в которой будет сохранено системное время.
 * */

void PROFILER_get_current_time(PROFILER_timestruct *PROFILER_timestruct_instance){
        system_timer_update(PROFILER_timestruct_instance);
}

/*!
 * @fn void PROFILER_refresh_time_consumed(PROFILER_timestruct PROFILER_begin_time, PROFILER_timestruct PROFILER_end_time, int32_t PROFILER_instance_index)
 * @brief Обновить общее время затраченное на работу указанного профилировщика
 * за все его вызовы.
 *
 * Добавляет время потраченное указанным профилировщиком за последний вызов
 * к общему времени за все вызовы, затраченному указанным профилировщиком.
 * @param [in] PROFILER_timestruct PROFILER_begin_time
 * \n Время начала работы (очередного вызова) локального профилировщика.
 * @param [in] PROFILER_timestruct PROFILER_end_time
 * \n Время окончания работы (очередного завершения) локального профилировщика.
 * @param [in] int32_t PROFILER_instance_index
 * \n Индекс локального профилировщика.
 * */

void PROFILER_refresh_time_consumed(PROFILER_timestruct PROFILER_begin_time, PROFILER_timestruct PROFILER_end_time, int32_t PROFILER_instance_index){
	PROFILER_timestruct local_diff;
    system_timer_get_diff_timer(&PROFILER_end_time, &PROFILER_begin_time, &local_diff);
    PROFILER_total_times[PROFILER_instance_index].num_interrupts += local_diff.num_interrupts;
    PROFILER_total_times[PROFILER_instance_index].num_ticks += local_diff.num_ticks;
}


/*!
 * @}
*/

/*!
 * @fn void PROFILER_refresh_times_called(int32_t PROFILER_instance_index)
 * @brief Обновить общее число вызовов данного профилировщика.
 *
 * Общее число вызовов профилировщика даёт понять, сколько раз
 * управление достигло секции, которую профилирует данный
 * профилировщик.
 * @param [in] int32_t PROFILER_instance_index
 * \n Индекс локального профилировщика.
 * */
void PROFILER_refresh_times_called(int32_t PROFILER_instance_index){
    PROFILER_times_called[PROFILER_instance_index] += 1;
}

/*!
 * @def PROFILER_local_start()
 * @brief Начинает/продолжает профилировку секции исходного кода.
 *
 * Если профилировщик начинает работу впервые, то происходит запись
 * текущего местоположения в соответствующие массивы.
 * Запоминается текущее время.
 * */	
#define PROFILER_local_start()\
	{\
		static int32_t PROFILER_instance_index = PROFILER_INSTANCE_NOT_INITIALIZED;\
		PROFILER_timestruct PROFILER_begin_time, PROFILER_end_time;\
		if(PROFILER_instance_is_not_initialized(PROFILER_instance_index)){\
            PROFILER_instance_index = PROFILER_get_free_instance_index();\
            PROFILER_instance_init(__FILE__, __FUNCTION__, __LINE__, PROFILER_instance_index);\
		}\
        PROFILER_refresh_times_called(PROFILER_instance_index);\
        PROFILER_get_current_time(&PROFILER_begin_time);
		
/*!
 * @def PROFILER_local_stop()
 * @brief Окончание работы/вызова локального профилировщика.
 *
 * Запоминается время окончания работы/вызова профилировщика.
 * Это время, как и время начала работы/вызова профилировщика
 * используется для обновления общего затраченного времени.
 * Общее затраченное профилировщиком время используется системой
 * профилировки для оценки загруженности профилируемой секции кода.
 * */		
#define PROFILER_local_stop()\
            PROFILER_get_current_time(&PROFILER_end_time);\
            PROFILER_refresh_time_consumed(PROFILER_begin_time, PROFILER_end_time, PROFILER_instance_index);\
    }

/*!
 * @addtogroup Портируемая_секция
 * @{
 * */

/*!
 * @def PROFILER_global_start()
 * @brief Начало работы глобального профилировщика.
 *
 * Запоминается время начала работы системы профилирования.
 * Которое используется в дальнейшем для расчёта времени работы системы
 * профилирования. Добавлено в портируемый раздел, поскольку инициализация
 * профилировщика может быть платформо-зависимой.
 * */

#define PROFILER_global_start() PROFILER_local_start()

/*!
 * @def PROFILER_global_stop()
 * @brief Окончание работы глобального профилировщика.
 *
 * Запоминается время окончания работы системы профилирования.
 * Которое используется в дальнейшем для расчёта времени работы системы
 * профилирования.Добавлено в портируемый раздел, поскольку завершение
 * работы профилировщика может быть платформо-зависимой.
 * */
#define PROFILER_global_stop() PROFILER_local_stop()

/*!
 * @}
 * */

/*!
 * @fn int32_t PROFILER_get_free_instance_index()
 * @brief Определяет индекс следующего свободного профилировщика.
 *
 * Когда профилировщик начинает свою работу впервые,
 * система присваивает ему некоторый индекс, посредством которого с профилировщиком
 * в дальнейшем выполняются все остальные манипуляции.
 * @return int32_t индекс следующего свободного профилировщика
 * */
int32_t PROFILER_get_free_instance_index(){
    if(++PROFILER_instance_last_index<PROFILER_TOTAL_PROFILERS){
        return PROFILER_instance_last_index;
    }
    else{
        return PROFILER_INSTANCE_NOT_INITIALIZED;
    }
}

/*!
 * @fn void PROFILER_instance_init(const char *file, const char *function, const int32_t line, const int32_t PROFILER_instance_index)
 * @brief Инициализирует экземпляр профилировщика.
 *
 * Когда профилировщик начинает свою работу впервые,
 * система профилировки запоминает его положение в исходном коде.
 * @param [in] const char *file
 * \n Название файла, в котором работает профилировщик.
 * @param [in] const char *function
 * \n Название функции, в которой работает профилировщик.
 * @param [in] const int32_t line
 * \n Номер строки, в которой начинается выполнение профилировщика.
 * Профилировщик измеряет время выполнения сегмента кода от этой строки
 * до вызова PROFILIER_local_stop()
 * @param [in] const int32_t PROFILER_instance_index
 * \n Индекс инициализируемого профилировщика.
 * */
void PROFILER_instance_init(const char *file, const char *function, const int32_t line, const int32_t PROFILER_instance_index){
        PROFILER_files_names[PROFILER_instance_index] = file;
        PROFILER_procedures_names[PROFILER_instance_index] = function;
        PROFILER_lines_numbers[PROFILER_instance_index] = line;
}

/*!
 * @fn uint8_t PROFILER_instance_is_not_initialized(int32_t PROFILER_instance_index)
 * @brief Сообщает инициализирован ли профилировщик или нет.
 *
 * Возвращает 0, если профилировщик ещё не инициализирован (работает впервые).
 * Возвращает значение отличное от 0, если профилировщик уже не нуждается в
 * инициализации (работает не в первые).
 * @param [in] int32_t PROFILER_instance_index
 * \n Индекс профилировщика.
 * @return
 * */
uint8_t PROFILER_instance_is_not_initialized(int32_t PROFILER_instance_index){
	return PROFILER_INSTANCE_NOT_INITIALIZED == PROFILER_instance_index;
}


#endif //PROFILING_TOOLS_H

