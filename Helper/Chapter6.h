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







#endif // !__CHAPTER6_H
