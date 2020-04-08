#ifndef SQLIST_H
#define SQLIST_H
#include<iostream>
using namespace std;

#define Maxsize 100

typedef int ElemType;

typedef struct sqList {
	ElemType *elem;
	int length;
public:
	bool InitList();					//À≥–Ú±Ì≥ı ºªØ
	bool CreatList();
	bool CreatList(int *arr ,int n);
	bool GetElem(int index,int &rlt);
	int LocateElem(int target);
	bool ListInsert(int index,int inserter);
	bool ListDelete(int index,int &rlt);

	friend ostream& operator<<(ostream &out,sqList sq) ;
} sqList;

void test(sqList sq, int * arr, int n);
void MergeSqList(sqList La, sqList Lb, sqList &Lc);



#endif // !SQLIST_H
