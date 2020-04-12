#ifndef GRAGH_H
#define GRAGH_H

//chapter 7 Gragh(ͼ)

//�ڽӾ������ݽṹ
#define MaxVnum 100					//�������ֵ
typedef char VexType;					//������������ͣ����Ը�����Ҫ����
typedef int EdgeType;				//���ϵ�Ȩֵ���������ͣ�������Ȩֵ��ͼ����Ϊ0��1

//Adjacency matrix���ڽӾ���
typedef struct {
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum, edgenum;
}AMGragh;

void CreateAMGragh(AMGragh &G);
int locatevex(AMGragh &G, VexType u);

void AMGraghTest();

void BFS_AM(AMGragh G, int v);

//�ڽӱ����ݽṹ����
typedef struct AdjNode {//�����ڽӵ�����
	int v;																//�ڽӵ��±�
	struct AdjNode *next;									//ָ����һ���ڽӵ�
}AdjNode;

typedef struct VexNode {//���嶨������
	VexType data;												//VexTypeΪ������������ͣ����Ը�����Ҫ���ж���
	AdjNode *first;												//ָ���һ���ڽӵ�

}VexNode;

//ͼ���ڽӱ�洢�Ľṹ�嶨��
#define MaxVnum 100

typedef struct {
	VexNode Vex[MaxVnum];							//�������͵Ķ����
	int vexnum, edgenum;									//������������
}ALGragh;

void CreateALGragh(ALGragh &G);

int locatevex(ALGragh &G, VexType u);

void insertedge(ALGragh &G, int i, int j);

void ALGraghTest();

void BFS_AL(ALGragh G, int v);


//ʮ������
typedef struct arcNode {//���ڵ�
	int head;		//ͷ�±�
	int tail;			//β�±�
	struct arcNode *hlink;			//ָ�룬ָ��ͬͷ�Ļ�
	struct arcNode *tlink;			//ָ�룬ָ��ͬβ�͵Ļ�
}arcNode;

typedef struct vexNodeol {//����ڵ�
	VexType data;						//�������ݣ����͸�����Ҫ�趨
	arcNode *firstin;					//ָ�룬ָ���һ���뻡
	arcNode *firstout;					//ָ�룬ָ���һ������
}vexNodeol;

//ʮ������洢������
typedef struct {
	vexNodeol Vex[MaxVnum];
	int  vexnum, edgenum;
}OLGragh;

//Depth first search(�����������,�ڽӾ���Adjacency matrix)
void DFS_AM(AMGragh G, int v);

//Adjaceny list(�ڽ��б�)
void DFS_AL(ALGragh G, int v);

void DFS_AL(ALGragh G);//����ͨͼ


//ͼ��Ӧ��ʵ��

void Dijkastra(AMGragh G, int u);

void CreateAMNet(AMGragh &G);

void Floyd(AMGragh G);

void CreateAMNet_Floyd(AMGragh & G);

#endif // GRAGH_H
