#ifndef GRAGH_H
#define GRAGH_H

//chapter 7 Gragh(图)

//邻接矩阵数据结构
#define MaxVnum 100					//定点最大值
typedef char VexType;					//定点的数据类型，可以更具需要定义
typedef int EdgeType;				//边上的权值的数据类型，若不带权值的图，则为0或1

//Adjacency matrix（邻接矩阵）
typedef struct {
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum, edgenum;
}AMGragh;

void CreateAMGragh(AMGragh &G);
int locatevex(AMGragh &G, VexType u);

void AMGraghTest();

void BFS_AM(AMGragh G, int v);

//邻接表数据结构定义
typedef struct AdjNode {//定义邻接点类型
	int v;																//邻接点下标
	struct AdjNode *next;									//指向下一个邻接点
}AdjNode;

typedef struct VexNode {//定义定点类型
	VexType data;												//VexType为定点的数据类型，可以根据需要自行定义
	AdjNode *first;												//指向第一个邻接点

}VexNode;

//图的邻接表存储的结构体定义
#define MaxVnum 100

typedef struct {
	VexNode Vex[MaxVnum];							//定点类型的定点表
	int vexnum, edgenum;									//顶点数，边数
}ALGragh;

void CreateALGragh(ALGragh &G);

int locatevex(ALGragh &G, VexType u);

void insertedge(ALGragh &G, int i, int j);

void ALGraghTest();

void BFS_AL(ALGragh G, int v);


//十字链表
typedef struct arcNode {//弧节点
	int head;		//头下标
	int tail;			//尾下标
	struct arcNode *hlink;			//指针，指向同头的弧
	struct arcNode *tlink;			//指针，指向同尾巴的弧
}arcNode;

typedef struct vexNodeol {//顶点节点
	VexType data;						//顶点数据，类型根据需要设定
	arcNode *firstin;					//指针，指向第一个入弧
	arcNode *firstout;					//指针，指向第一个出弧
}vexNodeol;

//十字链表存储机构提
typedef struct {
	vexNodeol Vex[MaxVnum];
	int  vexnum, edgenum;
}OLGragh;

//Depth first search(广度优先搜索,邻接矩阵Adjacency matrix)
void DFS_AM(AMGragh G, int v);

//Adjaceny list(邻接列表)
void DFS_AL(ALGragh G, int v);

void DFS_AL(ALGragh G);//非连通图


//图的应用实例

void Dijkastra(AMGragh G, int u);

void CreateAMNet(AMGragh &G);

void Floyd(AMGragh G);

void CreateAMNet_Floyd(AMGragh & G);

#endif // GRAGH_H
