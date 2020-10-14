#ifndef __CHAPTER6_H
#define __CHAPTER6_H

/*
*《趣学算法》第六章，分支限界法的实例（广度优先搜索）
*/

//0-1背包问题的分支限界法实现
typedef struct ShopBagNode
{
	int cp, rp;											//cp背包的物品总价值，rp剩余物品的总价值
	int rw;												//剩余容量
	int id;												//物品编号
	static const int N = 10;						//最大元素数
	bool x[N];											//解向量
	ShopBagNode();
	ShopBagNode(int _cp, int _rp, int _rw, int _id);
}SBNode;

struct Goods
{
	int value;
	int weight;
};

class ZeroOneBagSpan {
private:
	static const int N = 10;
	int bestp;														//bestp用来记录最优值
	int W;															//W为购物车最大容量
	int n;																//n为物品的个数
	int sumw;														//sumw为所有物品的总重量
	int sumv;														//sumv为所有物品的总价值
	bool bestx[N];												//最优解向量
	Goods goods[N];											//用来存储输入的物品属性，包括价值和重量
	int bfs();														//bfs用来进行子集树的广度优先搜索
public:
	void ZOBSTest();
};


//!!=======用于由优先队列实现的0-1背包问题的一些组件
typedef struct ShopBagNodePro{
	int cp;															//当前装入购物车的物品价值
	double up;													//价值上界
	int rw;															//购物车剩余容量
	int id;															//物品编号
	const static int N = 10;
	bool x[N];														//每个状态节点都要保存整个物品序列的放入状况，这一点其实很傻
	ShopBagNodePro();
	ShopBagNodePro(int _cp, double _up, int _rw, int _id);
}SBNodePro;
bool operator <(const ShopBagNodePro &a, const ShopBagNodePro &b);

typedef struct TempShopObject {
	int id;															//物品序号
	double d;														//单位重量价格
}TSObject;

//定义排序优先级，按照物品的单位重量价格由大到小排序
bool cmp(TSObject a1, TSObject a2);				//return a1.d > a2.d


//!!!========使用优先队列实现的0-1背包问题
class ZeroOneBagSpanPro {
private:
	static const int N = 10;
	bool bestx[N];												//最优解向量
	int w[N], v[N];												//辅助数组，用于存储排序后的重量和价值
	Goods goods[N];
	TSObject S[N];
	int bestp;														//最优值
	int W;															//背包最大容量
	int n;																//物品的个数
	int sumw;
	int sumv;
	double Bound(SBNodePro tnode);				//上界计算函数
	int priorbfs();												//使用优先队列的分支限界法实现
public:
	void ZOBSPTest();
};

//6.3使用优先队列广度优先实现的商旅问题
typedef struct TravelingSalesmanNode {						//结点定义，记录当前节点的解信息
	const static int N = 20;
	double cl;														//当前走过的路径长度
	int id;															//节点层号
	int x[N];														//记录当前路径
	TravelingSalesmanNode();
	TravelingSalesmanNode(double _cl, int _id);
}TSNode;

//用于之后把TSNode放入优先队列
bool operator < (const TSNode &a, const TSNode &b);

class TravelingSalesmanSpan {
private:
	const static int INF = 1e7;								//把一个很大的数作为无穷大
	const static int N = 20;
	double g[N][N]	;											//描述经典地图的无向带权图的邻接矩阵
	int bestx[N];													//最优解向量
	double bestl;												//最优解
	int n, m;														//景点个数，边数
	double Travelingbfs();									//使用优先队列的分支限界（广度优先）实现的商旅问题
	void init();
	void print();
	void TSSTest();
public:
	void TSSTest2();
};

//使用费用下界作为优先队列的优先级
typedef struct TsProNode {
	const static int N = 20;
	double cl;																							//当前已走过的路径长度
	double rl;																							//剩余路径长度的下界
	double zl;																							//当前路径长度的下界 zl = cl + rl;
	int id;																								//景点序号
	int x[N];																							//当前节点解向量
	TsProNode();
	TsProNode(double _cl, double _rl, double _zl, int _id);
}TspNode;

bool operator < (const TspNode &a, const TspNode &b);

class TravelingSalesmanSpanPro {
private:
	const static int INF = 1e7;
	const static int N = 20;
	double g[N][N];																				//景点地图的邻接矩阵
	double minout[N];																			//记录每个景点结点的最小出边
	double minsum;																				//记录每个结点的最小出边之和
	int bestx[N];																						//记录当前最优路径
	double	bestl;																					//记录当前最优解
	int n, m;																							//顶点数，边数
	bool Bound();																					//获取下界
	double Travelingbfsopt();
	void Init();
	void print();
public:
	void TSSProTest();
	void TSSProTest2();
};

typedef struct PositionNodeTypedef {
	int x;
	int y;
}Position;

class FindPathSpan {
private:
	const static int N = 20;
	int grid[N][N];
	bool findpath(Position s, Position e, Position *&path, int &Pathlen);						//第三个参数为一个指针的实参(引用)
	void Init(int m, int n);
public:
	void FPSTest();
};





#endif // !__CHAPTER6_H
