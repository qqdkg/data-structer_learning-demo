#ifndef BTREE_H_
#define BTREE_H_
#include<string>
#include<vector>
//���������ݽṹ

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


//����������

typedef struct BTnode {
	ElementType data;
	struct BTnode *lchild, *rchild;					//Ԫ������ΪBnode
	int ltag, rtag;											//���ұ�־��
}BTnode,*BTtree;

void InThread(BTtree &T);

void CreatInThread(BTtree &T);

void InorderThread(BTtree T);

//������Ӧ��

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

#define MAXBIT 50							//�����ֵ
#define MAXVALUE 1000					//���Ȩֵ
#define MAXLEAF 100						//���Ҷ�ӽڵ���

typedef struct
{
	double weight;								//Ȩֵ
	int parent;										//˫��
	int lchild;										//����
	int rchild;										//�Һ���
	char value;									//�ýڵ��ʶ���ַ�
} HNodeType,*Htree;

typedef struct 
{
	int bit[MAXBIT];			//�洢���������
	int strat;						//���뿪ʼ�±�
} HCodeType;				/*����ṹ��*/

void creat_Htree(std::vector<Htree> &HuffNode,int n);

void HuffmanCode(HCodeType HuffCode[MAXLEAF], int n);

void Huff_Test();


#endif // !BTREE_H_
