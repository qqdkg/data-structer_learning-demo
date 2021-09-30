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

	// ����hash��
	int *p_hash = new int[length];
	for (int i = 0; i < length; ++i)
	{
		p_hash[i] = 0;
	}

	// ����Ѱ���ظ�����
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
	cout << "���룺" << endl;
	PrintArr(arr, sizeof(arr) / sizeof(int));

	int out = 0;
	findUniNum_hash(arr, sizeof(arr) / sizeof(int), out);
	cout << "�ҵ����ظ����֣�" << out << endl;

}
