#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "Chapter3.h"
using namespace std;

int BinarySearchTank::BinarySearch(int n, int s[], int x)
{
	int low = 0, high = n - 1;						//lowָ������ĵ�һ��Ԫ�أ�highָ����������һ��Ԫ��
	while (low <= high)
	{
		int middle = (low + high) / 2;			//middleΪ���ҷ�Χ���м�ֵ
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
	//low ָ������ĵ�һ��Ԫ�أ�highָ����������һ��Ԫ��
	if (low > high)										//�ݹ�����
		return -1;
	int middle = (low + high) / 2;				//�����м�ֵ
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
	cout << "�������б��е�Ԫ�ظ���n��";
	cin >> n;
	cout << "���������������е�Ԫ�أ�";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	cout << "����֮�������Ϊ��";
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "������Ҫ��ѯ��Ԫ�أ�";
	cin >> x;
	ans = BinarySearch(n, s, x);
	if (ans == -1)
		cout << "��������û��Ҫ��ѯ��Ԫ��" << endl;
	else
		cout << "�ҵ���ѯ��Ԫ���ڵ�" << ans + 1 << "λ" << endl;

	cout << endl;
}

void BinarySearchTank::BinarySearchTestRec()
{
	int n;
	int x;
	int ans;
	cout << "�������б��е�Ԫ�ظ���n��";
	cin >> n;
	cout << "���������������е�Ԫ�أ�";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	cout << "����֮�������Ϊ��";
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "������Ҫ��ѯ��Ԫ�أ�";
	cin >> x;
	ans = RecursionBS(s, x, 0, n-1);
	if (ans == -1)
		cout << "��������û��Ҫ��ѯ��Ԫ��" << endl;
	else
		cout << "�ҵ���ѯ��Ԫ���ڵ�" << ans + 1 << "λ" << endl;

	cout << endl;
}

//3.2 �ϲ�����
void MergeSortTank::Merge(int A[], int low, int mid, int high)
{
	int *B = new int[high - low + 1];									//���븨������
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
	while (i <= mid) B[k++] = A[i++];								//��ʣ�µ�Ԫ�ط��븨������
	while (j <= high) B[k++] = A[j++];
	for (i = low, k = 0; i <= high; i++)
		A[i] = B[k++];
	delete []B;
}

void MergeSortTank::MergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;				//ȡ�е�
		MergeSort(A, low, mid);					//����A[low,mid]֮���Ԫ�غϲ�����
		MergeSort(A, mid + 1, high);			//����A[mid + 1, high]֮���Ԫ�غϲ�����
		Merge(A, low, mid, high);					//�ϲ�
	}
}

void MergeSortTank::MergeSortTest()
{
	cout << "������Ԫ�ظ���n��" << endl;
	cin >> n;
	int xArr[] = { 42, 15, 20,6, 8, 38, 50, 12 };
	cout << "���������������е�Ԫ�أ�" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	MergeSort(A, 0, n - 1);
	cout << "�����������" << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

int QuickSortTank::partition(int r[], int low, int high)
{
	int i = low, j = high, privot = r[low];					//��׼Ԫ��
	while (i < j)
	{
		while (i < j && r[j] > privot)								//�����ƶ�
			j--;
		if (i < j)
			swap(r[i++], r[j]);											//r[i],r[j]������i����һλ
		while (i < j && r[i] < privot)								//�����ƶ�
			i++;
		if (i < j)
			swap(r[i], r[j--]);											//r[i],r[j]������j����һλ
	}
	return i;																//����������ɻ���֮��Ļ�׼Ԫ������λ��
}

int QuickSortTank::partition2(int r[], int low, int high)
{
	int i = low, j = high, privot = r[low];
	while (i < j)
	{
		while (i < j && r[j] > privot)								//����ɨ��
			j--;
		while (i < j && r[i] < privot)								//����ɨ��
			i++;
		if (i < j)
			swap(r[i++], r[j--]);
	}
	if (r[i] > privot)
	{
		swap(r[i - 1], r[low]);
		return i - 1;
	}
	swap(r[i], r[low]);
	return i;
}

void QuickSortTank::QuickSort(int R[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = partition2(R, low, high);								//��׼λ��
		QuickSort(R, low, mid - 1);									//��������������
		QuickSort(R, mid + 1, high);									//�Ҳ������������
	}
}

void QuickSortTank::QuickSortTest()
{
	int i;
	cout << "������Ҫ��������ݸ���n��" << endl;
	cin >> n;
	cout << "������Ҫ��������ݣ�" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> R[i];
	}
	QuickSort(R, 0, n-1);
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < n; i++)
		cout << R[i] << " " ;
	cout << endl;
}
