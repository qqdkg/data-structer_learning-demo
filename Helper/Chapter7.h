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



#endif // !__CHAPTER3_H_
