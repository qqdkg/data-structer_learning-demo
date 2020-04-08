#include"stdafx.h"
#include"DuLinkList.h"

bool initList_L(DuLinkList &L)
{
	L = new DuLnode;
	if (!L)
		return false;
	L->next = L->prior = NULL;					//指针置空
	return true;
}

void CreatList_H(DuLinkList &L)
{
	int n;						//加入元素个数
	DuLinkList s;			//当前插入元素指针
	L = new DuLnode;
	L->next = L->prior = NULL;
	cout << "请输入元素个数n:" << endl;
	cin >> n;
	cout << "请输入每个元素值:" << endl;
	cout << "头插法，双向链表生成中" << endl;
	while (n--) {
		s = new DuLnode;
		cin >> s->Data;
		if (L->next)								//L的后面有节点，则先链接该未标记的节点
			L->next->prior = s;
		s->next = L->next;					//链接是s的后方节点
		s->prior = L;							//将s放到L之后,生成s与L的链接
		L->next = s;								//生成L与s的链接
	}
}

void CreatList_H(DuLinkList &L, int *arr, int n)
{
	DuLinkList s;			//当前插入元素指针
	L = new DuLnode;
	L->next = L->prior = NULL;
	while (n--) {
		s = new DuLnode;
		s->Data = arr[n];
		if (L->next)								//L的后面有节点，则先链接该未标记的节点
			L->next->prior = s;
		s->next = L->next;					//链接是s的后方节点
		s->prior = L;							//将s放到L之后,生成s与L的链接
		L->next = s;								//生成L与s的链接
	}
}

bool ListInsert_L(DuLinkList &L, int index, int target)
{
	int counter = 0;
	DuLinkList s, p;
	p = L;
	while (p&&counter < index)
	{
		p = p->next;
		counter++;
	}
	if (!p || counter > index)//i>n+1或i<1
		return false;
	s = new DuLnode;
	s->Data = target;
	p->prior->next = s;			//把s连接到p的前一个元素的后面
	s->prior = p->prior;		//把s的前指针连接到p的前一个元素上
	s->next = p;						//s的后指针连接到p上
	p->prior = s;					//p的前指针连接到s上，完成将s插入到第index个元素前的操作
	return true;
}

bool ListDelete_L(DuLinkList &L, int index)
{
	int counter = 0;
	DuLinkList p;
	p = L;
	while (p&&counter < index)
	{
		p = p->next;
		counter++;
	}
	if (!p || counter > index)//i>n+1或i<1
		return false;
	//上面查找链表第index个节点的代码同插入
	if (p->next)
		p->next->prior = p->prior;				//将p后一个元素的前指针指到p的起一个元素上
	p->prior->next = p->next;					//将p的前一个元素的后指针指到p的后一个元素上，从而将p从链表上取出
	delete p;
	return true;
}

//合并链表
void MergeDuLinkList(DuLinkList La, DuLinkList Lb, DuLinkList & Lc)
{
	DuLinkList ptra, ptrb, ptrc;
	ptra = La->next;
	ptrb = Lb->next;
	Lc = La;									//Lc指向La的头结点
	ptrc = Lc;									//ptrc为Lc的尾结点
	while (ptra&&ptrb)
	{
		if (ptra->Data <= ptrb->Data)			//串La的节点
		{
			ptrc->next = ptra;
			ptra->prior = ptrc;
			ptrc = ptra;
			ptra = ptra->next;
		}
		else													//串Lb的节点
		{
			ptrc->next = ptrb;
			ptrb->prior = ptrc;
			ptrc = ptrb;
			ptrb = ptrb->next;
		}
	}
	ptrc->next = ptra ? ptra : ptrb;
	ptrc->next->prior = ptrc;

}

//翻转链表
void reverseDuLinkList(DuLinkList & L)
{
	DuLinkList p, q;
	p = L->next;							//p指针(当前操作对象指针)指向链表的第一个数据元素
	L->next = NULL;					//断开头节点与后面的链接
	while (p) 
	{
		q = p->next;					//q(断点抓取指针)指向p的下一个节点，用于记录断点
		p->next = L->next;	
		if(p->next)
			p->next->prior = p;		//链接p后一个元素的前指针到p
		L->next = p;						//将当前元素插入L之后
		p->prior = L;					//回复p到L的链接
		p = q;								//p指针后移
	}

}

//寻找中间节点，返回指向中间节点的指针(快慢指针法)
DuLinkList FindMiddle(DuLinkList L)
{
	DuLinkList qk, sl;			//快指针，慢指针
	qk = L;
	sl = L;
	while (qk != NULL&&qk->next != NULL)
	{
		qk = qk->next->next;							//快指针走两步
		sl = sl->next;										//慢指针走一步
	}
	return sl;
}

//寻找倒数第k个节点并返回其指针(快慢指针法)
DuLinkList FindMiddle(DuLinkList L, int k)
{
	DuLinkList qk, sl;				//快指针，慢指针
	qk = L;
	sl = L;
	while (qk->next != NULL)
	{
		if (--k <= 0)
			sl = sl->next;			//快指针先走k-1步(也就是慢指针在k-1步之后才走)
		qk = qk->next;
	}
	if (k > 0)
		return NULL;
	else
	return sl;
}

//假设L中数据小于n且为整数，剔除其中绝对值相同的元素节点
void DeleteEquLessThanN(DuLinkList & L)
{
	DuLinkList p, q;								//当前节点指针，抓手指针
	int n = 50;									//假设题目中元素小于50
	int *flag = new int[n + 1];				//用于标记某个数是否出现的标记位数组
	for (int i = 0; i < n+1; i++)
		flag[i] = 0;									//初始化
	p = L;											//当前节点指针指向头结点
	while (p->next != NULL)
	{
		int x = abs(p->next->Data);
		if (flag[x] == 0)
		{
			flag[x] = 1;							//标记位1标书该位置的数据出现
			p = p->next;						//当前指针移动
		}
		else
		{
			q = p->next;						//抓取指针指向重读的节点
			p->next = q->next;				//跳过q指针指向的节点
			if(q->next!=NULL)				//当q抓到尾巴的时候，q->next是不合法的，因为没这个东西了
				q->next->prior = p;			//恢复q指针下一个节点与p的链接（双向链表跳过排除要删除的节点）
			delete q;
		}
	}

	delete[]flag;
}


ostream& operator<<(ostream &out, DuLinkList L) {
	DuLinkList p;
	p = L;
	while (p->next) {
		p = p->next;
		cout << p->Data << " ";
	}
	return out;
}

void DuLinkList_Test() {
	DuLinkList L;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	CreatList_H(L, arr, 10);
	cout << "输入的链表为:" << endl;
	cout << L;
	int index = 3;
	int target = 777;
	ListInsert_L(L, index, target);
	cout << endl;
	cout << "在第" << index << "个元素处插入数据:" << target << endl;
	cout << "结果为:" << L << endl;
	ListDelete_L(L, index);
	cout << "在第" << index << "个元素处删除元素" << endl;
	cout << "结果为:" << L << endl;

	DuLinkList La;
	DuLinkList Lb;
	DuLinkList Lc;
	int arr1[5] = { 1,3,5,7,9 };
	int arr2[5] = { 2,4,6,8,10 };
	CreatList_H(La, arr1, 5);
	CreatList_H(Lb, arr2, 5);
	MergeDuLinkList(La, Lb, Lc);
	cout << "Lc:" << Lc << endl;
	reverseDuLinkList(Lc);
	cout << "reverse:" << endl << "Lc=" << Lc << endl;
	DuLinkList mid=FindMiddle(Lc);
	cout << "找到Lc中间元素:" << mid->Data << endl;
	mid = FindMiddle(Lc,4);
	cout << "找到Lc倒数第4个元素:" << mid->Data << endl;
	int arr3[10] = {1,3,2,4,3,5,9,4,7,9};
	CreatList_H(Lc, arr3, 10);
	cout << "重新确立Lc："<<Lc<<endl;
	DeleteEquLessThanN(Lc);
	cout << "假设Lc中的元素小于n，剔除绝对值相同的元素后：" << Lc << endl;
}
