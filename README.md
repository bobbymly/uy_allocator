# uy_allocator
> 引言
>  * 使用空间配置器，而不是直接将所有的内存需求都直接向系统申请一块内存的一个重要原因就是要尽量避免内存碎片。
>  * 将所有的需求都通过向系统申请系统，不仅会带来内存碎片的问题，配置时的额外负担也是不可忽略的。
>  * 第二级配置器可以通过一次申请一大块内存，通过内存池和 free_list 来管理和负责小内存区块分配，这样在系统中的内存就不会被频繁的分割并产生过多内存碎片以及配置时的额外负担。
## uy_allocator_1.h  第一级空间配置器
>直接使用 malloc 从系统中申请内存空间

## uy_allocator_2.h  第二级空间配置器
>避免太多的小额区块造成内存的碎片

> * 空间管理策略是
> * 当申请的空间够大 （大于 128 bytes）时，直接交由第一级空间配置器处理
> * 当申请的空间较小 （小于 128 bytes）时，以 free_list 和内存池管理

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
