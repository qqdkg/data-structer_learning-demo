#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// 并查集
// 示例
class unionFind1 {
public:
	void Test()
	{
		int n = 0;
		cout << "请输入待查节点数: ";
		cin >> n;
		if (n <= 0)
		{
			cout << "error" << endl;
			return;
		}

		int *arr = new int[n];

		init(arr, n);
		int m = 0;
		cout << "请输入亲戚关系数目: ";
		cin >> m;
		cout << "请输入亲戚关系 " << endl;
		for (int i = 0; i < m; i++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			if (a < 0 || a >= n || b < 0 || b > n)
			{
				cout << "error" << endl;
				return;
			}
			unionfy(arr, a, b);
		}

		cout << "请输入查找对象:" << endl;
		for (int i = 0; i < 5; i++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			int tmpa = find(arr, a);
			int tmpb = find(arr, b);
			if (tmpa == tmpb)
				cout << "亲戚" << endl;
			else
				cout << "不是亲戚" << endl;
		}

		delete[] arr;
	}
private:
	// 初始化
	void init(int *arr, const int n)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}
	}
	
	// 递归并查
	int find(int * arr, int n)
	{
		if (n != arr[n])
		{
			arr[n] = find(arr, arr[n]);
		}
		return arr[n];
	}

	// 合并
	void unionfy(int *arr, int x, int y)
	{
		int a = find(arr, x);
		int b = find(arr, y);

		if (a != b)
		{
			arr[b] = a;
		}
	}
};


