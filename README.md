<!--
 * @Autor: SourDumplings
 * @Date: 2019-09-21 22:54:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 我自己实现的各种数据结构和算法的模板，用以学习数据结构和算法及编程语言
 -->
# DSA

----- 版权所有 酸饺子 -----

我自己实现的各种数据结构和算法的模板，用C++语言实现了一些，打算再用Java实现一遍

- 采用C++（C++11）语言实现，统一在CZ命名空间中

在编译器gcc version 7.2.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)下测试通过

## 通用算法（模板）：
1. ### 字典序比较操作符
2. ### 区间内最大值与最小值的查找算法
3. ### 交换算法
4. ### 查找算法
	- #### 顺序查找
	- #### 二分查找
	- #### 斐波那契查找
5. ### 排序算法
	- #### 选择排序
	- #### 插入排序
	- #### 冒泡排序
	- #### 归并排序
	- #### 快速排序
	- #### 堆排序
	- #### 希尔排序
6. ### 匹配算法
	- #### 括号匹配
	- #### 串匹配算法
		- ##### 蛮力算法
		- ##### KMP算法
7. ### 找中位数算法
	- #### 两个有序序列合并后的中位数
8. ### 逆置算法
9. ### Remove算法
## 容器（模板）类：（许多容器定义了print_info方法，故元素必须支持<<运算符）
1. ### 向量
2. ### 位域
3. ### 列表
	- #### 双向列表
4. ### 堆栈
5. ### 队列
	- #### 单向队列
6. ### 树
	- #### 二叉树
		- ##### 普通二叉树
		- ##### 二叉搜索树
			- ###### AVL树
			- ###### 伸展树
			- ###### 红黑树
	- #### B树
	- #### B+树
7. ### 算术表达式
8. ### 字符串
9. ### 并查集
10. ### 词典
	- #### 哈希表
	- #### 键值对Pair
11. ### 堆
	- #### 普通堆
	- #### 左式堆
12. ### 素数表
13. ### 集合
14. ### 图
	- #### 邻接表
	- #### 邻接矩阵
	- #### 图算法
		- ##### 深度优先搜索dfs
		- ##### 广度优先搜索bfs
		- ##### 最短路径
			- ###### Dijkstra（包括堆优化与普通）
			- ###### Floyd
		- ##### 连通集个数
		- ##### 回路判断
			- ###### 欧拉回路
			- ###### 半欧拉回路
		- ##### 最小生成树
			- ###### Prim
			- ###### Kruskal
		- ##### 拓扑排序
15. ### 树状数组
## 特殊工具：
1. ### 智能指针
	- #### Shared_ptr
	- #### Weak_ptr
2. ### 迭代器
	- #### 单向迭代器
	- #### 双向迭代器
	- #### 随机访问迭代器
## 参考资料：
[1] 《数据结构》3rd-邓俊辉

[2] http://en.cppreference.com/w/

[3] 《C++ Primer》5th-Stanley B. Lippman, Josée Lajoie, Barbara E. Moo

[4] 《Effective C++》3rd-Scott Meyers

[5] 《数据结构》2nd-陈越

[6] 《2019年数据结构考研复习指导》-王道论坛组编

[7] 《Database System Concepts》6th-Abraham Silberschatz, Henry F. Korth, S. Sudarshan

