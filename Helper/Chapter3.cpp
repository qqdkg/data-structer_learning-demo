#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "Chapter3.h"
using namespace std;

int BinarySearchTank::BinarySearch(int n, int s[], int x)
{
	int low = 0, high = n - 1;						//low指向数组的第一个元素，high指向数组的最后一个元素
	while (low <= high)
	{
		int middle = (low + high) / 2;			//middle为查找范围的中间值
		if (x == s[middle])
			return middle;
		else if (x < s[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;
}

int BinarySearchTank::RecursionBS(int s[], int x, int low, int high)
{
	//low 指向数组的第一个元素，high指向数组的最后一个元素
	if (low > high)										//递归条件
		return -1;
	int middle = (low + high) / 2;				//计算中间值
	if (x == s[middle])
		return middle;
	else if (x < s[middle])
		return RecursionBS(s, x, low, middle - 1);
	else
		return RecursionBS(s, x, middle + 1, high);
}

void BinarySearchTank::BinarySearchTest()
{
	int n;
	int x;
	int ans;
	cout << "请输入列表中的元素个数n：";
	cin >> n;
	cout << "请依次输入数列中的元素：";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	cout << "排序之后的数组为：";
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "请输入要查询的元素：";
	cin >> x;
	ans = BinarySearch(n, s, x);
	if (ans == -1)
		cout << "该数列中没有要查询到元素" << endl;
	else
		cout << "找到查询的元素在第" << ans + 1 << "位" << endl;

	cout << endl;
}

void BinarySearchTank::BinarySearchTestRec()
{
	int n;
	int x;
	int ans;
	cout << "请输入列表中的元素个数n：";
	cin >> n;
	cout << "请依次输入数列中的元素：";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	cout << "排序之后的数组为：";
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "请输入要查询的元素：";
	cin >> x;
	ans = RecursionBS(s, x, 0, n-1);
	if (ans == -1)
		cout << "该数列中没有要查询到元素" << endl;
	else
		cout << "找到查询的元素在第" << ans + 1 << "位" << endl;

	cout << endl;
}

//3.2 合并排序
void MergeSortTank::Merge(int A[], int low, int mid, int high)
{
	int *B = new int[high - low + 1];									//申请辅助数组
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high)
	{
		if (A[i] <= A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	while (i <= mid) B[k++] = A[i++];								//将剩下的元素放入辅助数组
	while (j <= high) B[k++] = A[j++];
	for (i = low, k = 0; i <= high; i++)
		A[i] = B[k++];
	delete []B;
}

void MergeSortTank::MergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;				//取中点
		MergeSort(A, low, mid);					//对于A[low,mid]之间的元素合并排序
		MergeSort(A, mid + 1, high);			//对于A[mid + 1, high]之间的元素合并排序
		Merge(A, low, mid, high);					//合并
	}
}

void MergeSortTank::MergeSortTest()
{
	cout << "请输入元素个数n：" << endl;
	cin >> n;
	int xArr[] = { 42, 15, 20,6, 8, 38, 50, 12 };
	cout << "请依次输入数组中的元素：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	MergeSort(A, 0, n - 1);
	cout << "输出排序结果：" << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

int QuickSortTank::partition(int r[], int low, int high)
{
	int i = low, j = high, privot = r[low];					//基准元素
	while (i < j)
	{
		while (i < j && r[j] > privot)								//向左移动
			j--;
		if (i < j)
			swap(r[i++], r[j]);											//r[i],r[j]交换，i右移一位
		while (i < j && r[i] < privot)								//向右移动
			i++;
		if (i < j)
			swap(r[i], r[j--]);											//r[i],r[j]交换，j左移一位
	}
	return i;																//返回最终完成划分之后的基准元素所在位置
}

void QuickSortTank::QuickSort(int R[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = partition(R, low, high);								//基准位置
		QuickSort(R, low, mid - 1);									//左侧区间快速排序
		QuickSort(R, mid + 1, high);									//右侧区间快速排序
	}
}

void QuickSortTank::QuickSortTest()
{
	int i;
	cout << "请输入要排序的数据个数n：" << endl;
	cin >> n;
	cout << "请输入要排序的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> R[i];
	}
	QuickSort(R, 0, n-1);
	cout << "排序后的数据为：" << endl;
	for (int i = 0; i < n; i++)
		cout << R[i] << " " ;
	cout << endl;
}
