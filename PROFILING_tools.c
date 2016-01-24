#include "PROFILING_tools.h"

int32_t PROFILER_instance_last_index = 0;
const char* PROFILER_files_names[PROFILER_TOTAL_PROFILERS] = {0};
const char* PROFILER_procedures_names[PROFILER_TOTAL_PROFILERS] = {0};
int32_t PROFILER_lines_numbers[PROFILER_TOTAL_PROFILERS] = {0};
PROFILER_timestruct PROFILER_total_times[PROFILER_TOTAL_PROFILERS] = {0};
PROFILER_timestruct PROFILER_global_begin = {0},PROFILER_global_end = {0};
float PROFILER_total_average = 0;	

static float PROFILER_timestamp_diff_to_float(PROFILER_timestruct PROFILER_timestruct_diff){
	return (PROFILER_timestruct_diff).tv_sec + (PROFILER_timestruct_diff).tv_nsec*1.e-9;
}		
		
static void PROFILER_calculate_all_profiles_average(){
	PROFILER_total_average = 
		PROFILER_timestamp_begin_end_to_float(PROFILER_global_begin,PROFILER_global_end);
}			
			
static float PROFILER_get_current_profile_average(int32_t PROFILER_instance_index){
	return 100*PROFILER_timestamp_diff_to_float(PROFILER_total_times[PROFILER_instance_index])/PROFILER_total_average;
}				

static void PROFILER_log_instance(uint16_t PROFILER_instance_index){
		fprintf(stderr,"file %s, line %d: ",
			PROFILER_files_names[PROFILER_instance_index],
			PROFILER_lines_numbers[PROFILER_instance_index]);
		fprintf(stderr,"%s 	average: %f%%\n",
			PROFILER_procedures_names[PROFILER_instance_index],
			PROFILER_get_current_profile_average(PROFILER_instance_index));
}		

float PROFILER_timestamp_begin_end_to_float(PROFILER_timestruct timestamp_begin, PROFILER_timestruct timestamp_end){
	return timestamp_end.tv_sec - timestamp_begin.tv_sec+
		(timestamp_end.tv_nsec - timestamp_begin.tv_nsec)*1.e-9;
}	
	
void PROFILER_log(){
	PROFILER_calculate_all_profiles_average();
	for(int32_t PROFILER_instance_index = 0; PROFILER_instance_index<PROFILER_instance_last_index; ++PROFILER_instance_index){
		PROFILER_log_instance(PROFILER_instance_index);
	}
}	
