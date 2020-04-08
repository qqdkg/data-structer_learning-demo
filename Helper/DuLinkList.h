#ifndef DULINKLIST_H
#define DULINKLIST_H
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct DuLnode {
	ElemType Data;
	struct DuLnode *prior, *next;
}DuLnode,*DuLinkList;


bool initList_L(DuLinkList &L);
void CreatList_H(DuLinkList &L);
void CreatList_H(DuLinkList &L, int *arr, int n);
bool ListInsert_L(DuLinkList &L, int index, int target);
bool ListDelete_L(DuLinkList &L, int index);
void MergeDuLinkList(DuLinkList La,DuLinkList Lb,DuLinkList &Lc);
void reverseDuLinkList(DuLinkList &L);
DuLinkList FindMiddle(DuLinkList L);
DuLinkList FindMiddle(DuLinkList L,int k);
void DeleteEquLessThanN(DuLinkList &L);
void DuLinkList_Test();

ostream& operator<<(ostream &out, DuLinkList L);



#endif // !DULINKLIST_H
