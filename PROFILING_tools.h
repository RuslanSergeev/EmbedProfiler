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
#include <time.h>

/*! 
 * @addtogroup Configuration_section_for_EmbedPROFILER
 * @{
 * */
 
 /*!
  * @typedef PROFILER_timestruct
  * @brief
  * */
 typedef struct timespec PROFILER_timestruct;
 
/*!
 * @def PROFILER_TOTAL_PROFILERS
 * @brief
 * */	
#define PROFILER_TOTAL_PROFILERS                1024

/*!
 * @}
 * */

/*!
 * @def PROFILER_GLOBAL_PROFILE_INDEX
 * @brief
 * */
#define PROFILER_GLOBAL_PROFILE_INDEX           0


/*!
 * @def PROFILER_LOCAL_PROFILES_BEGIN
 * @brief
 * */
#define PROFILER_LOCAL_PROFILES_BEGIN           ((PROFILER_GLOBAL_PROFILE_INDEX)+1)

/*!
 * @def PROFILER_INSTANCE_NOT_INITIALIZED
 * @brief
 * */	
#define PROFILER_INSTANCE_NOT_INITIALIZED       1

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
int32_t PROFILER_instance_init(const char *file, const char *function, const int32_t line);

static inline __attribute__((always_inline))
uint8_t PROFILER_instance_is_not_initialized(int32_t PROFILER_instance_index);

/*!
 * @fn void PROFILER_log()
 * @brief
 * */
void PROFILER_log();

/*!
 * @addtogroup port functions for EmbedPROFILER
 * @{
 * */

/*!
 * @fn PROFILER_get_current_time(PROFILER_timestruct *PROFILER_timestruct_instance)
 * @brief brief description
 * @param [out] PROFILER_timestruct *PROFILER_timestruct_instance
 * */
void PROFILER_get_current_time(PROFILER_timestruct *PROFILER_timestruct_instance){
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID,PROFILER_timestruct_instance);
}

/*!
 * @fn void PROFILER_refresh_time_consumed(PROFILER_timestruct PROFILER_begin_time, PROFILER_timestruct PROFILER_end_time, int32_t PROFILER_instance_index)
 * @brief
 * @param [in] @ref PROFILER_timestruct PROFILER_begin_time
 * @param [in] @ref PROFILER_timestruct PROFILER_end_time
 * @param [in] int32_t PROFILER_instance_index
 * */
void PROFILER_refresh_time_consumed(PROFILER_timestruct PROFILER_begin_time, PROFILER_timestruct PROFILER_end_time, int32_t PROFILER_instance_index){
    static int32_t PROFILER_seconds_summed = (PROFILER_total_times[PROFILER_instance_index].tv_nsec)/1000000000;\
    PROFILER_total_times[PROFILER_instance_index].tv_sec +=\
        PROFILER_end_time.tv_sec - PROFILER_begin_time.tv_sec + PROFILER_seconds_summed;\
    PROFILER_total_times[PROFILER_instance_index].tv_nsec =\
        PROFILER_total_times[PROFILER_instance_index].tv_nsec-1000000000*PROFILER_seconds_summed +\
        (PROFILER_end_time.tv_nsec - PROFILER_begin_time.tv_nsec);\
}

/*!
 * @}
*/

/*!
 * @fn void PROFILER_refresh_times_called(int32_t PROFILER_instance_index)
 * @brief
 * @param [in] int32_t PROFILER_instance_index
 * */
void PROFILER_refresh_times_called(int32_t PROFILER_instance_index){
    PROFILER_times_called[PROFILER_instance_index] += 1;
}

/*!
 * @def PROFILER_local_start()
 * @brief
 * */	
#define PROFILER_local_start()\
	{\
		static int32_t PROFILER_instance_index = PROFILER_INSTANCE_NOT_INITIALIZED;\
		PROFILER_timestruct PROFILER_begin_time, PROFILER_end_time;\
		if(PROFILER_instance_is_not_initialized(PROFILER_instance_index)){\
            PROFILER_instance_index = PROFILER_instance_init(__FILE__, __FUNCTION__, __LINE__);\
		}\
        PROFILER_refresh_times_called(PROFILER_instance_index);\
        PROFILER_get_current_time(&PROFILER_begin_time);
		
/*!
 * @def PROFILER_local_stop()
 * @brief
 * */		
#define PROFILER_local_stop()\
            PROFILER_get_current_time(&PROFILER_end_time);\
            PROFILER_refresh_time_consumed(PROFILER_begin_time, PROFILER_end_time, PROFILER_instance_index);\
    }

/*!
 * @def PROFILER_global_start()
 * @brief
 * */
#define PROFILER_global_start() PROFILER_local_start()

/*!
 * @def PROFILER_local_stop()
 * @brief
 * */
#define PROFILER_global_stop() PROFILER_local_stop()

/*!
 * @fn int32_t PROFILER_instance_init(const char *file, const char *function, const int32_t line)
 * @brief
 * @param [in] const char *file
 * @param [in] const char *function
 * @param [in] const int32_t line
 * @return
 * */
int32_t PROFILER_instance_init(const char *file, const char *function, const int32_t line){
        int32_t PROFILER_instance_index = PROFILER_instance_last_index++;
        PROFILER_files_names[PROFILER_instance_index] = file;
        PROFILER_procedures_names[PROFILER_instance_index] = function;
        PROFILER_lines_numbers[PROFILER_instance_index] = line;
        return PROFILER_instance_index;
}

/*!
 * @fn uint8_t PROFILER_instance_is_not_initialized(int32_t PROFILER_instance_index)
 * @brief
 * @param [in] int32_t PROFILER_instance_index
 * @return
 * */
uint8_t PROFILER_instance_is_not_initialized(int32_t PROFILER_instance_index){
	return PROFILER_INSTANCE_NOT_INITIALIZED == PROFILER_instance_index;
}


#endif //PROFILING_TOOLS_H
