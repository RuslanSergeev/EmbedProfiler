#include "precompiled_header.h"

#include "mtime.h"

volatile system_timer_typedef SYSTEM_TIMER;

void TIME_init(){
	SYSTEM_TIMER.num_interrupts = 0;
	SYSTEM_TIMER.num_ticks = 0;
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	SysTick_Config(SysTickReload);
};

void SysTick_Handler(){
	SYSTEM_TIMER.num_interrupts += 1;
};

void  m_usleep(float us)
{
	system_timer_typedef timer_init, timer_curr, timer_diff;
	system_timer_update(&timer_init);

	float diff;

	do{
		system_timer_update(&timer_curr);
		system_timer_get_diff(&timer_curr,&timer_init,&timer_diff);
		diff = system_timer_get_time(&timer_diff);
	}while(diff*1000000 < us);
};

void system_timer_test(){
//	system_timer_typedef init, cur, prev, delta;
	float cur_time, delta_time;

//	system_timer_update(&init);
//	prev = init;
	while(1){
//		system_timer_update(&cur);//ok
////		cur_time = system_timer_get_time(&cur);
//		system_timer_get_diff(&cur, &prev, &delta);//no
//		delta_time = system_timer_get_time(&delta);//ok
//		prev = cur;
		delta_time = system_timer_get_delta();
		printf("d: %f\n",delta_time);
	}
}
