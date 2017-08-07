# Introduction to Algorithm

- 说明lgn是以2为底的对数

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
- 菲波那切数列[源码](https://github.com/xuyicpp/Classical_Algorithms/blob/master/Introduction_to_Algorithms/Fibonacci.cpp)
- 结：朴素递归算法用时太多，实用价值不大，自底向上算法效率为线性，较高，平时用较多，递归平方算法效率为对数级，且编程可实现，实用价值很大。并且经过测试，当n值变很大后，递归平方算法效率明显高于自底向上算法效率。[BLOG](http://www.cnblogs.com/zhoutaotao/p/3964997.html)


