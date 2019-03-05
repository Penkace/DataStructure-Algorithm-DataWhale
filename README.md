# Leetcode-Datastructure

## Individual description
&emsp;&emsp;自己在校大三，有学业任务以及项目，所以Task1没有一次性全部完成，之后每天都会完成学习任务，巩固基础知识。
因为自己之前上过刘宇波老师的算法课，所以对TASK中的算法题目有一定的思路，其编程的思想都有所了解。

<br>
&emsp;&emsp;leetcode每道题的解题思路在每个cpp文档的开头**Solution**部分，主要思想都有说明;
<br>
&emsp;&emsp;写数据结构的时候采用比较简洁的方法，把更多的精力放在**数据结构及其不同操作实现的思想**上。<br>
-2019-2-27 完成单链表的编写，实现一定的功能，并且完成所有的Leetcode练习;
<br>
          &emsp;&emsp;&emsp;&emsp;&emsp;1. 3Sum.cpp<br>
          &emsp;&emsp;&emsp;&emsp;&emsp;2. Happy Number.cpp<br>
          &emsp;&emsp;&emsp;&emsp;&emsp;3. Linklist.cpp<br>
          &emsp;&emsp;&emsp;&emsp;&emsp;4. Majority Element.cpp<br>
          &emsp;&emsp;&emsp;&emsp;&emsp;5. Mergoe k sorted Lists.cpp<br>
          &emsp;&emsp;&emsp;&emsp;&emsp;6. Two Sum.cpp<br>
-2019-2-28 完成双向链表和循环链表的编写，双向链表实现了创建、删除某个值的结点、插入结点等操作以及查找中间结点;<br>
          &emsp;&emsp;&emsp;&emsp;&emsp;1. DoubleL.cpp<br>
          &emsp;&emsp;&emsp;&emsp;&emsp;2. CirList.cpp & CirList.h<br>
          
-2019-3-1  今天上下午满课，并且项目今天有大量数据分析，所以只写了一个顺序栈和模拟网页前进后退的练习<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;1. Sqstack.cpp<br>
  &emsp;&emsp;&emsp;&emsp;&emsp;2. 模拟网页前进后退<br>

-2019-3-2 完成了链式栈及链式栈的插入删除判空等操作，并且用自己写的链式栈完成了模拟网页前进后退的练习;完成一个链式队列以及使用数组实现一个循环队列<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;1. Linkstack.hpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;2. linkstacktest.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;3. LinkQueue.hpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;4. LinkQueuetest.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;5. CirQueue.hpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;6. CirQueuetest.cpp<br>
 
-2019-3-3 完成Leetcode的练习<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;1. Valid Parentheses.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;2. Longest Valid Parentheses.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;3. Evaluate Reverse Polish Notatio.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;4. Design Circular Deque.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;5. Sliding Window Maximum.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;6. Climbing Stairs.cpp<br>

-2019-3-4 今天帮一个朋友写知网的爬虫，没有写任务. 小爬虫开源的, 有需要的朋友可以拿去用, 主要抓取知网某个主题下的文章标题和日期<br>

-2019-3-5 完成常见的排序算法，在完成任务给的算法的同时(大三手撕排序还是挺快的...)，还复习了其他几种排序算法，Leetcode的题目没有做，之后补上<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;1. BinarySearch.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;2. FuzzyBinarySearch.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;3. 冒泡排序.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;4. 分治排序.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;5. 找第K大的数.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;6. 插入排序.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;7. 翻转插入排序.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;8. 选择排序.cpp<br>
 &emsp;&emsp;&emsp;&emsp;&emsp;9. 选择排序从小到大排序.cpp<br>
 
 
## Special Note
1. leetcode141.First Missing Positive 题解我写在了CSDN，[leetcode141题解](https://blog.csdn.net/qq_42034665/article/details/87968009);
2. 单链表linklist写在**Linklist.cpp**文件中，主要实现list的**创建、删除、打印**，并且在单链表中实现里**链表翻转和合并k个链表**，可以在自己的编译器上输出结果；
3. 双向链表写在了**Doublelist.cpp**里面，实现了双向链表的创建、打印、删除某个值的结点、删除链表，插入结点等操作，实现的时候采用了一些思路如创建虚拟头结点可以减少代码的编写量，此外，实现了**查找中间结点**。<br>
4. 循环链表看了严薇敏老师的数据结构C语言版，然后参考[数据结构（3）单循环链表 c++ 模板实现](https://blog.csdn.net/natsu1211/article/details/9412397)学习实践了答主的写法。<br>
5. 今天看了一个博主的C++编写方式，自己参考学习了，不再像之前写linklist那样写数据结构，而是用**template模板类**来实现，在头文件写好各操作（其实上课的时候也是用这种方式，但是我当时眼界狭隘就没有参照那张写法，没有深入体会template的作用）。<br>
6. Climbing Stairs这类递归的题目如果不能剪枝容易出TLE，所以能推DP就推DP，自己在不断的摸索中。<br>


