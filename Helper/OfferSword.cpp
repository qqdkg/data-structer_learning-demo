#include "stdafx.h"
#include "OfferSword.h"
#include "dkgPrintArr.h"

bool Prob_3_UniNum::findUniNum_hash(int numbers[], int length, int &duplication)
{
	// ASSERTATION
	if (numbers == nullptr || length <= 0)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > (length - 1))
		{
			return false;
		}
	}

	// 建立hash表
	int *p_hash = new int[length];
	for (int i = 0; i < length; ++i)
	{
		p_hash[i] = 0;
	}

	// 遍历寻找重复数字
	for (int i = 0; i < length; i++)
	{
		if (p_hash[numbers[i]] == 1)
		{
			duplication = numbers[i];
			return true;
		}
		else
		{
			p_hash[numbers[i]] = 1;
		}
	}


	delete[] p_hash;
	return false;
}

void Prob_3_UniNum::testUniNum()
{
	int arr[] = { 2,3,1,0,2,5,3 };
	cout << "输入：" << endl;
	PrintArr(arr, sizeof(arr) / sizeof(int));

	int out = 0;
	findUniNum_hash(arr, sizeof(arr) / sizeof(int), out);
	cout << "找到的重复数字：" << out << endl;

}
