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
