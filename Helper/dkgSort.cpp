#include "stdafx.h"
#include <iostream>
#include "dkgSort.h"
using std::cout;
using std::cin;
using std::endl;

void merge(int * arr, int low, int mid, int high)
{
	// ���merge��ʵ����Ҫʹ��һ����ʱ����
	// ����Ҫ��low ~ mid �� mid+1 ~ high�����������ڲ��������
	int *tmpArr = new int[high - low + 1];
	int i = low;													// ָ���һ�ε�����ͷ
	int j = mid + 1;												// ָ��ڶ��ε�����ͷ
	int k = 0;														// ָ����ʱ���������ͷ

	// �����������ݣ��Ƚϴ�С��������ʱ���飬֪����һ�α������
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
			tmpArr[k++] = arr[i++];
		else
			tmpArr[k++] = arr[j++];
	}

	// ��û�б��������һ��ʣ�����ݷ�����ʱ����
	while (i <= mid)
	{
		tmpArr[k++] = arr[i++];
	}
	while (j <= high)
	{
		tmpArr[k++] = arr[j++];
	}

	// ����ʱ�����е����ݿ�����ԭ���飬���������ʱ����
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
		
		// �ݹ����ǰһ����
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);

		// �ϲ�
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


// ð������
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
