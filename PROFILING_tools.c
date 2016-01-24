#include "PROFILING_tools.h"

int32_t PROFILER_instance_last_index = 0;
const char* PROFILER_files_names[PROFILER_TOTAL_PROFILERS] = {0};
const char* PROFILER_procedures_names[PROFILER_TOTAL_PROFILERS] = {0};
int32_t PROFILER_lines_numbers[PROFILER_TOTAL_PROFILERS] = {0};
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
        fprintf(stderr,"file %s, line %d: ",
			PROFILER_files_names[PROFILER_instance_index],
			PROFILER_lines_numbers[PROFILER_instance_index]);
		fprintf(stderr,"%s 	average: %f%%\n",
			PROFILER_procedures_names[PROFILER_instance_index],
			PROFILER_get_current_profile_average(PROFILER_instance_index));
}		

	
void PROFILER_log(){
	PROFILER_calculate_all_profiles_average();
    for(int32_t PROFILER_instance_index = PROFILER_LOCAL_PROFILES_BEGIN; PROFILER_instance_index<PROFILER_instance_last_index; ++PROFILER_instance_index){
		PROFILER_log_instance(PROFILER_instance_index);
	}
}	
