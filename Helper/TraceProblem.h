#pragma once

// 2021-07-19@DuoYixian
// 本文件主要集中了一类回溯问题的通用解法和实现

// 比较典型的回溯法是一类全排列类的问题
// 解空间是n叉树
// 但是我实践其实很不做，所以得多见几个题，把这个操作搞通

// 回溯法框架
//result = []
//def backtrack(路径, 选择列表)
//		if 满足结束条件：
//			result.add(路径)
//		return
//
//		for 选择 in 选择列表
//			做选择
//			backtrack(路径，选择列表)
//			撤销选择

template<typename T>
void dkgShow(T arr)
{
	for (const auto & elem : arr)
	{
		cout << elem << " ";
	}
}

// 回溯法求解全排列问题的列子
#include<List>
#include<vector>
#include<string>
using std::list;
using std::vector;
using std::string;


list<list<int>> permute(int num[] );
void backtrack(vector<int> numArr, list<int> track);

class fullpremut {
private:
	void dfs_nums(int a[], int k, int n);
	void dfs_nums(vector<int> a, int k, int n);
	void dfs_str(vector<string> strVec_in, string str);
	void dfs_str2(string str_in, string str);
	void dfs_8Queen(int k, int n);
	bool canPlaceAQueen(int row, int col);
	inline char getChOnBoard(int row, int col);
	void SetChOnBoard(int row, int col, char ch);
	void SetQueenOnBoard(int row, int col);
	void SetBlankOnBoard(int row, int col);
	void SetBadPointOnBoard(char ch);
	void showChessBoard();
public:
	void numArr2strSet();
	void Test_dfs_nums();
	void Test_dfs_str();
	void Test_dfs_8Queen();
private:
	int count = 0;
	vector<string> strVec_out;
	vector<string> strVec_in;
	void swap(int & a, int &b);
	template<typename T> void ShowAll(T Arr);

	// 八皇后问题数据成员
	vector<string> chessboard;
	char blank = '-';
	char Queen = 'Q';
	bool b_Show8QueenResult = false;

};
 
template<typename T>
inline void fullpremut::ShowAll(T Arr)
{
	for (const auto elem : Arr)
	{
		cout << elem << endl;
	}
}


// 题目：
// 给出总计面额的纸币，和一组硬币面额coins[]，长度为M，有无限制个面额为{coin1, coin2, coin3, ... coin_n }的硬币，获取能对换出V元的硬币数目。如果无法对话返回-1

// Given a value V and array coins[] of isze M, the task is to make the change for V cents,given that you have an infinite supply of each of coins{coins1,coins2,...,coinsn}valued coins.
// Find the minimum number of coins to make the change .if not possible to make change then return -1.

// 示例输入：
//	30,[25,10,5],3
// 示例输出：
// 2
// 
class CoinProblem {
public:
	CoinProblem();
	void minCoinsTest();
private:
	int min_count;															// 最少硬币数量计数
	int count;
	int cur_V;																	// 当期硬币价值
	int goal_V;																// 目标金额

	void DFS_greed(int iter,vector<int> &coins, vector<int> &coinCount,  int M);									//	深度优先，贪心策略
	int minCoins(int V, vector<int> &coins, int M);
};




// 基站问题
// 一维平面上有n个基站，从左到右第i个基站的位置为xi，定义整套基站系统的噪声干扰值为：
// max(x(i+1) - x(i)) (1<=i <= n-1)
// 现在我们可以在这n个基站的基础上最多在建立k个新的基站，想让建成后的基站系统噪声干扰值最小。
// 注意：新的基站不能建立在这n个基站的位置上，并且只能建立在整数坐标之上，同一个位置不能建立两个基站。
// 输入描述：第一行输入两个正整数n和k，表示当前基站个数和最多新建基站个数。
//					第二行输入n个由空格隔离开的整数x1 x2 x3 ... xn 表示当前n个基站的位置
// 例如：
//			3 1
//			1 4 5
// 输入：
//			2
// 说明:
//		在2处建立一个新基站，此时基站系统的噪声干扰值为:
//		max(2-1,4-2,5-4) = 2,是最小值，因此答案为2
class SiteProblem {
public:
	SiteProblem();
private:
	vector<int> oldsite;
	vector<int> cursite;
	vector<int> goalsite;
	int n;
	int k;
	int min_noise;
	// 待优化的目标函数
private:
	int disturb(vector<int> cur_site);
	int disturb(vector<int> old_site, vector<int> add_site);
	void DFS(int iter);
public:
	void SiteTest();
};



// 合并排序
class MergeSortClass {
public:
	void MergeSortTest();
private:
	void Merge(int A[], int low, int mid, int high);
	void MergeSort(int A[], int low, int high);
	void MergeSort2(int A[], int low, int high);


};


