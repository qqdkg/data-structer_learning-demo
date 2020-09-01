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
	int editdistance(char *str1, char *str2);
	void print(int i, int j);
public:
	void editDistanceTest();
};

//4.5 ��ͧ��������
class RentBoatTank {
private:
	static const int ms = 100;
	int r[ms][ms];
	int m[ms][ms];
	int s[ms][ms];
	int n;												//����n��վ��
	void rent();
	void print(int i, int j);
public:
	void RentBoatTest();
};

//4.6 ������������
class MatrixChainTank {
private:
	static const int msize = 100;
	int p[msize];
	int m[msize][msize], s[msize][msize];
	int n;
	void matrixchain();
	void print(int i, int j);
public:
	void MatrixChainTest();
};

//4.7 ���������ʷ�
class TrangleDivideTank {
private:
    static const int misze = 100;
	int n;
	int m[misze][misze], g[misze][misze];
	int s[misze][misze];
	void trangleDivide();
	void print(int i, int j);
public:
	void trangleDivideTest();
};

//4.8 ʯ�Ӻϲ�
class CombineStoneTank {
private:
	static const int INF = 1 << 30;
	static const int N = 205;
	int Min[N][N];
	int Max[N][N];
	int sum[N];
	int a[N];
	int min_Circular, max_Circular;
	void straight(int a[], int n);
	void Circular(int a[], int n);
public:
	void CSTTest();
};

//ʹ�����ı߲���ʽ�Ż��Ľ��
class CombineStoneTankPro {
private:
	static const int INF = 1 << 30;
	static const int N = 205;
	int Min[N][N];
	int Max[N][N];
	int s[N][N];
	int sum[N];
	int a[N];
	int min_Circular, max_Circular;
	void Get_Min(int n);
	void Get_Max(int n);
	void straight(int a[], int n);
	void Circular(int a[], int n);
public:
	void CSTPTest();
};




#endif // !__CHAPTER3_H
