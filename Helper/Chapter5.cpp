#include "stdafx.h"
#include "Chapter5.h"
#include <iostream>
#include <string>
#include <algorithm>
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