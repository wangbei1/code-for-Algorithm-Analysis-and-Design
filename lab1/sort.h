#pragma once
#include<vector>

/*
实验目的：熟悉主要排序算法，对排序算法的时间复杂度及其影响因素有直观认识。

实验题目：排序算法时间复杂度比较

(1) 随机生成一个包括n个整数的数组（元素取值范围是1~1000），利用插入排序、归并排序、快速排序、堆排序、基数排序、桶排序等算法对数组进行非降序排序，记录不同算法的运行时间。

(2) 改变数组规模 n = 5万、10万、20万、30万、50万，记录不同规模下各个算法的排序时间。

(3) 对固定规模 （n = 10万）的数组进行随机扰乱，对扰乱后的数组进行排序并记录各个算法的排序时间。本实验要求重复5次，观察输入数据分布和运行时间的关系。

(4) 据实验结果完成一份关于排序算法时间复杂度分析的实验报告。

完成时间：11月1日

考核方式：现场检查提问 + 报告检查。
*/


//插入排序
void Insertion_Sort(int* n,int size);

//归并排序(Merge Sort)//
void Merge_Sort(int *n, int size);

//快速排序 (Quick Sort)
void Quick_Sort(int *n, int left, int right);

//堆排序 (Heap Sort)
void Heap_Sort(int* n, int size);

//基数排序(Radix Sort)
void Radix_Sort(int* n, int size);

//桶排序(Bucket Sort)
void bucketsort(std::vector<int>& arr, int range);

//产生动态数组
int* generate_n(int n);

//随机扰乱
int* disturbance(int *n);

std::vector<int> generateRandomVector(int size);


//文件写入操作
int is_sorted(int *n, int size );

int is_sorted_vector(std::vector<int> n, int size);

