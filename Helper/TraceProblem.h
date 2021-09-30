#pragma once

// 2021-07-19@DuoYixian
// ���ļ���Ҫ������һ����������ͨ�ýⷨ��ʵ��

// �Ƚϵ��͵Ļ��ݷ���һ��ȫ�����������
// ��ռ���n����
// ������ʵ����ʵ�ܲ��������Եö�������⣬�����������ͨ

// ���ݷ����
//result = []
//def backtrack(·��, ѡ���б�)
//		if �������������
//			result.add(·��)
//		return
//
//		for ѡ�� in ѡ���б�
//			��ѡ��
//			backtrack(·����ѡ���б�)
//			����ѡ��

template<typename T>
void dkgShow(T arr)
{
	for (const auto & elem : arr)
	{
		cout << elem << " ";
	}
}

// ���ݷ����ȫ�������������
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

	// �˻ʺ��������ݳ�Ա
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


// ��Ŀ��
// �����ܼ�����ֽ�ң���һ��Ӳ�����coins[]������ΪM���������Ƹ����Ϊ{coin1, coin2, coin3, ... coin_n }��Ӳ�ң���ȡ�ܶԻ���VԪ��Ӳ����Ŀ������޷��Ի�����-1

// Given a value V and array coins[] of isze M, the task is to make the change for V cents,given that you have an infinite supply of each of coins{coins1,coins2,...,coinsn}valued coins.
// Find the minimum number of coins to make the change .if not possible to make change then return -1.

// ʾ�����룺
//	30,[25,10,5],3
// ʾ�������
// 2
// 
class CoinProblem {
public:
	CoinProblem();
	void minCoinsTest();
private:
	int min_count;															// ����Ӳ����������
	int count;
	int cur_V;																	// ����Ӳ�Ҽ�ֵ
	int goal_V;																// Ŀ����

	void DFS_greed(int iter,vector<int> &coins, vector<int> &coinCount,  int M);									//	������ȣ�̰�Ĳ���
	int minCoins(int V, vector<int> &coins, int M);
};




// ��վ����
// һάƽ������n����վ�������ҵ�i����վ��λ��Ϊxi���������׻�վϵͳ����������ֵΪ��
// max(x(i+1) - x(i)) (1<=i <= n-1)
// �������ǿ�������n����վ�Ļ���������ڽ���k���µĻ�վ�����ý��ɺ�Ļ�վϵͳ��������ֵ��С��
// ע�⣺�µĻ�վ���ܽ�������n����վ��λ���ϣ�����ֻ�ܽ�������������֮�ϣ�ͬһ��λ�ò��ܽ���������վ��
// ������������һ����������������n��k����ʾ��ǰ��վ����������½���վ������
//					�ڶ�������n���ɿո���뿪������x1 x2 x3 ... xn ��ʾ��ǰn����վ��λ��
// ���磺
//			3 1
//			1 4 5
// ���룺
//			2
// ˵��:
//		��2������һ���»�վ����ʱ��վϵͳ����������ֵΪ:
//		max(2-1,4-2,5-4) = 2,����Сֵ����˴�Ϊ2
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
	// ���Ż���Ŀ�꺯��
private:
	int disturb(vector<int> cur_site);
	int disturb(vector<int> old_site, vector<int> add_site);
	void DFS(int iter);
public:
	void SiteTest();
};



// �ϲ�����
class MergeSortClass {
public:
	void MergeSortTest();
private:
	void Merge(int A[], int low, int mid, int high);
	void MergeSort(int A[], int low, int high);
	void MergeSort2(int A[], int low, int high);


};


