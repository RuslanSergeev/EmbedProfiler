#include "PROFILING_tools.h"

/**
  **************************************************************************************************************************
  * @file    PROFILING_tools.c
  * @author  Sergeev Ruslan.
  * 	OOO SPUTNIX,
  * 	MIPT High-Precision Attitude Control Systems Laboratory
  * @version V1.0.0
  * @date    23-January-2016
  * @brief   Файл PROFILING_tools.c является частью библиотеки EmbedPROFILER - библиотеки профилировщика времени вызовов.
  *
  * Профилировщик времени вызовов - средство анализа исходного кода программ, представляющее
  * программистам и инженерам анализировать время, затраченное на выполнение того или
  * иного участка кода в процентном соотношении (относительно общего времени работы профилировщика).
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
 * @brief Индекс последнего инициализированного профилировщика.
 *
 * Инициализирован значением PROFILER_INSTANCE_NOT_INITIALIZED,
 * поскольку в начальный момент ни один профилировщик ещё не инициализирован.
*/
int32_t PROFILER_instance_last_index = PROFILER_INSTANCE_NOT_INITIALIZED;

/*!
 * @var const char* PROFILER_files_names[PROFILER_TOTAL_PROFILERS]
 * @brief Массив имён файлов, в которых вызываются профилировщики.
 *
 * Ячейка с определённым индексом заполняется, когда профилировщик с таким
 * индексом вызывается впервые.
*/
const char* PROFILER_files_names[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @var const char* PROFILER_procedures_names[PROFILER_TOTAL_PROFILERS]
 * @brief Массив имён функций(процедур, методов), в которых вызывается профилировщик.
*/
const char* PROFILER_procedures_names[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @var uint32_t PROFILER_lines_numbers[PROFILER_TOTAL_PROFILERS]
 * @brief Массив номеров строк исходного кода, в которых вызывается профилировщик.
*/
uint32_t PROFILER_lines_numbers[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @var uint32_t PROFILER_times_called[PROFILER_TOTAL_PROFILERS]
 * @brief Массив чисел вызовов профилировщиков.
 *
 * Каждый раз, когда управление достигает сегмента кода, профилироваемого
 * определённым профилировщиком, число вызовов этого профилировщика
 * в массиве инкрементируется.
 * @return uint32_t - Число вызовов локального профилировщика.
*/
uint32_t PROFILER_times_called[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @var PROFILER_timestruct PROFILER_total_times[PROFILER_TOTAL_PROFILERS]
 * @brief Массив времён затраченных на работы профилировщиков.
*/
PROFILER_timestruct PROFILER_total_times[PROFILER_TOTAL_PROFILERS] = {0};

/*!
 * @fn float PROFILER_timestamp_diff_to_float(int32_t PROFILER_instance_index)
 * @brief Рассчитывает общее число секунд затраченное интересующим профилировщиком
 * за всё время его работы (включая наносекунды).
 * @param [in] int32_t PROFILER_instance_index
 * @return float - Число секунд, которое работал интересующий профилировщик.
*/
static float PROFILER_timestamp_diff_to_float(int32_t PROFILER_instance_index){
    return (PROFILER_total_times[PROFILER_instance_index]).tv_sec +
            (PROFILER_total_times[PROFILER_instance_index]).tv_nsec*1.e-9;
}		

/*!
 * @fn float PROFILER_calculate_all_profiles_average()
 * @brief Считает время, затраченное всей системой профилировани времени вызовов.
 *
 * Если главный профилировщик запустился в момент начала работы системы, а
 * закончил работать в момент завершения работы системы, то это время представляет
 * из себя время работы системы в целом. Нагруженность конкретного профиля исходного
 * кода представляет собой время работы этого профиля относительно времени работы
 * главного профилировщика.
 * @return float - Общее время работы всей системы профилирования.
*/
static float PROFILER_calculate_all_profiles_average(){
    return PROFILER_timestamp_diff_to_float(PROFILER_GLOBAL_PROFILE_INDEX);
}			

/*!
 * @fn float PROFILER_get_current_profile_average(int32_t PROFILER_instance_index)
 * @brief
 * @param [in] int32_t PROFILER_instance_index
 * \n Индекс локального профилировщика.
 * @return float - Загруженность локального профилировщика.
*/
static float PROFILER_get_current_profile_average(int32_t PROFILER_instance_index){
    static float PROFILER_total_average = PROFILER_calculate_all_profiles_average();
    return 100*PROFILER_timestamp_diff_to_float(PROFILER_instance_index)/PROFILER_total_average;
}				

/*!
 * @fn void PROFILER_log_instance(uint16_t PROFILER_instance_index)
 * @brief
 * @param [in] uint16_t PROFILER_instance_index
*/
static void PROFILER_log_instance(uint16_t PROFILER_instance_index){
        fprintf(stderr,"[file %s,  line %d,  fun: %s] times called: %u,  average: %f%%\n",
			PROFILER_files_names[PROFILER_instance_index],
            PROFILER_lines_numbers[PROFILER_instance_index],
			PROFILER_procedures_names[PROFILER_instance_index],
            PROFILER_times_called[PROFILER_instance_index],
			PROFILER_get_current_profile_average(PROFILER_instance_index));
}		

/*!
 * @fn void PROFILER_log()
 * @brief Вывести отчёт о работе профилировщика.
 *
 * Сообщает затраченное на работу каждого профилировщика время, имена файлов, номера строк, названия функций где был создан данный профилировщик.
 * Также сообщает число вызовов данного профилировщика.
 * */
void PROFILER_log(){
	PROFILER_calculate_all_profiles_average();
    for(int32_t PROFILER_instance_index = PROFILER_LOCAL_PROFILES_BEGIN; PROFILER_instance_index<=PROFILER_instance_last_index; ++PROFILER_instance_index){
		PROFILER_log_instance(PROFILER_instance_index);
	}
}	
