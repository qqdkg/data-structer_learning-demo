#include "stdafx.h"
#include "limits.h"
#include "XiaoMiCar.h"
#include "dkgPrint.h"
#include "dkgSort.h"

int * getCorss(const int * arr1, int n1, const int * arr2, int n2, int &n_out)
{
	// �����쳣����

	// ������ʱ����
	int *tmp = new int[n1 + n2];

	// �����ʱ����
	for (int i = 0; i < n1; i++)
		tmp[i] = arr1[i];
	for (int i = n1; i < n1 + n2; i++)
		tmp[i] = arr2[i - n1];
	
	// ����
	/*BobSort(tmp, n1 + n2);*/
	mergeSort(tmp, 0, n1 + n2-1);

	// ���
	int count = 0;
	for (int i = 1; i < n1 + n2; i++)
	{
		if (tmp[i - 1] == tmp[i])
			tmp[i - 1] = INT_MIN;
		else
			count++;
	}

	// �����ϼ�����
	int* outArr = new int[count];
	count = 0;
	for (int i = 0; i < n1 + n2; i++)
	{
		if (tmp[i] != INT_MIN)
		{
			outArr[count++] = tmp[i];
		}
	}

	// ɾ����ʱ����
	delete[] tmp;
	
	// ���
	n_out = count;
	return outArr;
}

void getCorssTest()
{
	int a[] = { 10,29,37,81,02,8,74,10,2,9,34,710,9,2 };
	int b[] = { 1,92,7,39,1274,912,74,0,1,59,81,93,8,4,7,91,2,120 };

	int *arr;
	int n = 0;

	arr = getCorss(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]),n);
	dkgPrint(arr, n);
}


