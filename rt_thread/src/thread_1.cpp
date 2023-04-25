/********************************************************************************
* @author: jun Guo
* @email: 1379477285@qq.com
* @organization: LX
* @date:2023.04.15
* @version: 1.0
* @description:
********************************************************************************/

#include "thread_1.h"
long long a=0;

thread_1::thread_1()
{
     
}
thread_1::~thread_1()
{
    
}


// 线程函数1
void* thread_1::thread1(void *param)
{
  thread_1* pthis=(thread_1* ) param;
  pthis->attach_cpu(15);
  long long i;
  for (i = 0; i < 10000000000; i++)
  {

	a++;
	//sleep(1);
  }
}

// 将线程绑定到某个cpu核上
int thread_1::attach_cpu(int cpu_index)
{
  int cpu_num = sysconf(_SC_NPROCESSORS_CONF);
  if (cpu_index < 0 || cpu_index >= cpu_num)
  {
	printf("cpu index ERROR!\n");
	return -1;
  }

  cpu_set_t mask;
  CPU_ZERO(&mask);
  CPU_SET(cpu_index, &mask);

  if (pthread_setaffinity_np(pthread_self(), sizeof(mask), &mask) < 0)
  {
	printf("set affinity np ERROR!\n");
	return -1;
  }

  return 0;
}


