#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <stack>
#include <queue>
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


//2.5���·��

const int N = 100;							//���и��������޸�
const int INF = 1e7;
int map[N][N];
int dist[N];
int p[N];
int n, m;											//nΪ���и�����mΪ����֮���·������
int flag[N];										//flag[i]==ture,��ڵ�i������s���ϣ����߽ڵ�i��V-S����

struct Node {
	int u, step;
	Node() {};
	Node(int a, int sp)
	{
		u = a;
		step = sp;
	} 
	bool operator < (const Node &a) const {
		return step > a.step;
	}
};

void Dijkstra(int st)
{
	priority_queue <Node> Q;			//���ȶ��л�
	Q.push(Node(st, 0));
	memset(flag, 0, sizeof(flag));			//��ʼ��flag����Ϊ0
	for (int i = 1; i <= n; ++i)
		dist[i] = INF;								//��ʼ�����о���Ϊ�����
	dist[st] = 0;
	while (!Q.empty())
	{
		Node it = Q.top();						//���ȶ��ж�ͷԪ��Ϊ��Сֵ
		Q.pop();
		int t = it.u;
		if (flag[t])									//˵���Ѿ��ҵ�����̾��룬�ýڵ��Ƕ��������ظ���Ԫ��
			continue;
		flag[t] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!flag[i] && map[t][i] < INF)
				if (dist[i] > dist[t] + map[t][i])
				{										//����뵱ǰ���ÿ�������̾��룬�����ɳڲ���
					dist[i] = dist[t] + map[t][i];
					Q.push(Node(i, dist[i]));			//�Ѹ��¹�����̾���ѹ�����ȶ���
				}
		}
	}
}//void 

void TestDijkstra()
{
	int u, v, w, st;
	system("color 0d");
	cout << "��������и���" << endl;
	n = 5;
	cout << "��������м��·�߸���" << endl;
	m =7;
	cout << "��������м��·���Լ�����" << endl;
	for(int i=1;i<=n;i++)								//��ʼ��ͼ���ڽӾ���
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = INF;
		}

	int uArr[] = {0,1,1,2,2,3,3,4};
	int vArr[] = {0,2,3,3,4,4,5,5};
	int wArr[] = {0,2,3,5,6,7,1,4};

	int i=1;
	while (m--)
	{
		map[uArr[i]][vArr[i]] = wArr[i];
		i++;
	}
	cout << "������С��Ŀǰ���ڵ�λ��" << endl;
	cin >> st;
	Dijkstra(st);
	//findPath(st);
	for (int i = 1; i <= n; i++)
	{
		cout << "С����" << st << "--->" << "Ҫȥ��λ�ã�" << i;
		if (dist[i] == INF)
			cout << "sorry,��·�ɴ�" << endl;
		else
			cout << "��̾���Ϊ��" << dist[i] << endl;
	}
}

void findPath(int u)
{
	int x;
	stack<int> s;
	cout << "Դ��Ϊ��" << u << endl;
	for (int i = 1; i <= n; i++)
	{
		x = p[i];
		while (x != -1)
		{
			s.push(x);									//��ǰ���ڵ�ѹ��ջ��
			x = p[x];
		}
		cout << "Դ�㵽������������·��Ϊ��";
		while (!s.empty())
		{
			cout << s.top() << "--";					//���ε��������ڵ�
			s.pop();
		}
		cout << "��̾���Ϊ��" << dist[i] << endl;
	}
}




//2.6 ����������
typedef struct {
	double weight;					//Ȩֵ
	int parent;							//˫�׽ڵ�
	int lchild;							//����
	int rchild;							//�Һ���
	char value;						//�ýڵ��ʾ���ַ�
} HNodeType;

typedef struct {


} HCodeType;


