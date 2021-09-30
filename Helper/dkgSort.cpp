#include "stdafx.h"
#include <iostream>
#include "dkgSort.h"
using std::cout;
using std::cin;
using std::endl;

void merge(int * arr, int low, int mid, int high)
{
	// 这个merge的实现需要使用一个临时数组
	// 这里要求low ~ mid 和 mid+1 ~ high这两段数据内部是有序的
	int *tmpArr = new int[high - low + 1];
	int i = low;													// 指向第一段的数据头
	int j = mid + 1;												// 指向第二段的数据头
	int k = 0;														// 指向临时数组的数据头

	// 变量两段数据，比较大小并放入临时数组，知道有一段遍历完毕
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
			tmpArr[k++] = arr[i++];
		else
			tmpArr[k++] = arr[j++];
	}

	// 将没有遍历完的那一段剩余数据放入临时数组
	while (i <= mid)
	{
		tmpArr[k++] = arr[i++];
	}
	while (j <= high)
	{
		tmpArr[k++] = arr[j++];
	}

	// 将临时数组中的数据拷贝回原数组，并且清除临时数组
	for (i = low, k = 0; i <= high;i++, k++)
	{
		arr[i] = tmpArr[k];
	}


	delete[] tmpArr;
}

void mergeSort(int * arr, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		
		// 递归调用前一部分
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);

		// 合并
		merge(arr, low, mid, high);
	}
}

void mergeSortTest()
{
	int arr[] = { 1,5,3,6,7,4,2,8,0,9 };

	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}


// 冒泡排序
void BobSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
