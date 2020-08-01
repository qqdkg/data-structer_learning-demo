#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "Chapter3.h"
using namespace std;

int BinarySearchTank::BinarySearch(int n, int s[], int x)
{
	int low = 0, high = n - 1;						//low指向数组的第一个元素，high指向数组的最后一个元素
	while (low <= high)
	{
		int middle = (low + high) / 2;			//middle为查找范围的中间值
		if (x == s[middle])
			return middle;
		else if (x < s[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;
}

int BinarySearchTank::RecursionBS(int s[], int x, int low, int high)
{
	//low 指向数组的第一个元素，high指向数组的最后一个元素
	if (low > high)										//递归条件
		return -1;
	int middle = (low + high) / 2;				//计算中间值
	if (x == s[middle])
		return middle;
	else if (x < s[middle])
		return RecursionBS(s, x, low, middle - 1);
	else
		return RecursionBS(s, x, middle + 1, high);
}

void BinarySearchTank::BinarySearchTest()
{
	int n;
	int x;
	int ans;
	cout << "请输入列表中的元素个数n：";
	cin >> n;
	cout << "请依次输入数列中的元素：";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	cout << "排序之后的数组为：";
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "请输入要查询的元素：";
	cin >> x;
	ans = BinarySearch(n, s, x);
	if (ans == -1)
		cout << "该数列中没有要查询到元素" << endl;
	else
		cout << "找到查询的元素在第" << ans + 1 << "位" << endl;

	cout << endl;
}

void BinarySearchTank::BinarySearchTestRec()
{
	int n;
	int x;
	int ans;
	cout << "请输入列表中的元素个数n：";
	cin >> n;
	cout << "请依次输入数列中的元素：";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	cout << "排序之后的数组为：";
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "请输入要查询的元素：";
	cin >> x;
	ans = RecursionBS(s, x, 0, n-1);
	if (ans == -1)
		cout << "该数列中没有要查询到元素" << endl;
	else
		cout << "找到查询的元素在第" << ans + 1 << "位" << endl;

	cout << endl;
}

//3.2 合并排序
void MergeSortTank::Merge(int A[], int low, int mid, int high)
{
	int *B = new int[high - low + 1];									//申请辅助数组
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high)
	{
		if (A[i] <= A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	while (i <= mid) B[k++] = A[i++];								//将剩下的元素放入辅助数组
	while (j <= high) B[k++] = A[j++];
	for (i = low, k = 0; i <= high; i++)
		A[i] = B[k++];
	delete []B;
}

void MergeSortTank::MergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;				//取中点
		MergeSort(A, low, mid);					//对于A[low,mid]之间的元素合并排序
		MergeSort(A, mid + 1, high);			//对于A[mid + 1, high]之间的元素合并排序
		Merge(A, low, mid, high);					//合并
	}
}

void MergeSortTank::MergeSortTest()
{
	cout << "请输入元素个数n：" << endl;
	cin >> n;
	int xArr[] = { 42, 15, 20,6, 8, 38, 50, 12 };
	cout << "请依次输入数组中的元素：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	MergeSort(A, 0, n - 1);
	cout << "输出排序结果：" << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

int QuickSortTank::partition(int r[], int low, int high)
{
	int i = low, j = high, privot = r[low];					//基准元素
	while (i < j)
	{
		while (i < j && r[j] > privot)								//向左移动
			j--;
		if (i < j)
			swap(r[i++], r[j]);											//r[i],r[j]交换，i右移一位
		while (i < j && r[i] < privot)								//向右移动
			i++;
		if (i < j)
			swap(r[i], r[j--]);											//r[i],r[j]交换，j左移一位
	}
	return i;																//返回最终完成划分之后的基准元素所在位置
}

int QuickSortTank::partition2(int r[], int low, int high)
{
	int i = low, j = high, privot = r[low];
	while (i < j)
	{
		while (i < j && r[j] > privot)								//向左扫描
			j--;
		while (i < j && r[i] < privot)								//向右扫描
			i++;
		if (i < j)
			swap(r[i++], r[j--]);
	}
	if (r[i] > privot)
	{
		swap(r[i - 1], r[low]);
		return i - 1;
	}
	swap(r[i], r[low]);
	return i;
}

void QuickSortTank::QuickSort(int R[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = partition2(R, low, high);								//基准位置
		QuickSort(R, low, mid - 1);									//左侧区间快速排序
		QuickSort(R, mid + 1, high);									//右侧区间快速排序
	}
}

void QuickSortTank::QuickSortTest()
{
	int i;
	cout << "请输入要排序的数据个数n：" << endl;
	cin >> n;
	cout << "请输入要排序的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> R[i];
	}
	QuickSort(R, 0, n-1);
	cout << "排序后的数据为：" << endl;
	for (int i = 0; i < n; i++)
		cout << R[i] << " " ;
	cout << endl;
}


//3.5 大数乘法
void BigNumMulTank::cp(pNode src, pNode des, int st, int l)
{
	int i, j;
	for (i = st, j = 0; i < st +l; i++, j++)
	{
		des->s[j] = src->s[i];
	}
	des->l = l;
	des->c = st + src->c;												//幂次
}

void BigNumMulTank::add(pNode pa, pNode pb, pNode ans)
{
	int i, cc, k, palen, pblen, len;
	int ta, tb;
	pNode temp;
	if ((pa->c < pb->c))																//保证pa最大
	{
		temp = pa;
		pa = pb;
		pb = temp;
	}
	ans->c = pb->c;
	cc = 0;
	palen = pa->l + pa->c;
	pblen = pb->l + pb->c;
	if (palen > pblen)
		len = palen;
	else
		len = pblen;
	k = pa->c - pb->c;
	for (i = 0; i < len - ans->c; i++)									//结果的长度为pa，pb之中的最大长度减去最低次幂
	{
		if (i < k)
			ta = 0;
		else
			ta = pa->s[i - k];
		if (i < pb->l)
			tb = pb->s[i];
		else
			tb = 0;
		if (i >= pa->l + k)
			ta = 0;
		ans->s[i] = (ta + tb + cc) % 10;
		cc = (ta + tb + cc) / 10;
	}
	if (cc)
	{
		ans->s[i++] = cc;													//处理进位
	}
	ans->l = i;
}

void BigNumMulTank::mul(pNode pa, pNode pb, pNode ans)
{
	int i, cc, w;
	int ma = pa->l >> 1;									//位运算右移相当于除以二
	int mb = pb->l >> 1;
	Node ah, al, bh, bl;
	Node t1, t2, t3, t4, z;
	pNode temp;
	if (!ma || !mb)												//其中有一个数位数为1:既ma == 0 或 mb == 0
	{
		if (!ma)
		{
			temp = pa;
			pa = pb;
			pb = temp;
		}
		ans->c = pa->c + pb->c;
		w = pb->s[0];
		cc = 0;														//此时进位为c
		for (i = 0; i < pa->l; i++)
		{
			ans->s[i] = (w*pa->s[i] + cc) % 10;
			cc = (w*pa->s[i] + cc) / 10;
		}
		if (cc)
			ans->s[i++] = cc;
		ans->l = i;
		return;
	}
	//分治核心
	cp(pa, &ah, ma, pa->l - ma);						//先分成四部分 ah al bh bl
	cp(pa, &al, 0, ma);
	cp(pb, &bh, mb, pb->l - mb);
	cp(pb, &bl, 0, mb);

	mul(&ah, &bh, &t1);
	mul(&ah, &bl, &t2);
	mul(&al, &bh, &t3);
	mul(&al, &bl, &t4);

	add(&t3, &t4, ans);
	add(&t2, ans, &z);
	add(&t1, &z, ans);
}

void BigNumMulTank::BigNumMulTest()
{
	Node ans, a, b;
	cout << "请输入大整数a：" << endl;
	cin >> sa;
	cout << "请输入打整数b：" << endl;
	cin >> sb;
	a.l = strlen(sa);
	b.l = strlen(sb);
	int z = 0, i;
	for (i = a.l - 1; i >= 0; i--)
		a.s[z++] = sa[i] - '0';								//倒向存储
	a.c = 0;
	z = 0;
	for (i = b.l - 1; i >= 0; i--)
		b.s[z++] = sb[i] - '0';
	b.c = 0;
	mul(&a, &b, &ans);
	cout << "最终结果为：";
	for (i = ans.l - 1; i >= 0; i--)
		cout << ans.s[i];									//ans用来存储结果倒向存储
	cout << endl;
}




