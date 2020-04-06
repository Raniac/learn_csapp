# LEARN_CSAPP

## Program Optimization

- [优化程序性能的策略汇总](https://www.cnblogs.com/snsart/p/10726795.html)

## The Memory Hierarchy

- [计算机基础之主存和磁盘(十一)](https://blog.csdn.net/qq_31403321/article/details/80601215)
- 不同层级存储器速度差距很大，而程序对内存的访问具有局部性(时间/空间)，缓存机制利用局部性来弥补存储器层级差距。

### Cache Memories

- [深入理解处理器高速缓存的工作机制](https://www.cnblogs.com/snsart/p/10700599.html)

## Linking

- [文件的链接过程](https://www.cnblogs.com/snsart/p/10761642.html)
- [ELF文件格式](https://www.cnblogs.com/gatsby123/p/9750187.html)
- [Linux下静态库.a与.so库文件的生成与使用](https://blog.csdn.net/lisayh/article/details/79726249)
- [Linux和Windows平台 动态库.so和.dll文件的生成](https://www.cnblogs.com/xhslovecx/p/10613854.html)

## Shell Programming

- [Shell 教程](https://www.runoob.com/linux/linux-shell.html)

## Dynamic Memory Allocation

- [CSAPP Dynamic Storage Allocator 动态内存分配器](https://blog.csdn.net/weixin_43821874/article/details/86481632)
- [Dynamic Memory Allocate(动态内存分配)](https://blog.csdn.net/c602273091/article/details/53576494)
- [堆栈和内存分配](https://blog.csdn.net/dai_wen/article/details/78407709)
- [c++ new 与malloc有什么区别](https://www.cnblogs.com/ywliao/articles/8116622.html)
- [C++中对象new出来和直接声明的区别](https://blog.csdn.net/qq_43269048/article/details/90139907)
- [内存溢出(Memory Overflow)和内存泄露(Memory Leak)的区别](https://blog.csdn.net/u013519020/article/details/52347173)

## Network Programming

- [netstat和telnet命令在Windows7中的用法](https://www.cnblogs.com/Joetao/articles/2153934.html)
- [10个你需要了解的Linux 网络和监控命令](https://linux.cn/thread-12491-1-1.html)
- [初识CGI](https://www.cnblogs.com/xidongyu/p/9029102.html)
- [web架构的演化 - 从CGI到WSGI](https://www.jianshu.com/p/487cc605868f)
- [访问一个网页的全过程](https://blog.csdn.net/u012862311/article/details/78753232)
  - 首先通过域名找到IP，如果缓存里没有就要请求DNS服务器；得到IP后开始与目的主机进行三次握手来建立TCP连接；连接建立后进行HTTP访问，传输并获取网页内容；传输完后与目的主机四次挥手来断开TCP连接。

## Concurrent Programming

### Synchronization

- [并发编程导论](https://segmentfault.com/a/1190000018949353?utm_source=tag-newest)
- [并发编程模式](https://blog.csdn.net/yjclsx/article/details/80923737)
- [I/O多路复用机制（Epoll）](https://blog.csdn.net/cbjcry/article/details/84926952)
- [为什么基于事件驱动的服务器能实现高并发？](https://www.zhihu.com/question/64727674/answer/225113965)
- [并发服务器之多线程和多路复用(select)的区别](https://blog.csdn.net/linuxwln/article/details/81941048)
- [信号量(Semaphores)](https://www.jianshu.com/p/6ba83710ab62)
- [多线程设计模式：第三篇 - 生产者-消费者模式和读写锁模式](https://www.jianshu.com/p/9d37b08e0348)
