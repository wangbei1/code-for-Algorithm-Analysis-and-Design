#include "sort.h"
#include <stdio.h>
//#include<string.h>
#include <iterator> // ����ͷ�ļ�iterator
#include <iostream>
#include <stdlib.h>
#include<algorithm>
#include<vector>
#include<random>
/*
ʵ��Ŀ�ģ���Ϥ��Ҫ�����㷨���������㷨��ʱ�临�Ӷȼ���Ӱ��������ֱ����ʶ��

ʵ����Ŀ�������㷨ʱ�临�ӶȱȽ�

(1) �������һ������n�����������飨Ԫ��ȡֵ��Χ��1~1000��������
	��������++
	�鲢����++
	��������++
	������++
	��������++
	Ͱ����++
	���㷨
	��������зǽ������򣬼�¼��ͬ�㷨������ʱ�䡣

(2) �ı������ģ n = 5��10��20��30��50�򣬼�¼��ͬ��ģ�¸����㷨������ʱ�䡣

(3) �Թ̶���ģ ��n = 10�򣩵��������������ң������Һ������������򲢼�¼�����㷨������ʱ�䡣
	��ʵ��Ҫ���ظ�5�Σ��۲��������ݷֲ�������ʱ��Ĺ�ϵ��

(4) ��ʵ�������һ�ݹ��������㷨ʱ�临�Ӷȷ�����ʵ�鱨�档

���ʱ�䣺11��1��

���˷�ʽ���ֳ�������� + �����顣
*/


//��������Ԫ��
void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//ѡ������
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
�����ǹ鲢���������
*/
//����merge����,����Ҫ����
void merge(int arr[], int temparr[], int left, int mid, int right)
{
	//����������һ��δ�����Ԫ��
	int l_pos = left;
	//����������һ��δ�����Ԫ��
	int r_pos = mid + 1;
	//�����ʱ������±�
	int pos = left;
	//�ϲ�
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
	//�ϲ��������ʣ���Ԫ��
	while (l_pos <= mid)
	{
		temparr[pos++] = arr[l_pos++];
	}

	//�ϲ��Ұ�����ʣ���Ԫ��
	while (r_pos <= right)
	{
		temparr[pos++] = arr[r_pos++];
	}

	//����ʱ����ϲ��󣬸��Ƶ�ԭ�������飬������arr
	while (left <= right)
	{
		arr[left] = temparr[left];
		left++;
	}
}


//����msort����
void msort(int arr[], int temparr[], int left, int right)
{
	//���ֻ��һ��Ԫ�أ�����Ҫ����
	if (left < right)
	{
		//���м��
		int mid = (left + right) / 2;

		//�ݹ����������
		//�����������
		msort(arr, temparr, left, mid);
		//�����Ұ�����
		msort(arr, temparr, mid + 1, right);

		//�ϲ�����
		merge(arr, temparr,left,mid,right);

	}
}

//�鲢����
void Merge_Sort(int arr[], int size)
{
	//��������һ����̬���ڴ�
	int* temparr = (int*)malloc(size * sizeof(int));
	if (temparr)
	{
		//��Ҫ�����ǲ��ͺϲ�
		msort(arr, temparr, 0, size - 1);
		free(temparr);
	}
}

/*
�����ǿ������������
	��������ʹ�õ��Ƿ��ε�˼��
	ѡ��һ����׼���Ѵ��������׼�ķŵ����棬С�������׼�ķŵ�ǰ��
	��ô�����׼�ͷŵ�����ȷ��λ������
	Ȼ��ݹ���ú���������ǰ�벿�ֺͺ�벿��
*/

void Quick_Sort(int* n, int left, int right) 
{
    if (left < right) 
	{
        int i = left, j = right;
        int base = n[right]; // ʹ���������ұߵ�Ԫ����Ϊ��׼ֵ
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
        Swap(&n[i], &n[right]); // ����׼ֵ������ȷ��λ��
        Quick_Sort(n, left, i - 1); // �ݹ鴦����벿��
        Quick_Sort(n, i + 1, right); // �ݹ鴦���Ұ벿��
    }
}

/*
�����Ƕ�������㷨
	ʲô�Ƕ��أ�
	���Ӻ��Һ��ӱȸ��ڵ㶼С�Ķ�������һ��������洢��ע��һ�¸��ڵ���ӽڵ�Ĺ�ϵ
	���ڵ㣺i�����ӣ�2*i+1
*/

//ά���ѵ�����
//i����Ҫά����Ԫ�ص��±�
void heapify(int arr[], int size, int i)
{
	//��Ǹ��ڵ��Լ����ӽڵ���±�
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



//���������
void Heap_Sort(int n[], int size)
{
	
	//��һ���ǽ���
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(n, size, i);
	}

	for (i = size - 1; i > 0; i--)
	{
		//�ڶ��������Ѷ�Ԫ����ĩβԪ�ؽ���
		Swap(&n[i], &n[0]);
		heapify(n, i, 0);
	}
	

}


//�����ǻ���������㷨
/*
һ���������ֱȽϴ�������
�Ȱ��ո�λ������
��С�����ռ�
�ٰ���ʮλ���ٰ��հ�λ��
�Դ�����
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


//������Ͱ��������ݣ�ʵ��������Ҫ�ľ��Ƿ�Ͱ�Ĺ���



void bucketsort(std::vector<int>& arr, int range)
{

	// ����n/100����Ͱ
	int h = range / 1000;
	std::vector<std::vector<int>> buckets(h);

	// ��Ԫ�ط��䵽��Ӧ��Ͱ��
	for (int i = 0; i < arr.size(); i++)
	{
		int bucketIndex = (arr[i] - 1) / 100;
		buckets[bucketIndex].push_back(arr[i]);
	}

	// ��ÿ��Ͱ�ڵ�Ԫ�ؽ�������
	for (int i = 0; i < h; i++)
	{
		std::sort(buckets[i].begin(), buckets[i].end());
	}

	// ��������Ԫ�طŻ�ԭ����
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
	// ��̬�����ڴ洴������
	int* arr = (int*)malloc(n * sizeof(int));

	// ����ڴ�����Ƿ�ɹ�
	if (arr == NULL) {
		printf("�ڴ����ʧ��\n");
		return NULL;
	}

	// ʹ�������Ϊ���鸳ֵ
	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 1000 + 1; // ����1��1000��Χ�ڵ������
	}
	return arr;
}

std::vector<int> generateRandomVector(int size) {
	std::vector<int> randomVector(size);
	srand(time(0)); // ʹ�õ�ǰʱ����Ϊ���������
	int minValue = 0;
	int maxValue = 1000;

	for (int i = 0; i < size; ++i) {
		int randomNumber = rand() % (maxValue - minValue + 1) + minValue; // ����minValue��maxValue��Χ�ڵ������
		randomVector.push_back(randomNumber); // ���������ӵ�vector��
	}

	return randomVector;
}


int is_sorted(int arr[], int size) {
	for (int i = 1; i < size; ++i) {
		if (arr[i] < arr[i - 1]) {
			return 0; // ����0��ʾ����δ��˳������
		}
	}
	return 1; // ����1��ʾ���鰴˳������
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
