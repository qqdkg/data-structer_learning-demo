#ifndef __CHAPTER5
#define __CHAPTER5

/*
*《趣学算法》第五章，回溯法的实例
*/


//背包问题（Knapasck Problem）
//0-1背包问题的回溯法实现
class ZOPackBacktrackTank {
private:
	static const int M = 105;
	int i, j, n, W;														//n表示n件物品，W表示购物车总容量
	double w[M], v[M];											//w[i]表示第i个物品的重量，v[i]表示第i个物品的价值
	bool x[M];															//x[i]表示第i件物品是否被放入背包的状态
	double cw;														//当前重量
	double cp;														//当前价值
	double bestp;													//当前最优价值
	bool bestx[M];													//当前最优解
	double Bound(int i);											//计算上界
	void Backtrack(int t);											//回溯法实现
	void Knapsack(double W, int n);						//增加一些判断和输入输出
public:
	void ZOPBTest();												//面向外界的测试接口
};



#endif // !__CHAPTER5

