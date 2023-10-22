#include "sort.h"
#include <stdio.h>
#include<string.h>
// main.cpp
#include <iostream>
#include<vector>
using namespace std;

#include <chrono>

using namespace std::chrono;

int main()
{

	while (true)
	{
		int n = 0;
		cout << "输入数组的大小 ";
		cin >> n;



		
		

		//插入排序部分
		int* randomArray1 = generate_n(n);		
		std::cout << "Array sorted using Insertion Sort: ";
		auto start = high_resolution_clock::now();
		Insertion_Sort(randomArray1, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		if(is_sorted(randomArray1,n))
		{
			std::cout << "the randomrray is already sorted ";
			cout << "running time: " << duration.count() << " ms" << endl;
		}
		else
		{
			std::cout << "the randomrray is not already sorted " << endl;
		}
		free(randomArray1);


		//归并排序部分
		int* randomArray2 = generate_n(n);
		
		std::cout << "Array sorted using Merge Sort: ";
		auto start1 = high_resolution_clock::now();
		Merge_Sort(randomArray2, n);
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<milliseconds>(stop1 - start1);
		if (is_sorted(randomArray2, n))
		{
			std::cout << "the randomrray is already sorted ";
			cout << "running time: " << duration1.count() << " ms" << endl;
		}
		else
		{
			std::cout << "the randomrray is not already sorted " << endl;
		}
		free(randomArray2);

		//快速排序部分
		int* randomArray3 = generate_n(n);
		std::cout << "Array sorted using Quick Sort: ";
		auto start2 = high_resolution_clock::now();
		Quick_Sort(randomArray3, 0, n - 1);
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<milliseconds>(stop2 - start2);
		if (is_sorted(randomArray3, n))
		{
			std::cout << "the randomrray is already sorted ";
			cout << "running time: " << duration2.count() << " ms" << endl;
		}
		else
		{
			std::cout << "the randomrray is not already sorted " << endl;
		}
		free(randomArray3);

		//堆排序部分
		int* randomArray4 = generate_n(n);
		std::cout << "Array sorted using heap Sort: ";
		auto start3 = high_resolution_clock::now();
		Heap_Sort(randomArray4, n);
		auto stop3 = high_resolution_clock::now();
		auto duration3 = duration_cast<milliseconds>(stop3 - start3);
		if (is_sorted(randomArray4, n))
		{
			std::cout << "the randomrray is already sorted ";
			cout << "running time: " << duration3.count() << " ms" << endl;
		}
		else
		{
			std::cout << "the randomrray is not already sorted " << endl;
		}
		free(randomArray4);

		//基数排序部分
		int* randomArray5 = generate_n(n);
		std::cout << "Array sorted using Radix Sort: ";
		auto start4 = high_resolution_clock::now();
		Radix_Sort(randomArray5, n);
		auto stop4 = high_resolution_clock::now();
		auto duration4 = duration_cast<milliseconds>(stop4 - start4);
		if (is_sorted(randomArray5, n))
		{
			std::cout << "the randomrray is already sorted ";
			cout << "running time: " << duration4.count() << " ms" << endl;
		}
		else
		{
			std::cout << "the randomrray is not already sorted " << endl;
		}
		free(randomArray5);

		//桶排序部分
		vector<int> randomVector = generateRandomVector(n);
		std::cout << "Array sorted using bucket Sort: ";
		auto start5 = high_resolution_clock::now();
		bucketsort(randomVector, n);
		auto stop5 = high_resolution_clock::now();
		auto duration5 = duration_cast<milliseconds>(stop5 - start5);
		if (is_sorted_vector(randomVector, n))
		{
			std::cout << "the randomrray is already sorted ";
			cout << "running time: " << duration5.count() << " ms" << endl;
		}
		else
		{
			std::cout << "the randomrray is not already sorted " << endl;
		}
		
		
	}
	

}



