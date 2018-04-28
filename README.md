# uy_alloctor

## uy_alloctor_1.h  第一级空间配置器
>直接使用 malloc 从系统中申请内存空间

## uy_alloctor_2.h  第二级空间配置器
>避免太多的小额区块造成内存的碎片

> * 空间管理策略是
> * 当申请的空间够大 （大于 128 bytes）时，直接交由第一级空间配置器处理
> * 当申请的空间较小 （小于 128 bytes）时，以内存池管理

> * 第二级空间配置器 使用一个 free_list 管理不同大小的内存块（所有内存块的管理与申请均提升为 8 bytes 的整数倍）
> * 当所申请的内存块大小在 free_list 中有对应大小的剩余内存块可以使用时，直接从 free_list 中分配
> * 否则，从内存池中一次分配 20 个申请大小的内存块，一个用于使用，19 个添加到 free_list 中备用

> * 当内存池中内存不足 20 个 申请的内存块大小时
> * 若足够一个则给与一个放回使用
> * 剩余的小区块内存直接添加到 free_list 中（充分利用）
> * 然后调用第一级空间适配器 向内存池中补充内存


## process diagram



![](https://raw.githubusercontent.com/bobbymly/uy_alloctor/master/pic/process_diagram.png )

![](https://raw.githubusercontent.com/bobbymly/uy_alloctor/master/pic/free_list.png )
