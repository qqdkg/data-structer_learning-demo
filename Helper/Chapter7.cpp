#include "stdafx.h"
#include "Chapter7.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>
using namespace std;


void BestBenefitTank::print()
{
	cout << endl;
	cout << "---------------�����Ա����£�----------------" << endl;
	cout << "  ";
	cout << setw(7) << "b ";
	for (int i = 1; i <= m; i++)
		cout << setw(7) << "x" << FJL[i];
	cout << endl;
	cout << "c ";
	for (int i = 0; i <= n; i++)
	{
		if (i >= 1)
			cout << "x" << JL[i];
		for (int j = 0; j <= m; j++)
			cout << setw(7) << kernel[i][j] << " ";
		cout << endl;
	}
}

void BestBenefitTank::DCXA()
{
	float max1;													//max1���ڴ�����ļ�����
	float max2;													//max2���ڴ���������������Ӧ�Ļ������������ϵ��
	int e = -1;														//��¼�����
	int k = -1;														//��¼������
	float min;
	//ѭ��������ֱ���ҵ�����Ľ�����޽�Ϊֹ
	while (true)
	{
		max1 = 0;
		max2 = 0;
		min = 100000000;
		for (int j = 1; j <= m; j++)							//������У��������������Ӧ���У�
		{
			if (max1 < kernel[0][j])
			{
				max1 = kernel[0][j];
				e = j;
			}
		}
		if (max1 <= 0)											//���ֵ<=0�������м�����<=0�����������Ž������
		{
			cout << endl;
			cout << "������Ž�:" << kernel[0][0] << endl << endl;
			break;
		}
		for (int i = 1; i <= n; i++)							//������У�������/����� ����ֵ��С���У�
		{
			if (max2 < kernel[i][e])
			{
				max2 = kernel[i][e];
			}
			float temp = kernel[i][0] / kernel[i][e];
			if (temp > 0 && temp < min)
			{
				min = temp;
				k = i;
			}
		}
		cout << "�������" << "x" << FJL[e] << " ";
		cout << "�������" << "x" << JL[k] << endl;
		if (max2 == 0)
		{
			cout << "���޽�" << endl;
			break;
		}
		//����任��ת��任��
		char temp = FJL[e];
		FJL[e] = JL[k];
		JL[k] = temp;
		for (int i = 0; i <= n; i++)										//�����������кͳ�����֮�������Ԫ��
		{
			if (i != k)
			{
				for (int j = 0; j <= m; j++)
				{
					if (j != e)
					{
						if (i == 0 && j == 0)
							kernel[i][j] = kernel[i][j] + kernel[i][e] * kernel[k][j] / kernel[k][e];
						else
							kernel[i][j] = kernel[i][j] - kernel[i][e] * kernel[k][j] / kernel[k][e];;
					}
				}//=for (int j
			}//=if (i != k)
		}//=for (int i)
		for (int i = 0; i <= n; i++)														//��������λ�ã������Ԫ��
		{
			if (i != k)
			{
				kernel[i][e] = -kernel[i][e] / kernel[k][e];
			}
		}
		for (int j = 0; j <= m; j++)														//��������λ�ã������Ԫ��
		{
			if (j == e)
				kernel[k][j] = kernel[k][j] / kernel[k][e];
		}
		kernel[k][e] = 1 / kernel[k][e];												//��������λ�ã�����λ��
		print();
	}
}

void BestBenefitTank::BBTTest()
{
	cout << "����ǻ��������ĸ����ͷǻ����������±꣺" << endl;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> FJL[i];
	}
	cout << "������������ĸ����ͻ����������±꣺" << endl;
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		cin >> JL[j];
	}
	cout << "����Լ����׼�ͳ�ʼ�����α������" << endl;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			cin >> kernel[i][j];
		}
	}
	print();
	DCXA();
}

void BestBenefitTank::BBTTest2()
{
	cout << "����ǻ��������ĸ����ͷǻ����������±꣺" << endl;
	//cin >> m;]
	m = 3;
	cout << m << endl;
	char mArr[] = {'0', '2', '4', '5'};
	for (int i = 1; i <= m; i++)
	{
		//cin >> FJL[i];
		FJL[i] = mArr[i];
		cout << FJL[i] << " ";
	}
	cout << endl;
	cout << "������������ĸ����ͻ����������±꣺" << endl;
	//cin >> n;
	n = 4;
	cout << n << endl;
	char nArr[] = {'0', '1', '3', '6', '7' };
	for (int j = 1; j <= n; j++)
	{
		//cin >> JL[j];
		JL[j] = nArr[j];
		cout << JL[j] << " ";
	}
	cout << endl;
	cout << "����Լ����׼�ͳ�ʼ�����α������" << endl;
	float cube[5][4] = { {0, 2.5, 2.8, 76.25}, {0, 1, 0, -5}, {0, 0, 1, -2}, {12000, 0, 0, 1}, {1000, 0.1, 0.08, 0.05} };

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			//cin >> kernel[i][j];
			kernel[i][j] = cube[i][j];
			cout << cube[i][j] << " ";
		}
		cout << endl;
	}
	print();
	DCXA();
}
