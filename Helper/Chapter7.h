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



#endif // !__CHAPTER3_H_
