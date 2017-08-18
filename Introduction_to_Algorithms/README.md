# Introduction to Algorithm

- 说明lgn是以2为底的对数
- 编译环境：g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609
- g++ -std=c++11 XX.cpp -o XX


##  第一课 算法分析
- 插入排序 [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Insertion_Sort.cpp)
- 归并排序 [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Merge_Sort.cpp)

## 第二课 渐近符号、递归及解法

- f(n)的值总位于c1g(n)与c2g(n)之间或等于它们，那么记f(n)=Θ(g(n))。
- f(n)的值总小于或等于cg(n),那么记f(n)=O(g(n))。
- f(n)的值总大于或等于cg(n),那么记f(n)=Ω(g(n))。
- 用主方法求解递归式，
如下图：

![](./images/Main_Theorem.png)

另外这一篇BLOG详细了介绍了这种方法的用途：[BLOG](http://www.jianshu.com/p/4d0b005782d9)

## 第三课 分冶法（Divide and Conquer）
- 二分法 [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Binary_Search.cpp)
- 菲波那切数列 [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Fibonacci.cpp)
- 结：朴素递归算法用时太多，实用价值不大，自底向上算法效率为线性，较高，平时用较多，递归平方算法效率为对数级，且编程可实现，实用价值很大。并且经过测试，当n值变很大后，递归平方算法效率明显高于自底向上算法效率。[BLOG](http://www.cnblogs.com/zhoutaotao/p/3964997.html)

## 第四课 快排及随机化算法
- 快速排序及随机快速排序 [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Quick_Sort.cpp)
- Hoare的代码对快排有重复的情况运行的更好。
- 随机化快速排序，其运行时间不依赖于输入序列的顺序Θ(nlgn),一般来说比归并快3倍。
- 这篇博客对此进行了详细的介绍我就摘录了一些 [BLOG](http://www.cnblogs.com/zhoutaotao/p/3970099.html)
自我小结：对随机产生的数组进行排序，1）可以发现插入排序没有优势、特别是数组比较大时耗时太多；2）快速排序、随机化快速排序、归并排序性能不错，然而两种快排比归并排序性能好点；3）当数据量变大时，可以看出性能排序为快速排序、随机化快速排序、归并排序、插入排序；4）由于这里的数组是由随机数产生的，没有显示出随机化快速排序的优势，但是当数组为已排序情况下随机化快排将比快排性能好。

![](./images/sort_time_compare.png)

- 附：堆排序：[源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Heapsort.cpp) [算法详解](https://jingyan.baidu.com/article/5225f26b057d5de6fa0908f3.html)(注：这里的堆顶的下标是从1开始的)


## 第五课 线性时间排序

- 在最坏情况下，任何比较排序算法都需要做Ω(nlgn)次比较。故堆排序和归并排序都是渐进最优的比较排序算法。
- 计数排序 [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Counting_Sort.cpp)

它的优势在于在对一定范围内的整数排序时，它的复杂度为Ο(n+k)（其中k是整数的范围），快于任何比较排序算法。当然这是一种牺牲空间换取时间的做法，而且当O(k)>O(n*log(n))的时候其效率反而不如基于比较的排序（基于比较的排序的时间复杂度在理论上的下限是O(n*log(n)), 如归并排序，堆排序）

- 基数排序 [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Radix_Sort.cpp)

源码中实现排序的代码是和计数排序一样的。
基数排序（radix sort）属于“分配式排序”（distribution sort），又称“桶子法”（bucket sort）或bin sort，顾名思义，它是透过键值的部份资讯，将要排序的元素分配至某些“桶”中，藉以达到排序的作用，基数排序法是属于稳定性的排序，其时间复杂度为O (nlog(r)m)，其中r为所采取的基数，而m为堆数，在某些时候，基数排序法的效率高于其它的稳定性排序法。

## 第六课 顺序统计、中值

- 随机选择算法(一般选择这个) [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Randomized_Select.cpp) :

运行时间的复杂度期望是Θ(n),最坏的情况复杂度为Θ(n2)。

- 最坏线性选择算法 [源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Worse_Linear_Select.cpp) :

相比于上面的随机选择，我们有另一种类似的算法，它在最坏情况下也能达到O(n)。它也是基于数组的划分操作，而且利用特殊的手段保证每次划分两边的子数组都比较平衡；与上面算法不同之处是：本算法不是随机选择主元，而是采取一种特殊的方法选择“中位数”，这样能使子数组比较平衡，避免了上述的最坏情况（Ө(n^2)）。选出主元后，后面的处理和上述算法一致。

参考博客 [BLOG](http://www.cnblogs.com/zhoutaotao/p/4047082.html)





