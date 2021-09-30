#include "stdafx.h"
#include <iostream>
#include "dkgPrint.h"
using std::cout;
using std::endl;

void dkgPrint(int * arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
