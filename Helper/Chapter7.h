#ifndef __CHAPTER3_H_
#define __CHAPTER3_H_

//��7�£����Թ滮������

//����Ч��������⣬ʹ�õ������㷨
//�������㷨����Ա�׼�����Թ滮�����ͨ�ýⷨ
//��Ҫ�Լ���ʵ�����������������������������ת��ɵ����α�������м���

class BestBenefitTank {
private:
	const static int N = 20;
	float kernel[N][N];															//���ڴ洢�����α�Ķ�ά����
	char FJL[N];																		//�ǻ�������
	char JL[N];																			//��������
	int n, m;
	void print();
	void DCXA();
public:
	void BBTTest();
	void BBTTest2();
};

//���������-�������·�㷨��Shortest Augument Path��
class NetFlowSapTank {
private:
	const static  int N = 20;
	const static int INF = (1 << 30) - 1;
	int g[N][N];														//�������磨��ʼʱ����Ϊ������
	int f[N][N];														//ʵ�����磨��ʼʱ����Ϊ0����
	int pre[N];															//ǰ������
	bool vis[N];														//��������
	int n, m;
	bool bfs(int s, int t);
	int EK(int s, int t);
	void print();
public:
	void NFSTTest();
};

//ʹ���������ʽʵ���ڽӱ�
typedef struct Vertex {
	int first;
}Vertex;

typedef struct Edge {
	int v, next;
	int cap, flow;
}Edge;

//ʹ��������ǩ˼·���������·�㷨
class ISAPTank {
private:
	const int inf = 0x3fffffff;
	const static int N = 100;
	const static int M = 10000;
	int top;
	int h[N];															//h[]�������¼ÿ�����ĸ߶ȣ��ȵ�������̾���
	int pre[N];															//pre[]�����¼��ǰ����ǰ����,pre[v] = i;��ʾ���vǰ����Ϊi��������·�����
	int g[N];															//g[]�����¼�߶ȣ��������̾��룩Ϊh[]�Ľڵ�ĸ������磺g[3] = 1��ʾ�߶�3�Ľ�����Ϊ1��
	Vertex V[N];														//��������
	Edge E[M];														//������
	void init();
	void add_edge(int u, int v, int c);						//������
	void add(int u, int v, int c);								//����������
	void set_h(int t, int n);										//��ߺ���
	int Isap(int s, int t, int n);									//�������������·�㷨��Imporved Shortest Argument Path��
	void printg(int n);												//��������ڽӱ�
	void printflow(int n);											//���ʵ����
public:
	void ISAPTest();												//������ں���
};


#endif // !__CHAPTER3_H_
