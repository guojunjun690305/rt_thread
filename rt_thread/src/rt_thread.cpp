/********************************************************************************
* @author: jun Guo
* @email: 1379477285@qq.com
* @organization: LX
* @date:2023.04.15
* @version: 1.0
* @description:
********************************************************************************/

#include "rt_thread.h"

rt_thread::rt_thread()
{
 
}
rt_thread::~rt_thread()
{
    
}
// 获取调度策略的函数
int rt_thread::get_thread_policy(pthread_attr_t *attr)
{
  int policy;
  int rs = pthread_attr_getschedpolicy(attr, &policy);
  switch (policy)
  {
	case SCHED_FIFO:
	  printf("policy= SCHED_FIFO\n");
	  break;
	case SCHED_RR:
	  printf("policy= SCHED_RR");
	  break;
	case SCHED_OTHER:
	  printf("policy=SCHED_OTHER\n");
	  break; 
	default:
	  printf("policy=UNKNOWN\n");
	  break;
  }
  return policy;
}


int main() {
  rt_thread m_rt_thread;
  thread_1 m_thread_1;
  thread_2 m_thread_2;
  pthread_t t1;
  pthread_t t2;
  pthread_attr_t attr1;
  pthread_attr_t attr2;
  struct sched_param param1;
  struct sched_param param2;

  //1、初始化
  pthread_attr_init(&attr1);
  pthread_attr_init(&attr2);

  //2、自己决定调度策略
  pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setinheritsched(&attr2, PTHREAD_EXPLICIT_SCHED);

  //3、设置调度策略
  pthread_attr_setschedpolicy(&attr1, SCHED_FIFO);
  pthread_attr_setschedpolicy(&attr2, SCHED_FIFO);
  // 获取调度策略
  m_rt_thread.get_thread_policy(&attr1);
  m_rt_thread.get_thread_policy(&attr2);

  //4、设置优先级
  param1.sched_priority = 12;// 线程1设置优先级为10
  param2.sched_priority = 12;// 线程2设置优先级为12
  pthread_attr_setschedparam(&attr1, &param1);
  pthread_attr_setschedparam(&attr2, &param2);

  //5、创建线程
  pthread_create(&t1, &attr1, m_thread_1.thread1, NULL);
  //sleep(1);
  pthread_create(&t2, &attr2, m_thread_2.thread2, NULL);

  while (1)
  {
   	extern long long a;
   	extern long long b;
   
	printf("a=%d, b=%d \n ",a,b); 
	sleep(1);
  }

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}
