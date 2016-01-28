#include "precompiled_header.h"

#include "NVIC_tools.h"

#include "stm32f4xx.h"
#include "core_cm4.h"
#include "misc.h"
#include "core_cmFunc.h"

// sets groups number to 4, enables IRQ's.
void NVIC_init(){
	//4 bits for pre-emption priority 0 bits for subpriority
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	__enable_irq();
};
