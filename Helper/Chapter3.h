#ifndef __CHAPTER3_H
#define __CHAPTER3_H


//3.2 二分搜索
class BinarySearchTank
{
private:
	static const int M = 10000;
	int s[M];
public:
	int BinarySearch(int n, int s[], int x);
	int RecursionBS(int s[], int x, int low, int high);
	void BinarySearchTest();
	void BinarySearchTestRec();
};

//3.3 合并排序
class MergeSortTank
{
private:
	int n;
	int A[100];
	void Merge(int A[], int low, int mid, int high);
public:
	void MergeSort(int A[], int low, int high);
	void MergeSortTest();
};

//3.3 快速排序
class QuickSortTank {
private:
	int R[1000];
	int n;
	int partition(int r[], int low, int high);
	int partition2(int r[], int low, int high);
public:
	void QuickSort(int R[], int low, int high);
	void QuickSortTest();
};


//3.4 大数乘法
#define M	100
typedef struct BigNumNode{
	int s[M];
	int l;									//长度
	int c;									//幂数
} Node,*pNode;

class BigNumMulTank {
private:
	char sa[1000];
	char sb[1000];
	void cp(pNode src, pNode des, int st, int l);
	void add(pNode pa, pNode pb, pNode ans);
	void mul(pNode pa, pNode pb, pNode ans);
public:
	void BigNumMulTest();
};





#endif // !__CHAPTER3_H
