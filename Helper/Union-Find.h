#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// ���鼯
// ʾ��
class unionFind1 {
public:
	void Test()
	{
		int n = 0;
		cout << "���������ڵ���: ";
		cin >> n;
		if (n <= 0)
		{
			cout << "error" << endl;
			return;
		}

		int *arr = new int[n];

		init(arr, n);
		int m = 0;
		cout << "���������ݹ�ϵ��Ŀ: ";
		cin >> m;
		cout << "���������ݹ�ϵ " << endl;
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

		cout << "��������Ҷ���:" << endl;
		for (int i = 0; i < 5; i++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			int tmpa = find(arr, a);
			int tmpb = find(arr, b);
			if (tmpa == tmpb)
				cout << "����" << endl;
			else
				cout << "��������" << endl;
		}

		delete[] arr;
	}
private:
	// ��ʼ��
	void init(int *arr, const int n)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}
	}
	
	// �ݹ鲢��
	int find(int * arr, int n)
	{
		if (n != arr[n])
		{
			arr[n] = find(arr, arr[n]);
		}
		return arr[n];
	}

	// �ϲ�
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


