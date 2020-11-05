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



#endif // !__CHAPTER3_H_
