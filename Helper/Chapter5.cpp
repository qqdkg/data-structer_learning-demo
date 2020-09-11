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


