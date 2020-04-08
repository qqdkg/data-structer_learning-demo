#include "stdafx.h"
#include "Btree.h"
#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;


//ѯ�ʷ�������һ�ֵݹ鴴����
void createtree1(Btree & T)
{
	char check;							//�ж��Ƿ񴴽�����
	T = new Bnode;
	std::cout << "������ڵ���Ϣ" << std::endl;			//������ڵ���Ϣ
	cin >> T->data;
	cout << "�Ƿ����" << T->data << "������?(N/Y)" << endl;						//ѯ���Ƿ񴴽�T������
	cin >> check;
	if (check == 'Y')
		createtree1(T->lchild);
	else
		T->lchild = NULL;
	cout << "�Ƿ����" << T->data << "���Һ���?(N/Y)" << endl;
	cin >> check;
	if (check == 'Y')
		createtree1(T->rchild);
	else
		T->rchild = NULL;

}

//���շ�
void createtree2(Btree & T)
{
	//����������֮�����������������ַ�
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new Bnode;
		T->data = ch;					//���ɸ��ڵ�
		createtree2(T->lchild);		//��������
		createtree2(T->rchild);		//�����Һ���
	}

}

//�������
void preorder(Btree & T)
{
	if (T)
	{
		cout << T->data << " ";
		preorder(T->lchild);				//�ȵݹ��������
		preorder(T->rchild);				//Ȼ��ݹ�����Һ���
	}
}

//�������
void inorder(Btree & T)
{
	if (T)
	{
		inorder(T->lchild);				//�ȵݹ��������
		cout << T->data << " ";
		inorder(T->rchild);				//Ȼ��ݹ�����Һ���
	}
}

//�������
void postorder(Btree & T)
{
	if (T)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout << T->data << " ";
	}
}

//�ֲ����
bool leveltraverse(Btree & T)
{
	Btree p;
	if (!T)
		return false;
	queue<Btree>Q;						//����һ�����У����ڴ�Žڵ�ָ��
	Q.push(T);									//��ָ�����
	if (!Q.empty())
	{
		p = Q.front();						//ȡ����ͷԪ����Ϊ��ǰ�ڵ�
		Q.pop();								//��ͷԪ�س���
		cout << p->data << " ";
		if (p->lchild)
			Q.push(p->lchild);
		if (p->rchild)
			Q.push(p->rchild);
	}

}

//pre��ȫ�ֱ���ָ��ոշ��ʹ��Ľڵ�,ָ��p��ǰ��
BTtree pre;
//����������
void InThread(BTtree & p)
{
	if (p)
	{
		InThread(p->lchild);			//����p��������
		if (!p->lchild)					//p��������Ϊ��
		{
			p->ltag = 1;					//��־��Ϊ1����ʶ������ǰ����
			p->lchild = pre;			//p����ָ��ָ��pre��ǰ����
		}
		else
			p->rtag = 1;					//��־λ0������
		if (pre)
		{
			if (!pre->rchild)			//���pre��������Ϊ��
			{
				pre->rtag = 1;			//��־��Ϊ1��Ϊ��������̣�
				pre->rchild = p;		//pre��ָ��ָ��p
			}
			else
				pre->rtag = 0;			//�ұ�־λΪ0��������
		}
		pre = p;							//����pre��p��Ҫ������������ʼ�ձ���preָ��p��ǰ��
		InThread(p->rchild);			//����p��������
	}
}

//������������������
void CreatInThread(BTtree & T)
{
	pre = NULL;								//��ʼ��Ϊ��
	if (T)
	{
		InThread(T);							//����������
		pre->rchild = NULL;				//������������һ���ڵ㣬����Ϊ��
		pre->rtag = 1;
	}
}

//������������������
void InorderThread(BTtree T)
{
	BTtree p;
	p = T;
	while (p)
	{
		while (p->ltag == 0)						//������ڵ�
			p = p->lchild;
		cout << p->data << " ";					//����ڵ���Ϣ
		while (p->rtag = 1 && p->rchild)
		{
			p = p->rchild;								//���ʺ�̽ڵ�
			cout << p->data << " ";				//����ڵ���Ϣ
		}
		p = p->rchild;									//ת��p��������
	}
}

//���ض��������
int Depth(Btree T)
{
	int m, n;
	if (T == NULL)
		return 0;
	else
	{
		m = Depth(T->lchild);//�ݹ�������������
		n = Depth(T->rchild);//�ݹ�������������
		if (m > n)
			return m + 1;//������������������+1
		else
			return n + 1;
	}
	return 0;
}

//���������Ҷ����Ŀ
int LeafCount(Btree T)
{
	if (T == NULL)//�����Ϊ�գ�Ҷ����Ϊ0	
		return 0;
	else
		if (T->lchild == NULL && T->rchild == NULL)//��������Ϊ�գ���Ҷ����Ϊ1
			return 1;
		else
			return LeafCount(T->lchild) + LeafCount(T->rchild);//����������Ҷ����֮��
}

//��������ڵ���
int NodeCount(Btree T)
{
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	return 0;
}

//ʹ����Ԫ�鴴��������
void CreatebiTree(biTnode *& T)
{
	string a, b, c;
	biTnode *node, *p;
	queue<biTnode*>q;
	cin >> a >> b >> c;
	if (a == "NULL" && b != "NULL")//�������ڵ�
	{
		node = new biTnode;
		node->data = b;
		node->lchild = node->rchold = NULL;
		T = node;
		q.push(T);
		cout << "���ڵ�" << node->data << "�Ѵ���" << endl;
	}
	cin >> a >> b >> c;
	while (!q.empty() && a != "NULL" && b != "NULL")
	{
		p = q.front();//ȡ��ͷԪ��
		q.pop();//����
		while (a == p->data)//����ж�����,һ���ڵ��������������
		{
			node = new biTnode;
			node->data = b;
			node->lchild = node->rchold = NULL;
			if (c == "L")
			{
				p->lchild = node;
				cout << p->data << "'s lChild is " << node->data << endl;
			}
			else
			{
				p->rchold = node;
				cout << p->data << "'s rChild is " << node->data << endl;
			}
			q.push(node);
			cin >> a >> b >> c;
		}

	}
}

//���������к��������л�ԭ������
Btree pre_mid_createBiTree(char * pre, char * mid, int len)
{
	if (len == 0)
		return NULL;
	char ch = pre[0];				//���������еĵ�һ���ڵ���Ϊ��
	int index = 0;					//���������в��Ҹ��ڵ㣬����index��¼���ҵĳ���
	while (mid[index] != ch)
	{
		index++;
	}
	Btree T = new Bnode;//�������ڵ�
	T->data = ch;
	T->lchild = pre_mid_createBiTree(pre + 1, mid, index);//����������
	T->rchild = pre_mid_createBiTree(pre+index+1,mid+index+1,len-index-1);//����������

	return T;
}


//�ɺ������к��������л�ԭ������
Btree pro_mid_createBiTree(char * last, char * mid, int len)
{
	if (len == 0)
		return NULL;
	char ch = last[len - 1];//�ҵ����������е����һ���ڵ㣬����
	int index = 0;				//�������������Ҹ��ڵ㣬����index��¼��ѯ����
	while (last[index] != ch)
	{
		index++;
	}
	Btree T = new Bnode;//�������ڵ�
	T->data = ch;
	T->lchild = pro_mid_createBiTree(last,mid,index);//����������
	T->rchild = pro_mid_createBiTree(last+index,mid+index+1,len-index-1);//����������
	return T;
}

//Description:���ڹ���һ����������
//input:����һ�������HtreeNode��������һ���ڵ���n
void creat_Htree(vector<Htree> &HuffNode, int n)
{
	Htree temp_hnode;																				//һ�����������ĸ�ָ��
	//��ʼ����������
	for (int i = 0; i < 2 * n - 1; i++) {
		temp_hnode = new HNodeType;
		temp_hnode->weight = 0;
		temp_hnode->parent = -1;
		temp_hnode->lchild = -1;
		temp_hnode->rchild = -1;
		HuffNode.push_back(temp_hnode);
	}


	char val[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	double wei[6] = {5,32,18,7,25,13};

	//����n��Ҷ�ӽ�����ֵ��Ȩ��
	for (int i = 0; i < n; i++) {
		cout << "Please input value and weight of leaf node" << i + 1 << endl;
		HuffNode.at(i)->value=val[i];
		HuffNode.at(i)->weight=wei[i];
	}

	//ѭ�������������

	int i, j, x1, x2;																								//x1,x2Ϊ������СȨֵ�ڵ�ķ���
	double m1, m2;																						//m1,m2Ϊ������СȨֵ�ڵ��Ȩֵ(m1��С)
	for (i = 0; i < n - 1; i++) {
		m1 = m2 = MAXVALUE;																		//��ʼ��Ϊ����Ȩֵ
		x1 = x2 = -1;																						//�ڵ���ų�ʼ��Ϊ-1

		//�ҳ�������˫�׵���С�������ڵ�
		for (j = 0; j < n + i; j++) {
			if (HuffNode.at(j)->weight < m1 && HuffNode.at(j)->parent == -1) {
				m2 = m1;																						//��Ȩֵ��СȨֵ
				x2 = x1;																						//��Ȩֵ�ڵ�λ�� ���� СȨֵ�ڵ�λ��
				m1 = HuffNode.at(j)->weight;														//��С�ڵ�Ȩ�ظ�ֵ��m1
				x1 = j;																							//��С�Ľڵ�λ����ֵ����x1
			}
			else if (HuffNode.at(j)->weight < m2 && HuffNode.at(j)->parent == -1) {
				m2 = HuffNode.at(j)->weight;														//��ȡ��С�Ľڵ�Ȩ��
				x2 = j;
			}
		}//for j
		
		 /*��������Ϣ*/
		HuffNode.at(x1)->parent = n + i;															//����ѭ��Ȩ����С�Ľڵ�ĸ��ڵ㸳���±�ţ�n+i��Ҳ�����ڹ����������²��һ�У�
		HuffNode.at(x2)->parent = n + i;															//��С�ڵ�ĸ��ڵ㸳���±��:n+i
		HuffNode.at(n+i)->weight = m1 + m2;												//��ȨֵΪ��Ȩֵ
		HuffNode.at(n + i)->lchild = x1;															//�½ڵ㣬��Ȩֵ��С�Ľڵ���Ϊ�½ڵ������
		HuffNode.at(n + i)->rchild = x2;															//��СȨ�ؽڵ����Ÿ�ֵ���½ڵ���Һ���
	}//for i

}

void HuffmanCode(HCodeType HuffCode[MAXLEAF], int n)
{
	HCodeType cd;								/*����һ����ʱ���������������ʱ����Ϣ*/
	vector<Htree> HuffNode;							//������ŷ��صĹ���������
	creat_Htree(HuffNode, n);
	int i, j, c, p;
	for (i = 0; i < n; i++) {
		cd.strat = n - 1;
		c = i;											//iΪҶ�ӽڵ���,c�����洢�ӽڵ�����Ϣ
		p = HuffNode.at(c)->parent;			//�����洢���ڵ�����Ϣ
		while (p != -1) {
			//�ж�c��Žڵ����丸�ڵ�����ӻ����Һ���
			if (HuffNode.at(p)->lchild == c) {
				cd.bit[cd.strat] = 0;
			}
			else
				cd.bit[cd.strat] = 1;
			cd.strat--;								//��ʼ���ʼ�����Ҳ࣬���һ�β����������ƶ�һλ
			c = p;									//�����ڵ�Ĺ��������Ÿ����ӽڵ�
			p = HuffNode.at(c)->parent;		//���ڵ��ȡ�Լ����ڵ�ı����ֵ
		}
		/*��Ҷ�ӽڵ�ı����Ϣ����ʱ����cd����ȡ�������������ṹ��������*/
		for (j = cd.strat+1; j < n; j++) {
			HuffCode[i].bit[j] = cd.bit[j];
		}
		HuffCode[i].strat = cd.strat;
	}
}

//���������Ĳ��Դ���
void Huff_Test()
{
	int n = 6;
	HCodeType HuffCode[MAXLEAF];
	HuffmanCode(HuffCode, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = HuffCode[i].strat + 1; j < n; j++)
		{
			cout << HuffCode[i].bit[j];
		}
		cout << endl;
	}
}




