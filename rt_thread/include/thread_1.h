/********************************************************************************
* @author: jun Guo
* @email: 1379477285@qq.com
* @organization: LX
* @date:2023.04.15
* @version: 1.0
* @description:
********************************************************************************/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

using namespace std;
extern long long a;
class thread_1
{
  public:
    thread_1();
    ~thread_1();

    // 将线程绑定到某个cpu核上
    int attach_cpu(int cpu_index);
    // 线程函数1
    static void *thread1(void *param);
    

  private:
  //


    
};




