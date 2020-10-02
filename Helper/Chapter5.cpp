#include "stdafx.h"
#include "Chapter5.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

double ZOPackBacktrackTank::Bound(int i)									//�����Ͻ�
{
	//ʣ����ƷΪ��i~n����Ʒ
	int rp = 0;
	while (i <= n)
	{
		rp += v[i];
		i++;
	}
	return cp + rp;
}

double ZOPackBacktrackTank::BoundPro(int i)
{
	//ʣ����ƷΪ��i~n����Ʒ
	double cleft = W - cw;													//ʣ������
	double brp = 0.0;
	while (i <= n && w[i] < cleft)
	{
		cleft -= w[i];
		brp += v[i];
		i++;
	}
	if (i <= n)																		//�����и�ķ�ʽװ���������趨�Ͻ磨���ʱ�������и
	{
		brp += v[i] / w[i] * cleft;
	}
	return cp + brp;
}

void ZOPackBacktrackTank::Backtrack(int t)
{
	if (t > n)
	{
		for (int j = 1; j <= n; j++)
		{
			bestx[j] = x[j];
		}
		bestp = cp;
		return;
	}
	if (cw + w[t] < W)																			//��������������������������
	{
		x[t] = 1;
		cw += w[t];
		cp += v[t];
		Backtrack(t + 1);
		cw -= w[t];
		cp -= v[t];
	}
	if (Bound(t + 1) > bestp)																//�����޽�����������������
	{
		x[t] = 0;
		Backtrack(t + 1);
	}
}

void ZOPackBacktrackTank::Knapsack(double W, int n)
{
	//��ʼ��
	cw = 0;																							//��ǰ����
	cp = 0;																							//��ǰ��ֵ
	bestp = 0;																						//��ǰ���ż�ֵ
	double sumw = 0.0;																		//����ͳ����Ʒ��������
	double sumv = 0.0;																		//����ͳ����Ʒ���ܼ�ֵ
	for (int i = 1; i <= n; i++)
	{
		sumv += v[i];
		sumw += w[i];
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "���빺�ﳵ������ֵΪ��" << bestp << endl;
		cout << "������Ʒ�����Է��빺�ﳵ" << endl;
		return;
	}
	Backtrack(1);																					//�ӵ�һ�㿪ʼ����ȷ�������
	cout << "���빺�ﳵ������ֵΪ��" << bestp << endl;
	cout << "���빺�ﳵ����Ʒ�����Ϊ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i] == 1)
			cout << i << " ";
	}
	cout << endl;
}

void ZOPackBacktrackTank::KnapsackPro(double W, int n)
{
	cw = 0;																							//���ﳵ��ǰ����
	cp = 0;																							//���ﳵ��ǰ��ֵ
	bestp = 0;																						//��ǰ����ֵ
	double sumw = 0;																		//������Ʒ������
	double sumv = 0;																			//������Ʒ�ܼ�ֵ

	ObjectNode *Q = new ObjectNode[n];										//��Ʒ�ṹ�壬������Ʒ����ź͵�λ������ֵ
	double *a = new double[n + 1];													//�����������ڰ������������ͼ�ֵ���ݸ�ԭ����  a[]��ʾ��ʱ��������
	double *b = new double[n + 1];													//b[]��ʾ��ʱ��ֵ����
																										//��̬�������ڴ�֮��ǵ�Ҫ����
	for (int i = 1; i <= n; i++)
	{
		Q[i - 1].id = i;
		Q[i - 1].d = 1.0 * v[i] / w[i];
		sumv += v[i];
		sumw += w[i];
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "���빺�ﳵ������ֵΪ��" << bestp << endl;
		cout << "������Ʒ�����Է��빺�ﳵ" << endl;
		return;
	}
	sort(Q, Q + n, cmp);																		//����(��ֵ/����)��˳��Ӵ�С����
	for (int i = 1; i <= n; i++)
	{
		a[i] = w[Q[i - 1].id];																	//�����������ݴ��ݸ���������
		b[i] = v[Q[i - 1].id];
	}
	for (int i = 1; i <= n; i++)
	{
		w[i] = a[i];
		v[i] = b[i];
	}
	Backtrack(1);																					//�ӵ�һ�㿪ʼ�����������
	cout << "���빺�ﳵ����Ʒ������ֵΪ��" << bestp << endl;
	cout << "���빺�ﳵ����Ʒ���Ϊ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i] == 1)
			cout << i << " ";
	}
	cout << endl;

	//�ͷ��ڴ�
	delete []Q;
	delete []a;
	delete []b;
}

void ZOPackBacktrackTank::ZOPBTest()
{
	cout << "��������Ʒ���ܸ�����" << endl;
	cin >> n;
	cout << "�����빺�ﳵ���ؼ��ޣ�" << endl;
	cin >> W;
	cout << "��ֱ����������Ʒ������w�ͼ�ֵv���ÿո�ֿ���" << endl;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	Knapsack(W, n);
}

void ZOPackBacktrackTank::ZOPBTestPro()
{
	cout << "��������Ʒ���ܸ�����" << endl;
	cin >> n;
	cout << "�����빺�ﳵ���ؼ��ޣ�" << endl;
	cin >> W;
	cout << "��ֱ����������Ʒ������w�ͼ�ֵv���ÿո�ֿ���" << endl;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	KnapsackPro(W, n);
}

bool cmp(ObjectNode a1, ObjectNode a2)
{
	return a1.d > a2.d;
}

bool BPOcmp(BPOnode a, BPOnode b)
{
	return min(b.x, a.y) > min(b.y, a.x);												//���ձ�������ʽ������ʵ������û����
																						//��i���ܱ���j�õĳ�Ҫ������min{t1j, t2i} >= min{t1i, t2j} 
}

//�ж��Ƿ���԰ѽ��t��������
bool BigestRollTank::Place(int t)
{
	bool result = true;
	for (int j = 1; j < t; j++)													//�жϽ��t��ǰt - 1������Ƿ�����
	{
		if (x[j] && a[t][j] == 0)														//�൱��x[j] == true,��ʾj�Ǳ�ѡ�н��,a[t][j] == 0��ʾt��jû�б�����
		{
			result = false;
			break;
		}
	}
	return result;
}

void BigestRollTank::Backtrack(int t)
{
	if (t > n)
	{
		for (int i = 1; i <= n; i++)
		{
			bestx[i] = x[i];
		}
		bestn = cn;
		return;
	}
	if (Place(t))																		//����Լ�����������������������ѽ��t��������
	{
		x[t] = 1;
		cn++;
		Backtrack(t + 1);
		cn--;
	}
	if (cn + (n - t) > bestn)														//�����޽�����������������
	{
		x[t] = 0;
		Backtrack(t + 1);
	}
}

void BigestRollTank::BigestRollTest()
{
	int u, v;
	//int uArr[] = { 0, 1, 1, 1, 1, 2, 3, 3, 4 };
	//int vArr[] = { 0, 2, 3, 4, 5, 3, 4, 5, 5 };
	cout << "�����벿������n���ڵ�����" << endl;
	cin >> n;
	cout << "�����������˵��Ѻù�ϵ����������" << endl;
	cin >> m;
	memset(a, 0, sizeof(a));														//���ڽӾ����е����ݳ�ʼ��Ϊ0��<string.h>
	cout << "�������������Ѻù�ϵ�������ˣ��б������������ڵ�u��v���ÿո�ֿ�" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		a[u][v] = a[v][u] = 1;
		//cout << uArr[i] << " " << vArr[i] << endl;
		//a[uArr[i]][vArr[i]] = a[vArr[i]][uArr[i]] = 1;
	}
	bestn = 0;
	cn = 0;
	Backtrack(1);																		//�ӵ�һ�㿪ʼ����
	cout << "���������ӵ��������Ϊ��" << bestn << endl;
	cout << "���������ӵĳ�ԱΪ��";
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i])
			cout << i << " ";
	}
	cout << endl;
}

//�����ڽӾ���
void ColorMapQuesTank::CreatMap()
{
	int u, v;
	cout << "�����������" << endl;
	cin >> edge;
	memset(map, 0, sizeof(map));											//���ڽӾ��������ֵ��ʼ��Ϊ0
	cout << "���������б������ӵ������ڵ�u��v���ÿո�ֿ���" << endl;
	for (int i = 1; i <= edge; i++)
	{
		cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}
}

//Լ������
bool ColorMapQuesTank::OK(int t)
{
	for (int j = 1; j < t; j++)														//��1~ t - 1����
	{
		if (map[t][j])
		{
			if (x[t] == x[j])
				return false;
		}
	}// for j
	return true;
}

void ColorMapQuesTank::Backtrack(int t)
{
	if (t > n)																			//����Ҷ�ӽ��
	{
		sum++;																		//���н��������
		cout << "��" << sum << "�ֿ��н⣺";
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		cout << endl;
	}
	else
	{
		for (int j = 1; j <= m; j++)
		{
			x[t] = j;																		//��t��ڵ����ɫ������ɫ��
			if (OK(t))																	//��������ڽӵĽڵ���ɫ��ͬ���������������
				Backtrack(t + 1);													//����ֻѰ�ҿ��н⣬��Ѱ�����Ž⣬û�������޽纯��
		}
	}
}

void ColorMapQuesTank::CMQTest()
{
	cout << "������ڵ���n��" << endl;
	cin >> n;
	cout << "��������ɫ��m��" << endl;
	cin >> m;
	CreatMap();																		//�����ɵ�ͼת��������������ͨͼ���ڽӾ���
	Backtrack(1);																		//��m�����ṹ�Ľ����֯��ʽ�ĵ�һ�㿪ʼ�������ù��̲�����Ҫ�������һ��m������
}

bool NQueenTank::Place(int t)
{
	bool ok = true;
	for (int i = 1; i < t; i++)														//�жϵ�t���ʺ��Ƿ���ǰt - 1���ʺ��ͻ����ʱǰt���ʺ��λ���Ѿ���ȷ����
	{
		if (x[t] == x[i] || t - i == abs(x[t] - x[i]))
		{
			ok = false;
			break;
		}
	}
	return ok;
}

void NQueenTank::Backtrack(int t)
{
	if (t > n)
	{
		count++;
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		cout << endl;
		cout << "---------------" << endl;
	}
	else
		for (int i = 1; i <= n; i++)
		{																					//�ж�m����֧��m = n���Ľ��
			x[t] = i;
			if (Place(t))																//�����t��Ļʺ�����ڷ����ڵ�i�в���ͻ����������ȷ�������
				Backtrack(t + 1);
		}
}

void NQueenTank::NQueenTest()
{
	cout << "������ʺ�ĸ���n��" << endl;
	cin >> n;
	Backtrack(1);																		//�ӵ�һ�㿪ʼ����
	cout << "�𰸵ĸ�����" << count << "��" << endl;
}


//5.6 ���żӹ�˳��
void BestProcessOrderTank::Backtrack(int t)
{
	if (t > n)
	{
		for (int i = 1; i <= n; i++)
			bestx[i] = x[i];
		bestf = f2;																		//�����ֵ
		return;
	}

	for (int i = t; i <= n; i++)
	{
		f1 += T[x[i]].x;
		int temp = f2;
		f2 = max(f1, temp) + T[x[i]].y;
		if (f2 < bestf)
		{
			//�����ⲿ���߼��ǹ��������������ɵģ�֮����Ҫ�������¡�
			swap(x[t], x[i]);
			Backtrack(t + 1);
			swap(x[t], x[i]);
		}
		f1 -= T[x[i]].x;
		f2 = temp;
	}
}

void BestProcessOrderTank::BPOTest()
{
	cout << "����������������n��" << endl;
	cin >> n;
	cout << "������ÿ������ڵ�һ̨�����͵ڶ�̨�����ļӹ�ʱ�䣬���ÿո���" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> T[i].x >> T[i].y;
		x[i] = i;
	}
	//��ʼ��
	bestf = INF;
	f1 = f2 = 0;
	memset(bestx, 0, sizeof(bestx));
	Backtrack(1);														//�ӵ�һ�㿪ʼ����		�������������
	cout << "��������ӹ�˳��Ϊ" << endl;
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << " ";
	cout << endl;
	cout << "���ŵĻ�������ӹ�ʱ��Ϊ��" << endl;
	cout << bestf << endl;
}

void BestProcessOrderTank::BPOTest_Pro()
{
	//ʹ�ñ��������򣬵õ��ȼӹ�i�õ�������min{t1j, t2i} >= min{t1i, t2j}  �����������Ż���ʽ
	cout << "����������������n��" << endl;
	cin >> n;
	cout << "����������ÿ����������ڵ�һ̨�����ϵļӹ�ʱ��x�͵ڶ�̨�����ϵļӹ�ʱ��y��" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> T[i].x >> T[i].y;
		T[i].id = i;
	}
	sort(T + 1, T + n + 1, BPOcmp);													//����
	int f1 = 0, f2 = 0;
	for (int i = 1; i <= n; i++)																//������ʱ��
	{
		f1 += T[i].x;
		f2 = max(f1, f2) + T[i].y;
	}
	cout << "��������ӹ�˳��Ϊ��" << endl;
	for (int i = 1; i <= n; i++)
		cout << T[i].id << " ";
	cout << endl;
	cout << "���Ż�������ӹ�ʱ��Ϊ��" << endl;
	cout << f2 << endl;
}

void ArrayTree::myarray(int t)
{
	if (t > n)
	{
		for (int i = 1; i <= n; i++)					//�������
			cout << x[i] << " ";
		cout << endl;
		return;
	}
																//����ʵ���������ĵݹ�������Ƕ���ν��{1��2��...��n}��1��ÿһ������������ȥͷ���Ƶ�ʵ��
	for (int i = t; i <= n; i++)						//ö��
	{
		swap(x[t], x[i]);									//����
		myarray(t + 1);									//�����������
		swap(x[t], x[i]);									//����ʱ�ķ�����
	}
}

void ArrayTree::ArrayTreeTest()
{
	cout << "������е�Ԫ�ظ���n����1..n�����У���" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
		x[i] = i;
	myarray(1);
}

void BusinessTravelTank::Traveling(int t)
{
	if (t > n)
	{
		//��������Ҷ�ӽ������
		//���һ��������פ�س����б���������Ϊ��ĿҪ��ص������أ�������·�����ȱȵ�ǰ����ֵС
		//˵���ҵ�һ������·������¼�����Ϣ
		if (g[x[n]][1] != INF && (cl + g[x[n]][1] < bestl))
		{
			for (int i = 1; i <= n; i++)
				bestx[i] = x[i];
			bestl = cl + g[x[n]][1];
		}
	}
	else
	{
		//û�е���Ҷ�ӽڵ�
		for (int j = t; j <= n; j++)																		//������������
		{
			//������չ�ڵ�����з�֧
			//�����t - 1���������j�������б����������ҿ��ܵõ����̵�·��ʱ
			if (g[x[t - 1]][x[j]] != INF && (cl + g[x[t - 1]][x[j]] < bestl))
			{
				//�����t��Ҫȥ�ĳ��б�ŵ�x[t]�У������t + 1��
				swap(x[t], x[j]);																				//��������Ԫ����ֵ��Ϊ����������������ȡ�ĳ������
				cl = cl + g[x[t - 1]][x[t]];
				Traveling(t + 1);																			//��t + 1����չ�ڵ����������
				//��t + 1���������
				cl = cl - g[x[t - 1]][x[t]];
				swap(x[t], x[j]);
			}
		}
	}
}

void BusinessTravelTank::init()																		//��ʼ��
{
	bestl = INF;
	cl = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			g[i][j] = g[j][i] = INF;
	for (int i = 0; i <= n; i++)																			//��0��ʼ��������n + 1��Ԫ��
	{
		x[i] = i;																									//��0��ʼ��n��������Ȼ����
		bestx[i] = 0;
	}
}

void BusinessTravelTank::print()
{
	cout << "���·����" << endl;
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << "--->";
	cout << " 1" << endl;
	cout << "���·�����ȣ�" << bestl << endl;
}

void BusinessTravelTank::BTTest()
{
	int u, v, w;										//u, v������У�w����u��v֮������߳���
	cout << "�����뾰����Ŀn���ڵ�������";
	cin >> n;
	init();
	cout << "�����뾰����������Ŀ";
	cin >> m;
	cout << "������������������u��v�Լ����߾��룬��ʽ������u ����v ����w" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}
	Traveling(2);																							//��Ϊ��ͷ��ʵ�ֵ�������������Ҫ�ӵڶ��㿪ʼ��֮ǰд��ʱ�����Ԥ�е�
	print();
}

void BadBussinessTravelTank::Init()
{
	memset(dp, INF, sizeof(dp));
	memset(path, 0, sizeof(path));
	memset(g, INF, sizeof(g));
	bestl = INF;
}

void BadBussinessTravelTank::Traveling()
{
	dp[1][0] = 0;
	S = 1 << n;									//S  = 2^n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!(i & (1 << j))) continue;

			for (int k = 0; k < n; k++)
			{
				if (i & (1 << k)) continue;
				if (dp[i | (1 << k)][k] > dp[i][j] + g[j][k])
				{
					dp[i | (1 << k)][k] = dp[i][j] + g[j][k];
					path[i | (1 << k)][k] = j;
				}
			}// for k

		}// for j
	}// for i
	for (int i = 0; i < n; i++)												//�������·������
	{
		if (bestl > dp[S - 1][i] + g[i][0])
		{
			bestl = dp[S - 1][i] + g[i][0];
			sx = i;
		}
	}
}

void BadBussinessTravelTank::print(int S, int value)
{
	if (!S) return;

	for (int i = 0; i < n; i++)
	{
		if (dp[S][i] == value)
		{
			print(S^(1 << i), value - g[i][path[S][i]]);								//�ݹ������̬�滮�Ľ��
			cout << i + 1 << "--->";
			break;
		}
	}
}

void BadBussinessTravelTank::BBTTest()
{
	int u, v, w;										//u, v������У�w����u��v֮������߳���
	cout << "�����뾰����Ŀn���ڵ�������";
	cin >> n;
	Init();
	cout << "�����뾰����������Ŀ";
	cin >> m;
	cout << "������������������u��v�Լ����߾��룬��ʽ������u ����v ����w" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}
	Traveling();
	cout << "���·����" << endl;
	print(S - 1, bestl - g[sx][0]);
	cout << 1 << endl;
	cout << "���·������";
	cout << bestl << endl;
}

