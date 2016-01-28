#include "NVIC_tools.h"
#include "USART_tools.h"
#include "system_timer.h"


int main(void)
{
    SYSCFG_CompensationCellCmd(ENABLE);
    SystemCoreClockUpdate();

    UART_init();
    NVIC_init();
    TIME_init();


    PROFILER_global_start();

    PROFILER_local_start();

    PROFILER_local_start();
    m_usleep(1);
    PROFILER_local_stop();

    PROFILER_local_start();
    m_usleep(1);
    PROFILER_local_stop();

    PROFILER_local_start();
    m_usleep(1);
    PROFILER_local_stop();

    PROFILER_local_start();
    m_usleep(1);
    PROFILER_local_stop();

    PROFILER_local_stop();

    PROFILER_global_stop();

    PROFILER_log();


    while(1){
    }

    return 0;
}
