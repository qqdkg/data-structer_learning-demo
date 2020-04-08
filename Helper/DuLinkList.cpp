#include"stdafx.h"
#include"DuLinkList.h"

bool initList_L(DuLinkList &L)
{
	L = new DuLnode;
	if (!L)
		return false;
	L->next = L->prior = NULL;					//ָ���ÿ�
	return true;
}

void CreatList_H(DuLinkList &L)
{
	int n;						//����Ԫ�ظ���
	DuLinkList s;			//��ǰ����Ԫ��ָ��
	L = new DuLnode;
	L->next = L->prior = NULL;
	cout << "������Ԫ�ظ���n:" << endl;
	cin >> n;
	cout << "������ÿ��Ԫ��ֵ:" << endl;
	cout << "ͷ�巨��˫������������" << endl;
	while (n--) {
		s = new DuLnode;
		cin >> s->Data;
		if (L->next)								//L�ĺ����нڵ㣬�������Ӹ�δ��ǵĽڵ�
			L->next->prior = s;
		s->next = L->next;					//������s�ĺ󷽽ڵ�
		s->prior = L;							//��s�ŵ�L֮��,����s��L������
		L->next = s;								//����L��s������
	}
}

void CreatList_H(DuLinkList &L, int *arr, int n)
{
	DuLinkList s;			//��ǰ����Ԫ��ָ��
	L = new DuLnode;
	L->next = L->prior = NULL;
	while (n--) {
		s = new DuLnode;
		s->Data = arr[n];
		if (L->next)								//L�ĺ����нڵ㣬�������Ӹ�δ��ǵĽڵ�
			L->next->prior = s;
		s->next = L->next;					//������s�ĺ󷽽ڵ�
		s->prior = L;							//��s�ŵ�L֮��,����s��L������
		L->next = s;								//����L��s������
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
	if (!p || counter > index)//i>n+1��i<1
		return false;
	s = new DuLnode;
	s->Data = target;
	p->prior->next = s;			//��s���ӵ�p��ǰһ��Ԫ�صĺ���
	s->prior = p->prior;		//��s��ǰָ�����ӵ�p��ǰһ��Ԫ����
	s->next = p;						//s�ĺ�ָ�����ӵ�p��
	p->prior = s;					//p��ǰָ�����ӵ�s�ϣ���ɽ�s���뵽��index��Ԫ��ǰ�Ĳ���
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
	if (!p || counter > index)//i>n+1��i<1
		return false;
	//������������index���ڵ�Ĵ���ͬ����
	if (p->next)
		p->next->prior = p->prior;				//��p��һ��Ԫ�ص�ǰָ��ָ��p����һ��Ԫ����
	p->prior->next = p->next;					//��p��ǰһ��Ԫ�صĺ�ָ��ָ��p�ĺ�һ��Ԫ���ϣ��Ӷ���p��������ȡ��
	delete p;
	return true;
}

//�ϲ�����
void MergeDuLinkList(DuLinkList La, DuLinkList Lb, DuLinkList & Lc)
{
	DuLinkList ptra, ptrb, ptrc;
	ptra = La->next;
	ptrb = Lb->next;
	Lc = La;									//Lcָ��La��ͷ���
	ptrc = Lc;									//ptrcΪLc��β���
	while (ptra&&ptrb)
	{
		if (ptra->Data <= ptrb->Data)			//��La�Ľڵ�
		{
			ptrc->next = ptra;
			ptra->prior = ptrc;
			ptrc = ptra;
			ptra = ptra->next;
		}
		else													//��Lb�Ľڵ�
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

//��ת����
void reverseDuLinkList(DuLinkList & L)
{
	DuLinkList p, q;
	p = L->next;							//pָ��(��ǰ��������ָ��)ָ������ĵ�һ������Ԫ��
	L->next = NULL;					//�Ͽ�ͷ�ڵ�����������
	while (p) 
	{
		q = p->next;					//q(�ϵ�ץȡָ��)ָ��p����һ���ڵ㣬���ڼ�¼�ϵ�
		p->next = L->next;	
		if(p->next)
			p->next->prior = p;		//����p��һ��Ԫ�ص�ǰָ�뵽p
		L->next = p;						//����ǰԪ�ز���L֮��
		p->prior = L;					//�ظ�p��L������
		p = q;								//pָ�����
	}

}

//Ѱ���м�ڵ㣬����ָ���м�ڵ��ָ��(����ָ�뷨)
DuLinkList FindMiddle(DuLinkList L)
{
	DuLinkList qk, sl;			//��ָ�룬��ָ��
	qk = L;
	sl = L;
	while (qk != NULL&&qk->next != NULL)
	{
		qk = qk->next->next;							//��ָ��������
		sl = sl->next;										//��ָ����һ��
	}
	return sl;
}

//Ѱ�ҵ�����k���ڵ㲢������ָ��(����ָ�뷨)
DuLinkList FindMiddle(DuLinkList L, int k)
{
	DuLinkList qk, sl;				//��ָ�룬��ָ��
	qk = L;
	sl = L;
	while (qk->next != NULL)
	{
		if (--k <= 0)
			sl = sl->next;			//��ָ������k-1��(Ҳ������ָ����k-1��֮�����)
		qk = qk->next;
	}
	if (k > 0)
		return NULL;
	else
	return sl;
}

//����L������С��n��Ϊ�������޳����о���ֵ��ͬ��Ԫ�ؽڵ�
void DeleteEquLessThanN(DuLinkList & L)
{
	DuLinkList p, q;								//��ǰ�ڵ�ָ�룬ץ��ָ��
	int n = 50;									//������Ŀ��Ԫ��С��50
	int *flag = new int[n + 1];				//���ڱ��ĳ�����Ƿ���ֵı��λ����
	for (int i = 0; i < n+1; i++)
		flag[i] = 0;									//��ʼ��
	p = L;											//��ǰ�ڵ�ָ��ָ��ͷ���
	while (p->next != NULL)
	{
		int x = abs(p->next->Data);
		if (flag[x] == 0)
		{
			flag[x] = 1;							//���λ1�����λ�õ����ݳ���
			p = p->next;						//��ǰָ���ƶ�
		}
		else
		{
			q = p->next;						//ץȡָ��ָ���ض��Ľڵ�
			p->next = q->next;				//����qָ��ָ��Ľڵ�
			if(q->next!=NULL)				//��qץ��β�͵�ʱ��q->next�ǲ��Ϸ��ģ���Ϊû���������
				q->next->prior = p;			//�ָ�qָ����һ���ڵ���p�����ӣ�˫�����������ų�Ҫɾ���Ľڵ㣩
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
	cout << "���������Ϊ:" << endl;
	cout << L;
	int index = 3;
	int target = 777;
	ListInsert_L(L, index, target);
	cout << endl;
	cout << "�ڵ�" << index << "��Ԫ�ش���������:" << target << endl;
	cout << "���Ϊ:" << L << endl;
	ListDelete_L(L, index);
	cout << "�ڵ�" << index << "��Ԫ�ش�ɾ��Ԫ��" << endl;
	cout << "���Ϊ:" << L << endl;

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
	cout << "�ҵ�Lc�м�Ԫ��:" << mid->Data << endl;
	mid = FindMiddle(Lc,4);
	cout << "�ҵ�Lc������4��Ԫ��:" << mid->Data << endl;
	int arr3[10] = {1,3,2,4,3,5,9,4,7,9};
	CreatList_H(Lc, arr3, 10);
	cout << "����ȷ��Lc��"<<Lc<<endl;
	DeleteEquLessThanN(Lc);
	cout << "����Lc�е�Ԫ��С��n���޳�����ֵ��ͬ��Ԫ�غ�" << Lc << endl;
}
