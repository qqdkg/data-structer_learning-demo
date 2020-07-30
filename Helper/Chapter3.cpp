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
