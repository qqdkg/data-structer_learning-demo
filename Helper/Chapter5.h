#ifndef __CHAPTER5
#define __CHAPTER5

/*
*《趣学算法》第五章，回溯法的实例
*/


//背包问题（Knapasck Problem）
//0-1背包问题的回溯法实现

struct ObjectNode														//定义物品结构体，包含物品的序号和单位重量价值
{
	int id;																//物品序号
	double d;															//单位重量价值
};

bool cmp(ObjectNode a1, ObjectNode a2);

class ZOPackBacktrackTank {
private:
	/*数据成员*/
	static const int M = 105;
	int i, j, n, W;														//n表示n件物品，W表示购物车总容量
	double w[M], v[M];											//w[i]表示第i个物品的重量，v[i]表示第i个物品的价值
	bool x[M];															//x[i]表示第i件物品是否被放入背包的状态
	double cw;														//当前重量
	double cp;														//当前价值
	double bestp;													//当前最优价值
	bool bestx[M];													//当前最优解
	/*函数成员*/
	double Bound(int i);											//计算上界
	double BoundPro(int i);									//优化版本的上界限界函数，增加剪枝概率
	void Backtrack(int t);											//回溯法实现
	void Knapsack(double W, int n);						//增加一些判断和输入输出
	void KnapsackPro(double W, int n);					//又换版本低主执行函数，主要对于输入数据做了排序。
public:
	void ZOPBTest();												//面向外界的测试接口
	void ZOPBTestPro();
};

//部落护卫队（最大团问题）
class BigestRollTank {
private:
	static const int N = 100;
	int a[N][N];														//用邻接矩阵表示的图
	bool x[N];															//是否将第i个结点加入团中
	bool bestx[N];													//记录最优值
	int bestn;															//记录最优值
	int cn;																//当前已放入团中的节点数量
	int n, m;															//n为图中的结点数，m为图中的边数
	bool Place(int t);
	void Backtrack(int t);
public:
	void BigestRollTest();
};

//地图着色问题（解的组织结构为一颗m叉数）
class ColorMapQuesTank {
private:
	static const int Mx = 50;
	int x[Mx];															//解向量（元组）
	int map[Mx][Mx];												//图的邻接矩阵
	int sum = 0;														//记录解的个数的变量
	int n, m, edge;													//节点数，颜色数，边数
	void CreatMap();												//创建”连通无向图“的邻接矩阵
	bool OK(int t);													//约束条件
	void Backtrack(int t);											//搜索函数
public:
	void CMQTest();
};

#endif // !__CHAPTER5

