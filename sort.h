#pragma once
#include<vector>

/*
ʵ��Ŀ�ģ���Ϥ��Ҫ�����㷨���������㷨��ʱ�临�Ӷȼ���Ӱ��������ֱ����ʶ��

ʵ����Ŀ�������㷨ʱ�临�ӶȱȽ�

(1) �������һ������n�����������飨Ԫ��ȡֵ��Χ��1~1000�������ò������򡢹鲢���򡢿������򡢶����򡢻�������Ͱ������㷨��������зǽ������򣬼�¼��ͬ�㷨������ʱ�䡣

(2) �ı������ģ n = 5��10��20��30��50�򣬼�¼��ͬ��ģ�¸����㷨������ʱ�䡣

(3) �Թ̶���ģ ��n = 10�򣩵��������������ң������Һ������������򲢼�¼�����㷨������ʱ�䡣��ʵ��Ҫ���ظ�5�Σ��۲��������ݷֲ�������ʱ��Ĺ�ϵ��

(4) ��ʵ�������һ�ݹ��������㷨ʱ�临�Ӷȷ�����ʵ�鱨�档

���ʱ�䣺11��1��

���˷�ʽ���ֳ�������� + �����顣
*/


//��������
void Insertion_Sort(int* n,int size);

//�鲢����(Merge Sort)//
void Merge_Sort(int *n, int size);

//�������� (Quick Sort)
void Quick_Sort(int *n, int left, int right);

//������ (Heap Sort)
void Heap_Sort(int* n, int size);

//��������(Radix Sort)
void Radix_Sort(int* n, int size);

//Ͱ����(Bucket Sort)
void bucketsort(std::vector<int>& arr, int range);

//������̬����
int* generate_n(int n);

//�������
int* disturbance(int *n);

std::vector<int> generateRandomVector(int size);


//�ļ�д�����
int is_sorted(int *n, int size );

int is_sorted_vector(std::vector<int> n, int size);

