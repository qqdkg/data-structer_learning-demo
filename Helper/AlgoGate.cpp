#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "AlgoGate.h"
using namespace std;



//2.4�߼��ӵ���������

MeetType meet[1000];

void setMeet::init()
{
	int begArr[10] = {3,1,5,2,5,3,8,6,8,12};
	int endArr[10] = {6,4,7,5,9,8,11,10,12,14};
	cout << "�����ܴ���nΪ��" << n << endl;
	cout << "����Ŀ�ʼ�ͽ���ʱ��Ϊ��" << endl;
	cout << "������" << "  ���鿪ʼʱ��" << "  �������ʱ��" << endl;
	for (int i = 0; i < n; i++)
	{
		meet[i].beg = begArr[i];
		meet[i].end = endArr[i];
		meet[i].num = i + 1;
		cout << "  " << meet[i].num << "\t\t" << meet[i].beg << "\t\t" << meet[i].end << endl;
	}
}

//����sort�ıȽϺ���
bool cmp(MeetType x, MeetType y)
{
	if (x.end == y.end)
		return x.beg > y.beg;
	return x.end < y.end;
}


void setMeet::solve()
{
	sort(meet, meet + n, cmp);
	int i;
	cout << endl;
	cout << "����֮��Ļ���ʱ������:" << endl;
	cout << "������" << "  ���鿪ʼʱ��" << "  �������ʱ��" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "  " << meet[i].num << "\t\t" << meet[i].beg << "\t\t" << meet[i].end << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << "ѡ��Ļ���Ĺ��̣�" << endl;
	cout << "  ѡ���" << meet[0].num << "������" << endl;			//ѡ�е�һ������
	ans = 1;
	int last = meet[0].end;																	//��¼��һ������Ľ���ʱ��
	for (i = 1; i < n; i++)
	{
		if (meet[i].beg >= last)
		{
			//�������i�Ŀ�ʼʱ����ڵ���ѡ�е����һ������Ľ���ʱ��
			ans++;
			last = meet[i].end;
			cout << "  ѡ���" << meet[i].num << "������" << endl;
		}
	}
	cout << "�����԰���" << ans << "������" << endl;

}

