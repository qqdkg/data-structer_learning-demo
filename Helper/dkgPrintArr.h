#pragma once
#include<iostream>
using std::cout;
using std::endl;

// ���ڷ���Ĵ�ӡ����
void PrintArr(int *p_arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << p_arr[i] << " ";
	}
	cout << endl;
}

