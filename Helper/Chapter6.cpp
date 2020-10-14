#include "stdafx.h"
#include "Chapter6.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

//��������ת̬�Ľڵ�Ľṹ��Ĺ��캯��ʵ��
ShopBagNode::ShopBagNode()
{
	memset(x, 0, sizeof(x));
}

ShopBagNode::ShopBagNode(int _cp, int _rp, int _rw, int _id)
{
	cp = _cp;
	rp = _rp;
	rw = _rw;
	id = _id;
}

int ZeroOneBagSpan::bfs()
{
	int t;																				//t:��ǰ������Ʒ���
	int tcp;																			//tcp:��ǰװ�빺�ﳵ��Ʒ�ļ�ֵ
	int trp;																			//trp:��ǰʣ����Ʒ��ֵ
	int trw;																			//trw:��ǰʣ������
	queue<SBNode> q;														//����һ����ͨ���У��Ƚ��ȳ���
	q.push(SBNode(0, sumv, W, 1));									//ѹ��һ����ʼ�ڵ�

	while (!q.empty())															//ʹ�ý��ڵ������еķ���ʵ�ֹ�����������������ǵݹ���ʽ�������������
	{
		SBNode livenode, lchild, rchild;								//������ʱ����
		livenode = q.front();													//ȡ����ͷԪ����Ϊ��ǰ��չ�ڵ�livenode
		q.pop();																	//�׿�
		t = livenode.id;															//��ȡ��ǰ�������Ʒ���
		//���������һ����Ʒ��ʱ����Ҫ���¼�������
		//������ﳵ�Ѿ�װ����Ҳ����Ҫ������չ����Ϊ0-1����������Ʒ���ɷָ
		if (t > n || livenode.rw == 0)
		{
			if (livenode.cp >= bestp)										//�������Ž������ֵ
			{
				for (int i = 1; i <= n; i++)
				{
					bestx[i] = livenode.x[i];
				}
				bestp = livenode.cp;
			}
			continue;																//��������е���һ���ڵ�
		}
		//�жϵ�ǰ�ڵ��Ƿ������޽�����������������򲻼�����չ
		if (livenode.cp + livenode.rp < bestp)
			continue;																//����������չҲ����õ����Ž�
		//��չ����
		tcp = livenode.cp;														//��ǰ���ﳵ�еļ�ֵ
		trp = livenode.rp - goods[t].value;							//������Ʒ�Ƿ�װ�룬ʣ���ֵ�������
		trw = livenode.rw;													//��ǰ���ﳵʣ������
		if (trw >= goods[t].weight)										//����Լ�����������Է��빺�ﳵ
		{
			lchild.rw = trw - goods[t].weight;
			lchild.cp = tcp + goods[t].value;
			lchild = SBNode(lchild.cp, trp, lchild.rw, t + 1);
			for (int i = 1; i < t; i++)
				lchild.x[i] = livenode.x[i];									//����ǰt - 1����Ʒ��״̬
			lchild.x[t] = true;
			if (lchild.cp > bestp)												//��������е�����ֵ����
				bestp = lchild.cp;
			q.push(lchild);														//�������
		}

		//��չ�Һ���
		if (tcp + trp >= bestp)												//�����޽����������빺�ﳵ����֧��Ȼ�ǻ��֧��������������ν��������Һ���ֱ�Ӳ�������У�֮��Ͳ��ᱻ�������൱�ڱ���֦
		{
			rchild = SBNode(tcp, trp, trw, t + 1);
			for (int i = 1; i < t; i++)
				rchild.x[i] = livenode.x[i];
			rchild.x[t] = false;
			q.push(rchild);
		}
	}// while(!q.empty());

	return bestp;
}

void ZeroOneBagSpan::ZOBSTest()
{
	//������Ʒ�ĸ����ͱ���������
	cout << "��������Ʒ�ĸ���n��";
	cin >> n;
	cout << "�����빺�ﳵ������W��";
	cin >> W;
	cout << "����������ÿ����Ʒ������w�ͼ�ֵv��ʹ�ÿո����" << endl;
	bestp = 0;																							//��ʼ�����Ž�Ϊ0
	sumv = 0;
	sumw = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> goods[i].weight >> goods[i].value;
		sumw += goods[i].weight;
		sumv += goods[i].value;
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "���빺�ﳵ������ֵΪ��" << bestp << endl;
		cout << "������Ʒ���ɷ��빺�ﳵ��" << endl;
		return;
	}
	bfs();																									//ʹ�ù�����ѷ����������Ž�
	cout << "���빺�ﳵ����Ʒ������ֵΪ��" << bestp << endl;
	cout << "���빺�ﳵ����Ʒ˳��Ϊ��" << endl;
	//������Ž�
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i])
			cout << i << " ";
	}
	cout << endl;

}

ShopBagNodePro::ShopBagNodePro()
{
	memset(x, false, sizeof(x));
}

ShopBagNodePro::ShopBagNodePro(int _cp, double _up, int _rw, int _id)
{
	cp = _cp;
	up = _up;
	rw = _rw;
	id = _id;
}

bool operator <(const ShopBagNodePro & a, const ShopBagNodePro & b)
{
	return a.up < b.up;
}

bool cmp(TSObject a1, TSObject a2)
{
	return a1.d > a2.d;
}

//���ڶ������ȶ��е����ȼ���clԽС���ȼ�Խ��
bool operator<(const TSNode & a, const TSNode & b)
{
	return a.cl > b.cl;
}

//������е����ȼ�����zlΪ���ȼ��zlԽС��Խ����
bool operator<(const TspNode & a, const TspNode & b)
{
	return a.zl > b.zl;
}

double ZeroOneBagSpanPro::Bound(SBNodePro tnode)
{
	double maxvalue = tnode.cp;											//��װ�빺�ﳵ����Ʒ��ֵ
	int t = tnode.id;																//�����ı��
	double left = tnode.rw;														//ʣ������
	while (t <= n && w[t] <= left)											//δ����Ҷ�ӽ�㣬�ҵ�ǰ��Ʒ���ܹ�װ�빺�ﳵ
	{
		maxvalue += v[t];
		left -= w[t];
	}
	if (t <= n)
	{
		maxvalue += 1.0 * v[t] / w[t] * left;								//���ĳһ��Ų���ȥ�ˣ��Ǿͷ���һ���һ���ֽ�ȥ��������������Ͻ�
	}
	return maxvalue;
}

int ZeroOneBagSpanPro::priorbfs()
{
	int t;																					//���ڴ�����Ʒ���t
	int tcp;																				//��ǰ״�����Ʒ��ֵtcp
	int tup;																				//��ǰװ����Ʒ�ļ�ֵ�Ͻ�(��ǰ·�ߵĿ��ܵ�����ֵ)
	int trw;																				//��ǰ���ﳵʣ������ trw;
	priority_queue<SBNodePro> q;										//����һ�����ȶ��У����ȼ�Ϊװ�����е���Ʒ�ļ�ֵ�Ͻ�
	q.push(SBNodePro(0, sumv, W, 1));									//��ʼ���������ڵ�ѹ��
	//ʹ�����߶��У������Ӽ������й������
	while (!q.empty())
	{
		SBNodePro livenode, lchild, rchild;								//������������
		livenode = q.top();														//ȡ��ͷԪ����Ϊ��ڵ�  ����������ǵô�����
		q.pop();																		//�׿�
		t = livenode.id;																//��ǰ�������Ʒ���
		//���������һ����Ʒ��ʱ����Ҫ��������
		//---------------------//�����ǰ���ﳵû��ʣ������(�Ѿ�װ��)������չ
		if (t > n || livenode.rw == 0)
		{
			if (livenode.cp >= bestp)											//�������Ž������ֵ		//�ٶ����ȵ�ʱ������һ��Ҫ ">="�����޷�����Ҷ�ӽڵ�
			{
				for (int i = 1; i <= n; i++)
					bestx[i] = livenode.x[i];
				bestp = livenode.cp;
			}// livenode.cp > bestp
			continue;
		}// t >n || rw == 0
		//�жϵ�ǰ�ڵ��Ƿ������޽����������������������չ
		if (livenode.up < bestp)
			continue;

		//!!---------------------//��չ����
		tcp = livenode.cp;															//��ǰ���ﳵ�еļ�ֵ
		trw = livenode.rw;														//��ǰ���ﳵ�е�ʣ������

		if (trw >= w[t])																//�������Լ�����������Է��빺�ﳵ
		{
			lchild.cp = tcp + v[t];
			lchild.rw = trw - w[t];
			lchild.id = t + 1;
			tup = Bound(lchild);													//�������ӵĿ�װ�Ͻ�,����Bound����������ʱ��lchild��ʵֻ������һ����
			lchild = SBNodePro(lchild.cp, tup, lchild.rw, t + 1);
			for (int i = 1; i < t; i++)
				lchild.x[i] = livenode.x[i];										//�����һ��״̬�Ľ�����
			lchild.x[t] = true;
			if (lchild.cp > bestp)													//������ֵ��Ÿ��£���Ϊ�Ǻ���Ĺ���������б�Ҫ�������ж��Ƿ��������ֵ
				bestp = lchild.cp;
			q.push(lchild);
		}

		//--------------------------// ��չ�Һ���
		rchild.cp = tcp;
		rchild.rw = trw;
		rchild.id = t + 1;
		tup = Bound(rchild);														//�����Һ��ӵ��Ͻ�											//֮ǰ������������أ����ȶ����ƺ����Զ��Ƚ������ֵȻ������
		if (tup >= bestp);															//�����޽����������Ҳ�����ǰ��Ʒ���빺�ﳵ�����
		{
			rchild = SBNodePro(tcp, tup, trw, t + 1);
			for (int i = 1; i <t ; i++)
				rchild.x[i] = livenode.x[i];										//��ȡ��һ��״̬�Ľ�����
			rchild.x[t] = false;
			q.push(rchild);															//�Һ������
		}// tup > bestp
	}
	return bestp;
}

void ZeroOneBagSpanPro::ZOBSPTest()
{
	bestp = 0;																			//����ֵ��ʼ��
	sumw = 0;
	sumv = 0;
	memset(bestx, false, sizeof(bestx));
	cout << "��������Ʒ����n��" << endl;
	cin >> n;
	cout << "�����빺�ﳵ����W��" << endl;
	cin >> W;
	cout << "������ÿ����Ʒ������w�ͼ�ֵv��ʹ�ÿո�ֿ���" << endl;
	int wArr[] = {2, 5, 4, 2};
	int vArr[] = {6, 3, 5, 4};
	for (int i = 1; i <= n; i++)
	{
		cin >> goods[i].weight >> goods[i].value;					//�����i����Ʒ�������ͼ�ֵ
		/*goods[i].weight = wArr[i - 1];
		goods[i].value = vArr[i - 1];
		cout << goods[i].weight << " " << goods[i].value << endl;*/
		sumw += goods[i].weight;
		sumv += goods[i].value;
		S[i - 1].id = i;
		S[i - 1].d = 1.0 * goods[i].value / goods[i].weight;
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "���빺�ﳵ������ֵΪ��" << bestp << endl;
		cout << "������Ʒ�����Է��빺�ﳵ��" << endl;
		return;
	}
	sort(S, S + n, cmp);															//�Ը����ṹ�������������, a1.d > a2.d; �ɴ�С
	cout << "��������Ʒ�����ͼ�ֵ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		w[i] = goods[S[i - 1].id].weight;									//�����������������ʹ�ð�����������洢��ʵ������ı�ţ���������������֮������ڵ�λ�ñ仯��ͨ��id�ҵ�ԭʼ����Ķ�ӦԪ�أ�ͬʱ�����øı�ԭʼ����
		v[i] = goods[S[i - 1].id].value;
		cout << w[i] << " " << v[i] << endl;
	}
	priorbfs();																			//ʹ�����߶���ʵ�ֵ�0-1�������������������֧�޽編��
	//������Ž�
	cout << "���빺�ﳵ������ֵΪ��" << bestp << endl;
	cout << "���빺�ﳵ����Ʒ���Ϊ��";
	//������Ž�
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i])
			cout << S[i - 1].id << " ";											//����ԭʼ��Ʒ��ţ�����ǰ�ı�ſ�������ֱ�������
	}
	cout << endl;
}

TravelingSalesmanNode::TravelingSalesmanNode()
{
}

TravelingSalesmanNode::TravelingSalesmanNode(double _cl, int _id)
{
	cl = _cl;
	id = _id;
}

double TravelingSalesmanSpan::Travelingbfs()
{
	int t;																		//��ǰ����ľ������t
	TSNode livenode, newnode;									//���嵱ǰ��չ���livenode�������½��newnode
	priority_queue<TSNode> q;									//����һ�����ȶ��У����ȼ�Ϊ���߹�·��cl��clԽС���ȼ�Խ��
	newnode = TSNode(0, 2);									//��������㣨Ϊʲô������ڵڶ��㣿��
	for (int i = 1; i <= n; i++)
	{
		newnode.x[i] = i;												//��ʼ������������
	}
	q.push(newnode);													//�����������ȶ���
	while (!q.empty())
	{
		livenode = q.top();												//ȡ����ͷ�����Ϊ��ڵ�
		q.pop();															//�׿�
		t = livenode.id;													//��ǰ����ľ������
		//�����������ڶ�������ʱ����Ҫ����������
		if (t == n)
		{
			//�����ҵ�һ��·����1 2 4 3��������4�ž���ʱ�������ж�g[4][3]��g[3][1]�Ƿ��б�������
			//����б����������жϵ�ǰ·������ cl + g[4][3] + g[3][1] < bestl,�������������ֵ�����Ž�
			double path1 = g[livenode.x[n - 1]][livenode.x[n]];
			double path2 = g[livenode.x[n]][1];
			if (path1 != INF && path2 != INF && livenode.cl + path1 + path2 < bestl)
			{
				bestl = livenode.cl + path1 + path2;
				cout << endl;
				for (int i = 1; i <= n; i++)
				{
					bestx[i] = livenode.x[i];
				}
			}//==if (path1...
			continue;
		}//==if (t == n)
		
		 //�жϵ�ǰ�ڵ��Ƿ������޽����������������������չ
		if (livenode.cl >= bestl)
			continue;

		//��չ
		//û�дﵽҶ�ӽ��
		for (int j = t; j <= n; j++)												//������չ�������з�֧
		{
			if (g[livenode.x[t - 1]][livenode.x[j]] != INF)				//���x[t - 1]��x[j]����
			{
				double cl = livenode.cl + g[livenode.x[t - 1]][livenode.x[j]];
				if (cl < bestl)
				{
					newnode = TSNode(cl, t + 1);
					for (int i = 1; i <= n; i++)
					{
						newnode.x[i] = livenode.x[i];							//������ǰ�Ľ�����
					}
					swap(newnode.x[t], newnode.x[j]);					//����newnode��x[t]��x[j]��ֵ������ʵ�ֽ�ռ�Ϊ�������Ĳ���
					q.push(newnode);												//�½�����
				}
			}// == if (g...
		}// == for (int j = t

	}//== while (!q.empty())
	return bestl;
}

void TravelingSalesmanSpan::init()
{
	bestl = INF;
	for (int i = 0; i <= n; i++)
		bestx[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			g[i][j] = g[j][i] = INF;
}

void TravelingSalesmanSpan::print()
{
	cout << endl;
	cout << "���·����";
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << "--->";
	cout << "1" << endl;
	cout << "���·�����ȣ�" << bestl << endl;
}

void TravelingSalesmanSpan::TSSTest()
{
	int u, v, w;								//u,v������У�w�������u, v֮��ľ���
	cout << "�����뾰�����n�����������" << endl;
	cin >> n;
	init();
	cout << "�����뾰��������������������" << endl;
	cin >> m;
	cout << "������������������u, v�����������ľ���w����ʽ������u ����v ����w��" << endl;
	int uArr[] = {1, 1, 1, 2, 2, 3};
	int vArr[] = { 2, 3, 4, 3, 4, 4 };
	int wArr[] = { 15, 30, 5, 6, 12, 3 };
	for (int i = 1; i <= m; i++)
	{
		/*cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;*/
		cout << uArr[i - 1] << " " << vArr[i - 1] << " " << wArr[i - 1] << endl;
		g[uArr[i - 1]][vArr[i - 1]] = g[vArr[i - 1]][uArr[i - 1]] = wArr[i - 1];
	}
	Travelingbfs();
	print();
}

void TravelingSalesmanSpan::TSSTest2()
{
	int u, v, w;								//u,v������У�w�������u, v֮��ľ���
	cout << "�����뾰�����n�����������" << endl;
	cin >> n;
	init();
	cout << "�����뾰��������������������" << endl;
	cin >> m;
	cout << "������������������u, v�����������ľ���w����ʽ������u ����v ����w��" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}
	Travelingbfs();
	print();
}

TsProNode::TsProNode()
{
}

TsProNode::TsProNode(double _cl, double _rl, double _zl, int _id)
{
	cl = _cl;
	rl = _rl;
	zl = _zl;
	id = _id;
}

bool TravelingSalesmanSpanPro::Bound()													//�����½磨��ÿ��������С����֮�ͣ�
{
	for (int i = 1; i <= n; i++)
	{
		double minl = INF;																				//��ʼ������ĳ�����Сֵ
		for (int j = 1; j <= n; j++)																		//�ҳ�ÿ���������С��
			if (g[i][j] != INF && g[i][j] < minl)
				minl = g[i][j];
		if (minl == INF)
			return false;																						//��ʾ�޻�·
		minout[i] = minl;																					//��¼ÿ���������С����
		minsum += minl;																					//��¼���ж������С����֮��
	}
	return true;
}

//TravelingSalesmanSpanProΪ�Ż��ķ�֧�޽編
double TravelingSalesmanSpanPro::Travelingbfsopt()
{
	if (!Bound())
		return -1;																								//��ʾ�޻�·
	TspNode livenode, newnode;																	//���嵱ǰ��չ�ڵ�livenode�������½ڵ�newnode
	priority_queue<TspNode> q;																	//����һ�����ȶ��У����ȼ�ʹ�õ�ǰ·�����ȵ��½�
																													//zl = cl + rl;					zlԽСԽ����
	newnode = TsProNode(0, minsum, minsum, 2);										//���������
	for (int i = 1; i <= n; i++)
	{
		newnode.x[i] = i;																					//��ʼ������������
	}
	q.push(newnode);																						//���ڵ�������ȶ���
	while (!q.empty())
	{
		livenode = q.top();																				//ȡ����ͷ�����Ϊ��ǰ��չ�ڵ�livenode
		q.pop();																								//�׿�
		int t = livenode.id;																				//��¼��ǰ����ľ������
		//�����������ڶ������ʱ����Ҫ�����������ˣ���Ϊ��ö�Ҫ�ص�Լ�㣬�յ������ڶ������ʱδ֪�Ѷ�
		if (t == n)																								//�ж��Ƿ񵽴����Ž�
		{
			//���統�ҵ�һ��·�� ��1 2 4 3��������4�Ž���ʱ�������ж�g[4][3]��g[3][1]�Ƿ���������
			//����б��������жϵ�ǰ·���Ƿ�Ϊ����·�� cl + g[4][3] + g[3][1] < bestl��������������Ž�
			double path1 = g[livenode.x[n - 1]][livenode.x[n]];
			double path2 = g[livenode.x[n]][1];
			if (path1 != INF && path2 != INF && livenode.cl + path1 + path2 < bestl)
			{
				bestl = livenode.cl + path1 + path2;

				//��¼��ǰ���Ž�����
				for (int i = 1; i <= n; i++)
					bestx[i] = livenode.x[i];
			}// == if (path1 ...
			continue;
		}// == if (t == n)

		if (livenode.cl >= bestl)
			continue;

		//��չ
		//û�е���Ҷ�ӽ��
		for (int j = t; j <= n; j++)																				//������չ�ڵ�����з�֧1 ... t - 1 �ڵ�ǰ·�����Ѿ����߹��ˣ������ڱ���
		{
			if (g[livenode.x[t - 1]][livenode.x[j]] != INF)
			{																												//���x[t - 1]��x[j]֮���б�����
				double cl = livenode.cl + g[livenode.x[t - 1]][livenode.x[j]];
				double rl = livenode.rl - minout[livenode.x[j]];
				double zl = cl + rl;
				if (zl < bestl)																							//������ܻ�ø���·��
				{
					newnode = TsProNode(cl, rl, zl, t + 1);
					for (int i = 1; i <= n; i++)
						newnode.x[i] = livenode.x[i];															//������ǰ�Ľ�����
					swap(newnode.x[t], newnode.x[j]);													//��������Ԫ�ص�ֵ��Ϊ���޶���ռ�Ϊ��������
					q.push(newnode);																				//�½ڵ����
				}// == if (zl < bestl)
			}// == if (g...
		}// == for (int j...)
	}// == while (!q.empty())

	return bestl;
}

void TravelingSalesmanSpanPro::Init()
{
	bestl = INF;
	minsum = 0;
	for (int i = 0; i <= n; i++)
		bestx[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			g[i][j] = g[j][i] = INF;																						//��ʼ��Ϊȫ����ͨ
}

void TravelingSalesmanSpanPro::print()
{
	cout << endl;
	cout << "���·����" << endl;
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << "--->";
	cout << "1" << endl;
	cout << "���·�����ȣ�" << bestl << endl;
}

void TravelingSalesmanSpanPro::TSSProTest()
{
	int u, v, w;																//��������u������v��u v֮��ľ���w
	cout << "�����뾰����n��" << endl;
	cin >> n;
	Init();
	cout << "���������m��" << endl;
	cin >> m;
	cout << "�������뾰��u�� ����v�� u v֮��ľ���w����ʽ������u�� ����v�� ����w" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}
	Travelingbfsopt();
	print();
}

void TravelingSalesmanSpanPro::TSSProTest2()
{
	int u, v, w;																//��������u������v��u v֮��ľ���w
	cout << "�����뾰����n��" << endl;
	cin >> n;
	Init();
	cout << "���������m��" << endl;
	cin >> m;
	cout << "�������뾰��u�� ����v�� u v֮��ľ���w����ʽ������u�� ����v�� ����w" << endl;
	int uArr[] = { 1, 1, 1, 2, 2, 3 };
	int vArr[] = { 2, 3, 4, 3, 4, 4 };
	int wArr[] = { 15, 30, 5, 6, 12, 3 };
	for (int i = 1; i <= m; i++)
	{
		/*cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;*/
		cout << uArr[i - 1] << " " << vArr[i - 1] << " " << wArr[i - 1] << endl;
		g[uArr[i - 1]][vArr[i - 1]] = g[vArr[i - 1]][uArr[i - 1]] = wArr[i - 1];
	}
	Travelingbfsopt();
	print();
}

bool FindPathSpan::findpath(Position s, Position e, Position *& path, int & Pathlen)
{
	if (s.x == e.x && s.y == e.y)																//�ж������յ���û���غ�
	{
		Pathlen = 0;
		return true;
	}
	Position DIR[4], here, next;
	DIR[0].x = 0;																						//����
	DIR[0].y = 1;

	DIR[1].x = 1;																						//����
	DIR[1].y = 0;

	DIR[2].x = 0;																						//����
	DIR[2].y = -1;

	DIR[3].x = -1;																					//����
	DIR[3].y = 0;
	return false;
}
