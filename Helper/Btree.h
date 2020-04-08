#ifndef BTREE_H_
#define BTREE_H_
#include<string>
#include<vector>
//二叉树数据结构

typedef int ElementType;

typedef struct Bnode {
	ElementType data;
	struct Bnode *lchild, *rchild, *parent;
}Bnode,*Btree;

void createtree1(Btree &T);

void createtree2(Btree &T);

void preorder(Btree &T);

void inorder(Btree &T);

void postorder(Btree &T);

bool leveltraverse(Btree &T);


//线索二叉树

typedef struct BTnode {
	ElementType data;
	struct BTnode *lchild, *rchild;					//元素类型为Bnode
	int ltag, rtag;											//左右标志域
}BTnode,*BTtree;

void InThread(BTtree &T);

void CreatInThread(BTtree &T);

void InorderThread(BTtree T);

//二叉树应用

int Depth(Btree T);

int LeafCount(Btree T);

int NodeCount(Btree T);

typedef struct biTnode {
	std::string data;
	struct biTnode *lchild, *rchold;
}biTnode,*biTree;

void CreatebiTree(biTnode* &T);

Btree pre_mid_createBiTree(char *pre,char *mid,int len);

Btree pro_mid_createBiTree(char *last, char *mid, int len);

#define MAXBIT 50							//编码最长值
#define MAXVALUE 1000					//最大权值
#define MAXLEAF 100						//最大叶子节点数

typedef struct
{
	double weight;								//权值
	int parent;										//双亲
	int lchild;										//左孩子
	int rchild;										//右孩子
	char value;									//该节点标识的字符
} HNodeType,*Htree;

typedef struct 
{
	int bit[MAXBIT];			//存储编码的数组
	int strat;						//编码开始下标
} HCodeType;				/*编码结构体*/

void creat_Htree(std::vector<Htree> &HuffNode,int n);

void HuffmanCode(HCodeType HuffCode[MAXLEAF], int n);

void Huff_Test();


#endif // !BTREE_H_
