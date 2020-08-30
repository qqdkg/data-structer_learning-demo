#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "Chapter3.h"
using namespace std;

int BinarySearchTank::BinarySearch(int n, int s[], int x)
{
	int low = 0, high = n - 1;						//lowָ������ĵ�һ��Ԫ�أ�highָ����������һ��Ԫ��
	while (low <= high)
	{
		int middle = (low + high) / 2;			//middleΪ���ҷ�Χ���м�ֵ
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
	//low ָ������ĵ�һ��Ԫ�أ�highָ����������һ��Ԫ��
	if (low > high)										//�ݹ�����
		return -1;
	int middle = (low + high) / 2;				//�����м�ֵ
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
	cout << "�������б��е�Ԫ�ظ���n��";
	cin >> n;
	cout << "���������������е�Ԫ�أ�";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	cout << "����֮�������Ϊ��";
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "������Ҫ��ѯ��Ԫ�أ�";
	cin >> x;
	ans = BinarySearch(n, s, x);
	if (ans == -1)
		cout << "��������û��Ҫ��ѯ��Ԫ��" << endl;
	else
		cout << "�ҵ���ѯ��Ԫ���ڵ�" << ans + 1 << "λ" << endl;

	cout << endl;
}

void BinarySearchTank::BinarySearchTestRec()
{
	int n;
	int x;
	int ans;
	cout << "�������б��е�Ԫ�ظ���n��";
	cin >> n;
	cout << "���������������е�Ԫ�أ�";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	cout << "����֮�������Ϊ��";
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "������Ҫ��ѯ��Ԫ�أ�";
	cin >> x;
	ans = RecursionBS(s, x, 0, n-1);
	if (ans == -1)
		cout << "��������û��Ҫ��ѯ��Ԫ��" << endl;
	else
		cout << "�ҵ���ѯ��Ԫ���ڵ�" << ans + 1 << "λ" << endl;

	cout << endl;
}

//3.2 �ϲ�����
void MergeSortTank::Merge(int A[], int low, int mid, int high)
{
	int *B = new int[high - low + 1];									//���븨������
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
	while (i <= mid) B[k++] = A[i++];								//��ʣ�µ�Ԫ�ط��븨������
	while (j <= high) B[k++] = A[j++];
	for (i = low, k = 0; i <= high; i++)
		A[i] = B[k++];
	delete []B;
}

void MergeSortTank::MergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;				//ȡ�е�
		MergeSort(A, low, mid);					//����A[low,mid]֮���Ԫ�غϲ�����
		MergeSort(A, mid + 1, high);			//����A[mid + 1, high]֮���Ԫ�غϲ�����
		Merge(A, low, mid, high);					//�ϲ�
	}
}

void MergeSortTank::MergeSortTest()
{
	cout << "������Ԫ�ظ���n��" << endl;
	cin >> n;
	int xArr[] = { 42, 15, 20,6, 8, 38, 50, 12 };
	cout << "���������������е�Ԫ�أ�" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	MergeSort(A, 0, n - 1);
	cout << "�����������" << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

int QuickSortTank::partition(int r[], int low, int high)
{
	int i = low, j = high, privot = r[low];					//��׼Ԫ��
	while (i < j)
	{
		while (i < j && r[j] > privot)								//�����ƶ�
			j--;
		if (i < j)
			swap(r[i++], r[j]);											//r[i],r[j]������i����һλ
		while (i < j && r[i] < privot)								//�����ƶ�
			i++;
		if (i < j)
			swap(r[i], r[j--]);											//r[i],r[j]������j����һλ
	}
	return i;																//����������ɻ���֮��Ļ�׼Ԫ������λ��
}

int QuickSortTank::partition2(int r[], int low, int high)
{
	int i = low, j = high, privot = r[low];
	while (i < j)
	{
		while (i < j && r[j] > privot)								//����ɨ��
			j--;
		while (i < j && r[i] < privot)								//����ɨ��
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
		mid = partition2(R, low, high);								//��׼λ��
		QuickSort(R, low, mid - 1);									//��������������
		QuickSort(R, mid + 1, high);									//�Ҳ������������
	}
}

void QuickSortTank::QuickSortTest()
{
	int i;
	cout << "������Ҫ��������ݸ���n��" << endl;
	cin >> n;
	cout << "������Ҫ��������ݣ�" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> R[i];
	}
	QuickSort(R, 0, n-1);
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < n; i++)
		cout << R[i] << " " ;
	cout << endl;
}


//3.5 �����˷�
void BigNumMulTank::cp(pNode src, pNode des, int st, int l)
{
	int i, j;
	for (i = st, j = 0; i < st +l; i++, j++)
	{
		des->s[j] = src->s[i];
	}
	des->l = l;
	des->c = st + src->c;												//�ݴ�
}

void BigNumMulTank::add(pNode pa, pNode pb, pNode ans)
{
	int i, cc, k, palen, pblen, len;
	int ta, tb;
	pNode temp;
	if ((pa->c < pb->c))																//��֤pa���
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
	for (i = 0; i < len - ans->c; i++)									//����ĳ���Ϊpa��pb֮�е���󳤶ȼ�ȥ��ʹ���
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
		ans->s[i++] = cc;													//�����λ
	}
	ans->l = i;
}

void BigNumMulTank::mul(pNode pa, pNode pb, pNode ans)
{
	int i, cc, w;
	int ma = pa->l >> 1;									//λ���������൱�ڳ��Զ�
	int mb = pb->l >> 1;
	Node ah, al, bh, bl;
	Node t1, t2, t3, t4, z;
	pNode temp;
	if (!ma || !mb)												//������һ����λ��Ϊ1:��ma == 0 �� mb == 0
	{
		if (!ma)
		{
			temp = pa;
			pa = pb;
			pb = temp;
		}
		ans->c = pa->c + pb->c;
		w = pb->s[0];
		cc = 0;														//��ʱ��λΪc
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
	//���κ���
	cp(pa, &ah, ma, pa->l - ma);						//�ȷֳ��Ĳ��� ah al bh bl
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
	cout << "�����������a��" << endl;
	cin >> sa;
	cout << "�����������b��" << endl;
	cin >> sb;
	a.l = strlen(sa);
	b.l = strlen(sb);
	int z = 0, i;
	for (i = a.l - 1; i >= 0; i--)
		a.s[z++] = sa[i] - '0';								//����洢
	a.c = 0;
	z = 0;
	for (i = b.l - 1; i >= 0; i--)
		b.s[z++] = sb[i] - '0';
	b.c = 0;
	mul(&a, &b, &ans);
	cout << "���ս��Ϊ��";
	for (i = ans.l - 1; i >= 0; i--)
		cout << ans.s[i];									//ans�����洢�������洢
	cout << endl;
}


//4.3 �����������
void LCSTank::LCSL()
{
	int i, j;
	for (i = 1; i <= len1; i++)			//����s1����
		for (j = 1; j <= len2; j++)		//����s2����
		{
			if (s1[i - 1] == s2[j - 1])
			{										//�����ǰ�ַ���ͬ���򹫹������еĳ���Ϊ���ַ�ǰ�����������+1
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
	cout << "�������ַ���s1��" << endl;
	cin >> s1;
	cout << "�������ַ���s2��" << endl;
	cin >> s2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	for (i = 0; i <= len1; i++)
	{
		c[i][0] = 0;				//��ʼ����һ��
	}
	for (j = 0; j <= len2; j++)
	{
		c[0][j] = 0;				//��ʼ����һ��
	}
	LCSL();
	cout << "s1��s2������������еĳ����ǣ�" << c[len1][len2] << endl;
	cout << "s1��s2�������������Ϊ��";
	print(len1, len2);
	cout << endl;
}

//4.4 �༭����
int EditDistanceTank::min(int a, int b)
{
	return a < b ? a : b;
}

int EditDistanceTank::editdistance(char * str1, char * str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i <= len1; i++)
		d[i][0] = i;												//��ʼ����0��
	for (int j = 0; j <= len2; j++)
		d[0][j] = j;												//��ʼ����0��

	for (int i = 1; i <= len1; i++)
		for (int j = 1; j <= len2; j++)					//���������ַ���
		{
			int diff;												//�����ж�str1[i] �� str2[j]�Ƿ���ȣ����Ϊ0������Ϊ1
			if (str1[i - 1] == str2[j - 1])
				diff = 0;
			else
				diff = 1;
			int temp = min(d[i - 1][j] + 1, d[i][j - 1] + 1);
			d[i][j] = min(temp, d[i - 1][j - 1] + diff);										
																	//����������������õ��ĵ��Ʋ������벻�������Կ�ȥѧ�㷨4.4
			
			if (d[i][j] == d[i - 1][j - 1] + diff)		//������Ϊ
				p[i][j] = 3;										//��ΪΪ������
			else if (d[i][j] == d[i - 1][j] + 1)
				p[i][j] = 2;										//��ΪΪ����
			else
				p[i][j] = 1;										//��ΪΪ����
		}
	return d[len1][len2];
}

void EditDistanceTank::print(int i, int j)
{
	if (i == 0 || j == 0)
		return;

	if (p[i][j] == 1)
	{
		cout << "����" << " ";
		print(i, j - 1);
	}
	else if (p[i][j] == 2)
	{
		cout << "����" << " ";
		print(i - 1, j);
	}
	else
	{
		cout << "������" << " ";
		print(i - 1, j - 1);
	}
}

void EditDistanceTank::editDistanceTest()
{
	cout << "�������ַ���str1��" << endl;
	cin >> str1;
	cout << "�������ַ���str2��" << endl;
	cin >> str2;
	cout << str1 << "��" << str2 << "�ı༭����Ϊ��" << editdistance(str1, str2) << endl;
	cout << "���Ž���Ϊ��" << endl;
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
	cout << "������վ�����n��";
	//cin >> n;
	n = 6;
	cout << n << endl;

	cout << "�����������վ�������" << endl;
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
	cout << "���ѵ��������Ϊ��" << m[1][n] << endl;
	cout << "������𾭹�վ�㣺" << 1;
	print(1, n);
}

void MatrixChainTank::matrixchain()
{
	int i, j, r, k;
	memset(m, 0, sizeof(m));
	memset(s, 0, sizeof(s));
	for (r = 2; r <= n; r++)							//��ͬ��ģ��������
	{
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];							//����Ϊk == i�ĳ˷�����
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
	cout << "������������n��";
	cin >> n;
	cout << "����������ÿ����������������һ�������������" << endl;
	for (int i = 0; i <= n; i++)
		cin >> p[i];
	matrixchain();
	print(1, n);
	cout << endl;
	cout << "��С��������ֵΪ��" << m[1][n] << endl;
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
	for (int d = 2; d <= n; d++)									//d���������ģ��d == 2ʱʵ���ϱ�ʾ��������Ϊm[i][j]��ʾ{Vi-1.Vi,Vj}
		for (int i = 1; i <= n - d + 1; i++)
		{
			int j = i + d - 1;
			m[i][j] = m[i + 1][j] + g[i - 1][i] + g[i][j] + g[i - 1][j];						//��m[i][j]���ܵ����ֵ��Ϊ��ֵ
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				double temp = m[i][k] + m[k + 1][j] + g[i - 1][k] + g[i - 1][j] + g[k][j];
				if (m[i][j] > temp)
				{
					m[i][j] = temp;																		//����������ֵ
					s[i][j] = k;																				//��¼����
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

	cout << "�����붥�����n��";
	//cin >> n;
	n = 6;
	cout << n << endl;
	n--;
	cout << "�������������������Ȩֵ��" << endl;
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
	for (int i = 1; i <= n; i++)							//��ʼ��
	{
		Min[i][i] = 0;
		Max[i][i] = 0;
	}
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int v = 2; v <= n; v++)						//ö�ٺϲ������Ĺ�ģ
	{
		for (int i = 1; i <= n - v + 1; i++)			//ö�����i
		{
			int j = i + v - 1;									//ö���յ�j
			Min[i][j] = INF;									//��ʼ��Ϊ���ֵ
			Max[i][j] = -1;									//��ʼ��Ϊ-1
			int temp = sum[j] - sum[i - 1];			//��¼i...j֮���ʯ����Ŀ֮��
			for (int k = i; k < j; k++)					//ö���м�ָ���
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
	cout << "������ʯ�Ӷ���n" << endl;
	cin >> n;
	cout << "��������ѵ�ʯ����Ŀ" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	straight(a, n);
	cout << "·���淨��ֱ���ͣ�����С����Ϊ��" << Min[1][n] << endl;
	cout << "·���淨��ֱ���ͣ�����󻨷�Ϊ��" << Max[1][n] << endl;
	Circular(a, n);
	cout << "�ٳ��淨��Բ�Σ�����С����Ϊ��" << min_Circular << endl;
	cout << "�ٳ��淨��Բ�Σ�����󻨷�Ϊ��" << max_Circular << endl;
}


