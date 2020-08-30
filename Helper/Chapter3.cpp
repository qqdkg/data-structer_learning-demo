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


//4.3 最长公共子序列
void LCSTank::LCSL()
{
	int i, j;
	for (i = 1; i <= len1; i++)			//控制s1序列
		for (j = 1; j <= len2; j++)		//控制s2序列
		{
			if (s1[i - 1] == s2[j - 1])
			{										//如果当前字符相同，则公共子序列的长度为该字符前的最长公共序列+1
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else
			{
				if (c[i][j - 1] >= c[i - 1][j])
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = 2;
				}
				else
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = 3;
				}
			}//for j
		}//for i
}//LCSL

void LCSTank::print(int i, int j)
{
	if (i == 0 || j == 0) return;
	if (b[i][j] == 1)
	{
		print(i - 1, j - 1);
		cout << s1[i - 1];
	}
	else if (b[i][j] == 2)
		print(i, j - 1);
	else
		print(i - 1, j);
}

void LCSTank::printTest()
{
	int i, j;
	cout << "请输入字符串s1：" << endl;
	cin >> s1;
	cout << "请输入字符串s2：" << endl;
	cin >> s2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	for (i = 0; i <= len1; i++)
	{
		c[i][0] = 0;				//初始化第一列
	}
	for (j = 0; j <= len2; j++)
	{
		c[0][j] = 0;				//初始化第一行
	}
	LCSL();
	cout << "s1和s2的最长公共子序列的长度是：" << c[len1][len2] << endl;
	cout << "s1和s2的最长公共子序列为：";
	print(len1, len2);
	cout << endl;
}

//4.4 编辑距离
int EditDistanceTank::min(int a, int b)
{
	return a < b ? a : b;
}

int EditDistanceTank::editdistance(char * str1, char * str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i <= len1; i++)
		d[i][0] = i;												//初始化第0列
	for (int j = 0; j <= len2; j++)
		d[0][j] = j;												//初始化第0列

	for (int i = 1; i <= len1; i++)
		for (int j = 1; j <= len2; j++)					//遍历两个字符串
		{
			int diff;												//用于判断str1[i] 与 str2[j]是否相等，相等为0，不等为1
			if (str1[i - 1] == str2[j - 1])
				diff = 0;
			else
				diff = 1;
			int temp = min(d[i - 1][j] + 1, d[i][j - 1] + 1);
			d[i][j] = min(temp, d[i - 1][j - 1] + diff);										
																	//这是由子问题分析得到的递推操作，想不起来可以看去学算法4.4
			
			if (d[i][j] == d[i - 1][j - 1] + diff)		//个点行为
				p[i][j] = 3;										//行为为向左上
			else if (d[i][j] == d[i - 1][j] + 1)
				p[i][j] = 2;										//行为为向上
			else
				p[i][j] = 1;										//行为为向左
		}
	return d[len1][len2];
}

void EditDistanceTank::print(int i, int j)
{
	if (i == 0 || j == 0)
		return;

	if (p[i][j] == 1)
	{
		cout << "向左" << " ";
		print(i, j - 1);
	}
	else if (p[i][j] == 2)
	{
		cout << "向上" << " ";
		print(i - 1, j);
	}
	else
	{
		cout << "向左上" << " ";
		print(i - 1, j - 1);
	}
}

void EditDistanceTank::editDistanceTest()
{
	cout << "请输入字符串str1：" << endl;
	cin >> str1;
	cout << "请输入字符串str2：" << endl;
	cin >> str2;
	cout << str1 << "和" << str2 << "的编辑距离为：" << editdistance(str1, str2) << endl;
	cout << "最优解行为：" << endl;
	print(strlen(str1), strlen(str2));
	cout << endl;
}

void RentBoatTank::rent()
{
	int i, j, k, d;
	for (d = 3; d <= n; d++)
	{
		for (i = 1; i <= n - d + 1; i++)
		{
			j = i + d - 1;
			for (k = i + 1; k < j; k++)
			{
				int temp;
				temp = m[i][k] + m[k][j];
				if (temp < m[i][j])
				{
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
}

void RentBoatTank::print(int i, int j)
{
	if (s[i][j] == 0)
	{
		cout << "--" << j;
		return;
	}
	print(i, s[i][j]);
	print(s[i][j], j);
}

void RentBoatTank::RentBoatTest()
{
	int i, j;
	int rArr[] = {2, 6, 9, 15, 20, 3, 5, 11, 18, 3, 6, 12, 5, 8, 6};
	int rCount = 0;
	cout << "请输入站点个数n：";
	//cin >> n;
	n = 6;
	cout << n << endl;

	cout << "请依次输入各站点间的租金：" << endl;
	for(i = 1; i <=n; i++)
		for (j = i + 1; j <= n; ++j)
		{
			//cin >> r[i][j];
			r[i][j] = rArr[rCount++];
			cout << r[i][j] << " ";
			m[i][j] = r[i][j];
			s[i][j] = 0;
		}
	cout << endl;
	rent();
	cout << "花费的最少租金为：" << m[1][n] << endl;
	cout << "最少租金经过站点：" << 1;
	print(1, n);
}

void MatrixChainTank::matrixchain()
{
	int i, j, r, k;
	memset(m, 0, sizeof(m));
	memset(s, 0, sizeof(s));
	for (r = 2; r <= n; r++)							//不同规模的子问题
	{
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];							//决策为k == i的乘法次数
			s[i][j] = i;
			for (k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}//if
			}//for k
		}//for i
	}//for r
}

void MatrixChainTank::print(int i, int j)
{
	if (i == j)
	{
		cout << "A[" << i << "]";
		return;
	}
	cout << "(";
	print(i, s[i][j]);
	print(s[i][j] + 1, j);
	cout << ")";
}

void MatrixChainTank::MatrixChainTest()
{
	cout << "请输入矩阵个数n：";
	cin >> n;
	cout << "请依次输入每个矩阵的行数和最后一个矩阵的列数：" << endl;
	for (int i = 0; i <= n; i++)
		cin >> p[i];
	matrixchain();
	print(1, n);
	cout << endl;
	cout << "最小计算量的值为：" << m[1][n] << endl;
}

void TrangleDivideTank::trangleDivide()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			m[i][j] = 0;
			s[i][j] = 0;
		}
	}
	for (int d = 2; d <= n; d++)									//d代表问题规模，d == 2时实际上表示三个点因为m[i][j]表示{Vi-1.Vi,Vj}
		for (int i = 1; i <= n - d + 1; i++)
		{
			int j = i + d - 1;
			m[i][j] = m[i + 1][j] + g[i - 1][i] + g[i][j] + g[i - 1][j];						//用m[i][j]可能的最大值作为初值
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				double temp = m[i][k] + m[k + 1][j] + g[i - 1][k] + g[i - 1][j] + g[k][j];
				if (m[i][j] > temp)
				{
					m[i][j] = temp;																		//更新最优数值
					s[i][j] = k;																				//记录策略
				}
			}//for k
		}// for i
}

void TrangleDivideTank::print(int i, int j)
{
	if (i == j) return;
	if (s[i][j] > i)
		cout << "{v" << i - 1 << "v" << s[i][j] << "}" << endl;
	if (j > s[i][j] + 1)
		cout << "{v" << s[i][j] << "v" << j << "}" << endl;
	print(i, s[i][j]);
	print(s[i][j] + 1, j);
}

void TrangleDivideTank::trangleDivideTest()
{
	int i, j;
	int gMat[6][6] = { {0, 2, 3, 1, 5, 6},
								{2, 0, 3, 4, 8, 6},
								{3, 3, 0, 10, 13, 7},
								{1, 4, 10, 0, 12, 5},
								{5, 8, 13, 12, 0, 3},
								{6, 6, 7, 5, 3, 0} };

	cout << "请输入顶点个数n：";
	//cin >> n;
	n = 6;
	cout << n << endl;
	n--;
	cout << "请依次输入各顶点链接权值：" << endl;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			//cin >> g[i][j];
			g[i][j] = gMat[i][j];
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	trangleDivide();
	cout << m[1][n] << endl;
	print(1, n);
}

void CombineStoneTank::straight(int a[], int n)
{
	for (int i = 1; i <= n; i++)							//初始化
	{
		Min[i][i] = 0;
		Max[i][i] = 0;
	}
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int v = 2; v <= n; v++)						//枚举合并堆数的规模
	{
		for (int i = 1; i <= n - v + 1; i++)			//枚举起点i
		{
			int j = i + v - 1;									//枚举终点j
			Min[i][j] = INF;									//初始化为最大值
			Max[i][j] = -1;									//初始化为-1
			int temp = sum[j] - sum[i - 1];			//记录i...j之间的石子数目之和
			for (int k = i; k < j; k++)					//枚举中间分隔点
			{
				Min[i][j] = min(Min[i][j], Min[i][k] + Min[k + 1][j] + temp);
				Max[i][j] = max(Max[i][j], Max[i][k] + Max[k + 1][j] + temp);
			}//for k
		}//for i
	}//for v
}

void CombineStoneTank::Circular(int a[], int n)
{
	for (int i = 1; i <= n - 1; i++)
		a[n + i] = a[i];
	n = 2 * n - 1;
	straight(a, n);
	n = (n + 1) / 2;
	min_Circular = Min[1][n];
	max_Circular = Max[1][n];
	for (int i = 2; i <= n; i++)
	{
		if (Min[i][n + i - 1] < min_Circular)
			min_Circular = Min[i][n + i - 1];
		if (Max[i][n + i - 1] > max_Circular)
			max_Circular = Max[i][n + i - 1];
	}
}

void CombineStoneTank::CSTTest()
{
	int n;
	cout << "请输入石子堆数n" << endl;
	cin >> n;
	cout << "请输入各堆的石子数目" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	straight(a, n);
	cout << "路边玩法（直线型）的最小花费为：" << Min[1][n] << endl;
	cout << "路边玩法（直线型）的最大花费为：" << Max[1][n] << endl;
	Circular(a, n);
	cout << "操场玩法（圆形）的最小花费为：" << min_Circular << endl;
	cout << "操场玩法（圆形）的最大花费为：" << max_Circular << endl;
}


