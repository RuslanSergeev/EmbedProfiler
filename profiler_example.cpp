

#include <stdio.h>
#include <time.h>

#include "PROFILING_tools.h"

class My_class{
private:
protected:	
public:
	My_class():I(0){};
	volatile float I;
	inline void Increment_I(){
        PROFILER_local_start();
        for(uint16_t i = 0; i <100; ++i){
            printf("some message:)!\n");
            this->I += 1.F;
        }
        PROFILER_local_stop();
};

typedef struct My_struct{
	volatile float I;
}My_struct;

static inline __attribute__((always_inline))
void Increment_I(My_struct *struct_ptr){
    PROFILER_local_start();
	for(uint16_t i = 0; i <100; ++i){
		printf("some message:)!\n");
        struct_ptr->I += 1.F;
    }
    PROFILER_local_stop();
}

My_class obj;
My_struct str;

int main(int argc, char *argv[]){
	PROFILER_global_start();
	
    PROFILER_local_start();
    Increment_I(&str);
    PROFILER_local_stop();

    PROFILER_local_start();
    Increment_I(&str);
    PROFILER_local_stop();

    PROFILER_local_start();
    Increment_I(&str);
    PROFILER_local_stop();
	
	PROFILER_global_stop();
	PROFILER_log();
	return 0;
};

