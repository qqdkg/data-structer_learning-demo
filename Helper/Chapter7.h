#ifndef __CHAPTER3_H_
#define __CHAPTER3_H_

//第7章，线性规划网络流

//工厂效益最大问题，使用单纯形算法
//单纯形算法是针对标准型线性规划问题的通用解法
//需要自己将实际生产中遇到的生产安排问题抽象，转变成单纯形表输入进行计算

class BestBenefitTank {
private:
	const static int N = 20;
	float kernel[N][N];															//用于存储单纯形表的二维矩阵
	char FJL[N];																		//非基本变量
	char JL[N];																			//基本变量
	int n, m;
	void print();
	void DCXA();
public:
	void BBTTest();
	void BBTTest2();
};

//最大网络流-最短增广路算法（Shortest Augument Path）
class NetFlowSapTank {
private:
	const static  int N = 20;
	const static int INF = (1 << 30) - 1;
	int g[N][N];														//残余网络（初始时各边为容量）
	int f[N][N];														//实流网络（初始时各边为0流）
	int pre[N];															//前驱数组
	bool vis[N];														//访问数组
	int n, m;
	bool bfs(int s, int t);
	int EK(int s, int t);
	void print();
public:
	void NFSTTest();
};

//使用数组的形式实现邻接表
typedef struct Vertex {
	int first;
}Vertex;

typedef struct Edge {
	int v, next;
	int cap, flow;
}Edge;

//使用重贴标签思路的最短曾广路算法
class ISAPTank {
private:
	const int inf = 0x3fffffff;
	const static int N = 100;
	const static int M = 10000;
	int top;
	int h[N];															//h[]数据组记录每个结点的高度，既到汇点的最短距离
	int pre[N];															//pre[]数组记录当前结点的前驱边,pre[v] = i;表示结点v前驱边为i，即搜索路径入边
	int g[N];															//g[]数组记录高度（到汇点最短距离）为h[]的节点的个数，如：g[3] = 1表示高度3的结点个数为1个
	Vertex V[N];														//顶点数组
	Edge E[M];														//边数组
	void init();
	void add_edge(int u, int v, int c);						//创建边
	void add(int u, int v, int c);								//穿件两条边
	void set_h(int t, int n);										//标高函数
	int Isap(int s, int t, int n);									//升级版最短增广路算法（Imporved Shortest Argument Path）
	void printg(int n);												//输出网络邻接表
	void printflow(int n);											//输出实流边
public:
	void ISAPTest();												//例程入口函数
};


#endif // !__CHAPTER3_H_
