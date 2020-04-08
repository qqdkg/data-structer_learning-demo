#include "stdafx.h"
#include "sqList.h"

bool sqList::InitList()
{
	elem = new int[Maxsize];
	if (!elem) return false;
	length = 0;
	return true;
}

bool sqList::CreatList()
{
	int x=0, i=0;
	elem = new int[Maxsize];
	if (!elem) return false;
	length = 0;
	while (x != -1) {
		if (length >= Maxsize) {
			cout << "顺序列表已满！"<<endl;
			return false;
		}
		cin >> x;
		elem[i++] = x;
		length++;
	}
	return true;
}

bool sqList::CreatList(int * arr,int n)
{
	elem = new int[Maxsize];
	if (!elem) return false;
	length = 0;

	for (int i = 1; i <= n; i++) {
		if (length >= Maxsize) {
			cout << "顺序列表已满！" << endl;
			return false;
		}

		elem[i - 1] = arr[i - 1];
		length++;
	}
	return true;
}

bool sqList::GetElem(int index, int & rlt)
{
	if (index<1 || index>length){
		return false;
	}
	rlt = elem[index-1];

	return true;
}

int sqList::LocateElem(int target)
{
	for (int i = 0; i < length; i++) {
		if (target == elem[i])
			return i + 1;
	}
	return -1;
}

bool sqList::ListInsert(int index, int inserter)
{
	if (index<1 || index>length)
		return false;
	if (length >= Maxsize)
		return false;
	for (int i = length - 1; i > index - 1; i--) {
		elem[i+1] = elem[i];
	}
	elem[index - 1] = inserter;
	length++;
	return true;
}

bool sqList::ListDelete(int index, int & rlt)
{
	if (index<1 || index>length)
		return false;
	rlt = elem[index - 1];
	for (int i = index; i < length; i++)
		elem[i - 1] = elem[i];
	length--;
	return true;
}

void test(sqList sq,int * arr, int n)
{
	sq.CreatList(arr, n);
	cout << "sqList的元素有：" << sq << endl << endl;
	int rlt;
	sq.GetElem(5, rlt);
	cout << "获取其中的第5个元素为:" << rlt << endl << endl;
	rlt = sq.LocateElem(3);
	cout << "获取其中元素3的位置:" << rlt << endl << endl;
	sq.ListInsert(2, 777);
	cout << "在第二个位置插入:777" << endl << sq << endl << endl;
	sq.ListDelete(2, rlt);
	cout << "删除第2个元素，此元素为" << rlt << endl << " 变为:" << sq << endl;

	sqList La;
	int arr1[5] = { 1,2,3,4,5 };
	La.CreatList(arr1, 5);
	sqList Lb;
	int arr2[5] = { 6,7,8,9,10 };
	Lb.CreatList(arr2, 5);
	sqList Lc;
	MergeSqList(La, Lb, Lc);
	cout << "La：" << La << endl;
	cout << "Lb：" << Lb << endl;
	cout << "Lc=La+Lb：" << Lc << endl;
}

void MergeSqList(sqList La, sqList Lb, sqList & Lc)
{
	int counterA = 0;
	int counterB = 0;
	int counterC = 0;
	Lc.length = La.length + Lb.length;
	Lc.elem = new int[Lc.length];
	while (counterA<La.length&&counterB<Lb.length)
	{
		if (La.elem[counterA] <= Lb.elem[counterB])
			Lc.elem[counterC++] = La.elem[counterA++];
		else
			Lc.elem[counterC++] = Lb.elem[counterB++];
	}
	while(counterA<La.length)
		Lc.elem[counterC++] = La.elem[counterA++];
	while(counterB<Lb.length)
		Lc.elem[counterC++] = Lb.elem[counterB++];
}

ostream & operator<<(ostream & out, sqList sq)
{
	// TODO: 在此处插入 return 语句
	for (int i = 1; i <= sq.length; i++)
		out << sq.elem[i - 1] << " ";
	return out;
}
