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





