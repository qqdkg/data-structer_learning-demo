#pragma once
#include<iostream>
using std::cout;
using std::endl;

// 用于方便的打印数组
void PrintArr(int *p_arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << p_arr[i] << " ";
	}
	cout << endl;
}

