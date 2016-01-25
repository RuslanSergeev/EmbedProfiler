#include "PROFILING_tools.h"

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

/*!
 * @var int32_t PROFILER_instance_last_index
 * @brief
*/
int32_t PROFILER_instance_last_index = 0;

/*!
 * @var
 * @brief
*/
const char* PROFILER_files_names[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @var
 * @brief
*/
const char* PROFILER_procedures_names[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @var
 * @brief
*/
uint32_t PROFILER_lines_numbers[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @var
 * @brief
*/
uint32_t PROFILER_times_called[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @var
 * @brief
*/
PROFILER_timestruct PROFILER_total_times[PROFILER_TOTAL_PROFILERS] = {0};


static float PROFILER_timestamp_diff_to_float(int32_t PROFILER_instance_index){
    return (PROFILER_total_times[PROFILER_instance_index]).tv_sec +
            (PROFILER_total_times[PROFILER_instance_index]).tv_nsec*1.e-9;
}		
		
static float PROFILER_calculate_all_profiles_average(){
    return PROFILER_timestamp_diff_to_float(PROFILER_GLOBAL_PROFILE_INDEX);
}			
			
static float PROFILER_get_current_profile_average(int32_t PROFILER_instance_index){
    static float PROFILER_total_average = PROFILER_calculate_all_profiles_average();
    return 100*PROFILER_timestamp_diff_to_float(PROFILER_instance_index)/PROFILER_total_average;
}				

static void PROFILER_log_instance(uint16_t PROFILER_instance_index){
        fprintf(stderr,"[file %s, line %d  fun:%s] times called: %u average: %f%%\n",
			PROFILER_files_names[PROFILER_instance_index],
            PROFILER_lines_numbers[PROFILER_instance_index],
			PROFILER_procedures_names[PROFILER_instance_index],
            PROFILER_times_called[PROFILER_instance_index],
			PROFILER_get_current_profile_average(PROFILER_instance_index));
}		

	
void PROFILER_log(){
	PROFILER_calculate_all_profiles_average();
    for(int32_t PROFILER_instance_index = PROFILER_LOCAL_PROFILES_BEGIN; PROFILER_instance_index<PROFILER_instance_last_index; ++PROFILER_instance_index){
		PROFILER_log_instance(PROFILER_instance_index);
	}
}	
