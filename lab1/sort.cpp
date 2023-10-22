#include "sort.h"
#include <stdio.h>
//#include<string.h>
#include <iterator> // 包含头文件iterator
#include <iostream>
#include <stdlib.h>
#include<algorithm>
#include<vector>
#include<random>
/*
实验目的：熟悉主要排序算法，对排序算法的时间复杂度及其影响因素有直观认识。

实验题目：排序算法时间复杂度比较

(1) 随机生成一个包括n个整数的数组（元素取值范围是1~1000），利用
	插入排序、++
	归并排序、++
	快速排序、++
	堆排序、++
	基数排序、++
	桶排序++
	等算法
	对数组进行非降序排序，记录不同算法的运行时间。

(2) 改变数组规模 n = 5万、10万、20万、30万、50万，记录不同规模下各个算法的排序时间。

(3) 对固定规模 （n = 10万）的数组进行随机扰乱，对扰乱后的数组进行排序并记录各个算法的排序时间。
	本实验要求重复5次，观察输入数据分布和运行时间的关系。

(4) 据实验结果完成一份关于排序算法时间复杂度分析的实验报告。

完成时间：11月1日

考核方式：现场检查提问 + 报告检查。
*/


//交换两个元素
void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//选择排序
void Insertion_Sort(int n[], int size)
{
	int i = 1;
	for (; i < size; i++)
	{
		int key = n[i];
		int j = i - 1;
		while (j >= 0 && n[j] > key)
		{
			n[j + 1] = n[j];
			j--;
		}
		n[j+1] = key;
	}
}






/*
以下是归并排序的内容
*/
//定义merge函数,最主要过程
void merge(int arr[], int temparr[], int left, int mid, int right)
{
	//标记左半区第一个未排序的元素
	int l_pos = left;
	//标记左半区第一个未排序的元素
	int r_pos = mid + 1;
	//标记临时数组的下标
	int pos = left;
	//合并
	while (l_pos <= mid && r_pos <= right)
	{
		if (arr[l_pos] < arr[r_pos])
		{
			temparr[pos++] = arr[l_pos++];
		}
		else 
		{
			temparr[pos++] = arr[r_pos++];
		}
	}
	//合并左半区域剩余的元素
	while (l_pos <= mid)
	{
		temparr[pos++] = arr[l_pos++];
	}

	//合并右半区域剩余的元素
	while (r_pos <= right)
	{
		temparr[pos++] = arr[r_pos++];
	}

	//把临时数组合并后，复制到原来的数组，这里是arr
	while (left <= right)
	{
		arr[left] = temparr[left];
		left++;
	}
}


//定义msort函数
void msort(int arr[], int temparr[], int left, int right)
{
	//如果只有一个元素，不需要划分
	if (left < right)
	{
		//找中间点
		int mid = (left + right) / 2;

		//递归分两个半区
		//划分左半区域
		msort(arr, temparr, left, mid);
		//划分右半区域
		msort(arr, temparr, mid + 1, right);

		//合并操作
		merge(arr, temparr,left,mid,right);

	}
}

//归并排序
void Merge_Sort(int arr[], int size)
{
	//首先申请一个动态的内存
	int* temparr = (int*)malloc(size * sizeof(int));
	if (temparr)
	{
		//主要功能是拆解和合并
		msort(arr, temparr, 0, size - 1);
		free(temparr);
	}
}

/*
以下是快速排序的内容
	快速排序使用的是分治的思想
	选择一个基准，把大于这个基准的放到后面，小于这个基准的放到前面
	那么这个基准就放到了正确的位置上了
	然后递归调用函数，排序前半部分和后半部分
*/

void Quick_Sort(int* n, int left, int right) 
{
    if (left < right) 
	{
        int i = left, j = right;
        int base = n[right]; // 使用数组最右边的元素作为基准值
        while (i != j)
		{
            while (i < j && n[i] <= base)
			{
                i++;
            }
            while (i < j && n[j] >= base) 
			{
                j--;
            }
            if (i <= j) 
			{
                Swap(&n[i], &n[j]);             
            }
        }
        Swap(&n[i], &n[right]); // 将基准值放入正确的位置
        Quick_Sort(n, left, i - 1); // 递归处理左半部分
        Quick_Sort(n, i + 1, right); // 递归处理右半部分
    }
}

/*
以下是堆排序的算法
	什么是堆呢？
	左孩子和右孩子比根节点都小的二叉树，一般用数组存储，注意一下根节点和子节点的关系
	根节点：i，左孩子：2*i+1
*/

//维护堆的性质
//i是需要维护的元素的下标
void heapify(int arr[], int size, int i)
{
	//标记根节点以及孩子节点的下标
	int bigger = i;
	int lson = 2 * i + 1;
	int rson = 2 * i + 2;
	if (lson < size && arr[bigger] < arr[lson])
	{
		bigger = lson;
	}
	if (rson < size && arr[bigger] < arr[rson])
	{
		bigger = rson;
	}
	if (bigger != i)
	{
		Swap(&arr[bigger], &arr[i]);
		heapify(arr, size, bigger);
	}
}



//堆排序入口
void Heap_Sort(int n[], int size)
{
	
	//第一步是建堆
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(n, size, i);
	}

	for (i = size - 1; i > 0; i--)
	{
		//第二步，将堆顶元素与末尾元素交换
		Swap(&n[i], &n[0]);
		heapify(n, i, 0);
	}
	

}


//以下是基数排序的算法
/*
一般用于数字比较大的情况下
先按照个位数排序
从小到大收集
再按照十位数再按照百位数
以此类推
*/

void Radix_Sort(int* n, int size)
{
	int i, max=n[0];
	for (i = 1; i < size; i++)
	{
		if (n[i] > max)
		{
			max = n[i];
		}
	}

	int* space = (int*)malloc(sizeof(int) * size);

	int base = 1;
	while (max / base > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < size; i++)
		{
			bucket[n[i] / base % 10]++;
		}
		
		for (i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (i = size - 1; i >= 0; i--)
		{
			space[bucket[n[i] / base % 10] - 1] = n[i];
			bucket[n[i] / base % 10]--;
		}
		for (i = 0; i < size; i++)
		{
			Swap(&n[i], &space[i]);
		}
		base *= 10;
	}
}


//以下是桶排序的内容，实际上最主要的就是分桶的过程



void bucketsort(std::vector<int>& arr, int range)
{

	// 创建n/100个空桶
	int h = range / 1000;
	std::vector<std::vector<int>> buckets(h);

	// 将元素分配到对应的桶中
	for (int i = 0; i < arr.size(); i++)
	{
		int bucketIndex = (arr[i] - 1) / 100;
		buckets[bucketIndex].push_back(arr[i]);
	}

	// 对每个桶内的元素进行排序
	for (int i = 0; i < h; i++)
	{
		std::sort(buckets[i].begin(), buckets[i].end());
	}

	// 将排序后的元素放回原数组
	int index = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < buckets[i].size(); j++)
		{
			arr[index++] = buckets[i][j];
		}
	}
	
}

int* generate_n(int n)
{
	// 动态分配内存创建数组
	int* arr = (int*)malloc(n * sizeof(int));

	// 检查内存分配是否成功
	if (arr == NULL) {
		printf("内存分配失败\n");
		return NULL;
	}

	// 使用随机数为数组赋值
	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 1000 + 1; // 生成1到1000范围内的随机数
	}
	return arr;
}

std::vector<int> generateRandomVector(int size) {
	std::vector<int> randomVector(size);
	srand(time(0)); // 使用当前时间作为随机数种子
	int minValue = 0;
	int maxValue = 1000;

	for (int i = 0; i < size; ++i) {
		int randomNumber = rand() % (maxValue - minValue + 1) + minValue; // 生成minValue到maxValue范围内的随机数
		randomVector.push_back(randomNumber); // 将随机数添加到vector中
	}

	return randomVector;
}


int is_sorted(int arr[], int size) {
	for (int i = 1; i < size; ++i) {
		if (arr[i] < arr[i - 1]) {
			return 0; // 返回0表示数组未按顺序排列
		}
	}
	return 1; // 返回1表示数组按顺序排列
}

int is_sorted_vector(std::vector<int> n, int size) 
{
	for (int i = 1; i < size; ++i) {
		if (n[i - 1] > n[i]) 
		{
			return 0; 
		}
	}
	return 1; 
}


void shuffle_vector(std::vector<int>& vec)
{
	std::srand(std::time(0)); // Seed for the random number generator
	int size = vec.size();
	for (int i = size - 1; i > 0; --i)
	{
		int j = std::rand() % (i + 1); // Generate a random index between 0 and i (inclusive)
		Swap(&vec[i], &vec[j]); // Swap elements at i and j
	}
}

void shuffle_array(int* arr, int size)
{
	std::srand(std::time(0)); // Seed for the random number generator
	for (int i = size - 1; i > 0; --i)
	{
		int j = std::rand() % (i + 1); // Generate a random index between 0 and i (inclusive)
		Swap(&arr[i], &arr[j]); // Swap elements at i and j
	}
}
