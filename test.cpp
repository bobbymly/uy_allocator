#include <iostream>
#include "uy_alloctor_2.h"
#include <string.h>
using namespace std;


int main()
{
    uy_alloctor_2<0> alloc;

    //测试正常使用
    char* test1 = (char*)alloc.allocate(64);
    strcpy(test1,"apply 64 bytes, the alloctor will add 19 blocks of 64 bytes to the free_list");
    cout<<test1<<endl;


    // //测试非正常使用，检验 free_list 是否如设计，程序崩溃则为正常
    // char* test2 = (char*)alloc.allocate(1);
    // strcpy(test2,"the blocks is continous in the memory, if we use the memory out of 19*64=1216 bytes,the program will crash");
    // cout<<test2<<endl;
    // for(int i=0;i<1500;++i)
    // {
    //     test2[i]=i;
    //     cout<<(int)test2[i];
    // }



    return 0;
}