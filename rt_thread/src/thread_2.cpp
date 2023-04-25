/********************************************************************************
* @author: jun Guo
* @email: 1379477285@qq.com
* @organization: LX
* @date:2023.04.15
* @version: 1.0
* @description:
********************************************************************************/

#include "thread_2.h"
long long b=0;
thread_2::thread_2()
{

}
thread_2::~thread_2()
{
    
}

// 线程函数2
void* thread_2::thread2(void *param)
{
  thread_2* pthis=(thread_2* ) param;
  pthis->attach_cpu(14);
  long long i;
  for (i = 0; i < 10000000000; i++)
  {
	b++;
	//sleep(1);
  }
  
}


// 将线程绑定到某个cpu核上
int thread_2::attach_cpu(int cpu_index)
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

