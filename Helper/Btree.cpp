#include "stdafx.h"
#include "Btree.h"
#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;


//询问法创建（一种递归创建）
void createtree1(Btree & T)
{
	char check;							//判断是否创建左孩子
	T = new Bnode;
	std::cout << "请输入节点信息" << std::endl;			//输入根节点信息
	cin >> T->data;
	cout << "是否添加" << T->data << "的左孩子?(N/Y)" << endl;						//询问是否创建T的左孩子
	cin >> check;
	if (check == 'Y')
		createtree1(T->lchild);
	else
		T->lchild = NULL;
	cout << "是否添加" << T->data << "的右孩子?(N/Y)" << endl;
	cin >> check;
	if (check == 'Y')
		createtree1(T->rchild);
	else
		T->rchild = NULL;

}

//补空法
void createtree2(Btree & T)
{
	//二叉树补空之后按照先续序列输入字符
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new Bnode;
		T->data = ch;					//生成根节点
		createtree2(T->lchild);		//创建左孩子
		createtree2(T->rchild);		//创建右孩子
	}

}

//先序遍历
void preorder(Btree & T)
{
	if (T)
	{
		cout << T->data << " ";
		preorder(T->lchild);				//先递归遍历左孩子
		preorder(T->rchild);				//然后递归遍历右孩子
	}
}

//中序遍历
void inorder(Btree & T)
{
	if (T)
	{
		inorder(T->lchild);				//先递归遍历左孩子
		cout << T->data << " ";
		inorder(T->rchild);				//然后递归遍历右孩子
	}
}

//后序遍历
void postorder(Btree & T)
{
	if (T)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout << T->data << " ";
	}
}

//分层遍历
bool leveltraverse(Btree & T)
{
	Btree p;
	if (!T)
		return false;
	queue<Btree>Q;						//创建一个队列，用于存放节点指针
	Q.push(T);									//根指针入队
	if (!Q.empty())
	{
		p = Q.front();						//取出队头元素作为当前节点
		Q.pop();								//对头元素出队
		cout << p->data << " ";
		if (p->lchild)
			Q.push(p->lchild);
		if (p->rchild)
			Q.push(p->rchild);
	}

}

//pre是全局变量指向刚刚访问过的节点,指向p的前驱
BTtree pre;
//中序线索化
void InThread(BTtree & p)
{
	if (p)
	{
		InThread(p->lchild);			//中序化p的左子树
		if (!p->lchild)					//p的左子树为空
		{
			p->ltag = 1;					//标志域为1，标识线索（前驱）
			p->lchild = pre;			//p的左指针指向pre（前驱）
		}
		else
			p->rtag = 1;					//标志位0非线索
		if (pre)
		{
			if (!pre->rchild)			//如果pre的右子树为空
			{
				pre->rtag = 1;			//标志域为1，为线索（后继）
				pre->rchild = p;		//pre右指针指向p
			}
			else
				pre->rtag = 0;			//右标志位为0，非线索
		}
		pre = p;							//更新pre，p将要移向右子树，始终保持pre指向p的前驱
		InThread(p->rchild);			//中序化p的右子树
	}
}

//创建中序线索二叉树
void CreatInThread(BTtree & T)
{
	pre = NULL;								//初始化为空
	if (T)
	{
		InThread(T);							//中序线索化
		pre->rchild = NULL;				//处理遍历的最后一个节点，其后继为空
		pre->rtag = 1;
	}
}

//遍历中序线索二叉树
void InorderThread(BTtree T)
{
	BTtree p;
	p = T;
	while (p)
	{
		while (p->ltag == 0)						//找最左节点
			p = p->lchild;
		cout << p->data << " ";					//输出节点信息
		while (p->rtag = 1 && p->rchild)
		{
			p = p->rchild;								//访问后继节点
			cout << p->data << " ";				//输出节点信息
		}
		p = p->rchild;									//转向p的右子树
	}
}

//返回二叉树深度
int Depth(Btree T)
{
	int m, n;
	if (T == NULL)
		return 0;
	else
	{
		m = Depth(T->lchild);//递归计算左子树深度
		n = Depth(T->rchild);//递归计算右子树深度
		if (m > n)
			return m + 1;//返回左右子树最大深度+1
		else
			return n + 1;
	}
	return 0;
}

//求二叉树的叶子数目
int LeafCount(Btree T)
{
	if (T == NULL)//如果树为空，叶子数为0	
		return 0;
	else
		if (T->lchild == NULL && T->rchild == NULL)//左右树均为空，则叶子数为1
			return 1;
		else
			return LeafCount(T->lchild) + LeafCount(T->rchild);//左右子树的叶子数之和
}

//求二叉树节点数
int NodeCount(Btree T)
{
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	return 0;
}

//使用三元组创建二叉树
void CreatebiTree(biTnode *& T)
{
	string a, b, c;
	biTnode *node, *p;
	queue<biTnode*>q;
	cin >> a >> b >> c;
	if (a == "NULL" && b != "NULL")//创建根节点
	{
		node = new biTnode;
		node->data = b;
		node->lchild = node->rchold = NULL;
		T = node;
		q.push(T);
		cout << "根节点" << node->data << "已创建" << endl;
	}
	cin >> a >> b >> c;
	while (!q.empty() && a != "NULL" && b != "NULL")
	{
		p = q.front();//取出头元素
		q.pop();//出队
		while (a == p->data)//最多判断两次,一个节点最多有两个孩子
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

//由先序序列和中序序列还原二叉树
Btree pre_mid_createBiTree(char * pre, char * mid, int len)
{
	if (len == 0)
		return NULL;
	char ch = pre[0];				//先序序列中的第一个节点作为根
	int index = 0;					//在中序列中查找根节点，并用index记录查找的长度
	while (mid[index] != ch)
	{
		index++;
	}
	Btree T = new Bnode;//创建根节点
	T->data = ch;
	T->lchild = pre_mid_createBiTree(pre + 1, mid, index);//创建左子树
	T->rchild = pre_mid_createBiTree(pre+index+1,mid+index+1,len-index-1);//创建右子树

	return T;
}


//由后序序列和中序序列还原二叉树
Btree pro_mid_createBiTree(char * last, char * mid, int len)
{
	if (len == 0)
		return NULL;
	char ch = last[len - 1];//找到后序序列中的最后一个节点，作根
	int index = 0;				//在中序序列中找根节点，并用index记录查询长度
	while (last[index] != ch)
	{
		index++;
	}
	Btree T = new Bnode;//创建根节点
	T->data = ch;
	T->lchild = pro_mid_createBiTree(last,mid,index);//创建左子树
	T->rchild = pro_mid_createBiTree(last+index,mid+index+1,len-index-1);//创建右子树
	return T;
}

//Description:用于构造一个哈夫曼树
//input:输入一个存放了HtreeNode的向量和一个节点数n
void creat_Htree(vector<Htree> &HuffNode, int n)
{
	Htree temp_hnode;																				//一个哈夫曼树的根指针
	//初始化哈夫曼树
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

	//输入n个叶子结点的数值和权重
	for (int i = 0; i < n; i++) {
		cout << "Please input value and weight of leaf node" << i + 1 << endl;
		HuffNode.at(i)->value=val[i];
		HuffNode.at(i)->weight=wei[i];
	}

	//循环构造哈夫曼树

	int i, j, x1, x2;																								//x1,x2为两个最小权值节点的符号
	double m1, m2;																						//m1,m2为两个最小权值节点的权值(m1更小)
	for (i = 0; i < n - 1; i++) {
		m1 = m2 = MAXVALUE;																		//初始化为最大的权值
		x1 = x2 = -1;																						//节点序号初始化为-1

		//找出所有无双亲的最小的两个节点
		for (j = 0; j < n + i; j++) {
			if (HuffNode.at(j)->weight < m1 && HuffNode.at(j)->parent == -1) {
				m2 = m1;																						//大权值给小权值
				x2 = x1;																						//大权值节点位置 赋给 小权值节点位置
				m1 = HuffNode.at(j)->weight;														//较小节点权重赋值给m1
				x1 = j;																							//较小的节点位置数值赋予x1
			}
			else if (HuffNode.at(j)->weight < m2 && HuffNode.at(j)->parent == -1) {
				m2 = HuffNode.at(j)->weight;														//获取次小的节点权重
				x2 = j;
			}
		}//for j
		
		 /*更新树信息*/
		HuffNode.at(x1)->parent = n + i;															//本次循环权重最小的节点的父节点赋予新编号，n+i（也就是在哈夫曼表最下层加一行）
		HuffNode.at(x2)->parent = n + i;															//次小节点的父节点赋予新编号:n+i
		HuffNode.at(n+i)->weight = m1 + m2;												//新权值为两权值
		HuffNode.at(n + i)->lchild = x1;															//新节点，将权值较小的节点作为新节点的左孩子
		HuffNode.at(n + i)->rchild = x2;															//次小权重节点的序号赋值给新节点的右孩子
	}//for i

}

void HuffmanCode(HCodeType HuffCode[MAXLEAF], int n)
{
	HCodeType cd;								/*定义一个临时变量来存放求解编码时的信息*/
	vector<Htree> HuffNode;							//用来存放返回的哈夫曼树表
	creat_Htree(HuffNode, n);
	int i, j, c, p;
	for (i = 0; i < n; i++) {
		cd.strat = n - 1;
		c = i;											//i为叶子节点编号,c用来存储子节点编号信息
		p = HuffNode.at(c)->parent;			//用来存储父节点编号信息
		while (p != -1) {
			//判断c编号节点是其父节点的左孩子还是右孩子
			if (HuffNode.at(p)->lchild == c) {
				cd.bit[cd.strat] = 0;
			}
			else
				cd.bit[cd.strat] = 1;
			cd.strat--;								//起始点最开始在最右侧，完成一次操作，向左移动一位
			c = p;									//将父节点的哈夫曼表编号赋给子节点
			p = HuffNode.at(c)->parent;		//父节点获取自己父节点的编号数值
		}
		/*把叶子节点的编号信息从临时编码cd中提取出来，放入编码结构体数组中*/
		for (j = cd.strat+1; j < n; j++) {
			HuffCode[i].bit[j] = cd.bit[j];
		}
		HuffCode[i].strat = cd.strat;
	}
}

//哈夫曼树的测试代码
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




