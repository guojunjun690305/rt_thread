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
#include "thread_1.h"
#include "thread_2.h"
using namespace std;

 
class rt_thread
{
  public:
    rt_thread();
    ~rt_thread();
    // 获取调度策略的函数
    static int get_thread_policy(pthread_attr_t *attr);

  private:
  //
 

    
};



