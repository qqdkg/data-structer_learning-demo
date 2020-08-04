#ifndef __CHAPTER3_H
#define __CHAPTER3_H


//3.2 ��������
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

//3.3 �ϲ�����
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

//3.3 ��������
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


//3.4 �����˷�
#define M	100
typedef struct BigNumNode{
	int s[M];
	int l;									//����
	int c;									//����
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


//4.3 �����������
class LCSTank {
private:
	static const int N = 100;
	int c[N][N];
	int b[N][N];
	char s1[N];
	char s2[N];
	int len1, len2;
	void LCSL();
	void print(int i, int j);
public:
	void printTest();
} ;

//4.4 �༭����
class EditDistanceTank {
private:
	static const int N = 100;
	char str1[N], str2[N];
	int d[N][N];									//������ʾstr1��i���ַ���str2��j���ַ�֮��ı༭����
	int p[N][N];									//·�߼�¼����p����path�����ڷ�����Ϊ
	int min(int a, int b);
public:
	int editdistance(char *str1, char *str2);
	void print(int i,int j);
	void editDistanceTest();
};




#endif // !__CHAPTER3_H
