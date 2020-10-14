#ifndef __CHAPTER6_H
#define __CHAPTER6_H

/*
*��Ȥѧ�㷨�������£���֧�޽編��ʵ�����������������
*/

//0-1��������ķ�֧�޽編ʵ��
typedef struct ShopBagNode
{
	int cp, rp;											//cp��������Ʒ�ܼ�ֵ��rpʣ����Ʒ���ܼ�ֵ
	int rw;												//ʣ������
	int id;												//��Ʒ���
	static const int N = 10;						//���Ԫ����
	bool x[N];											//������
	ShopBagNode();
	ShopBagNode(int _cp, int _rp, int _rw, int _id);
}SBNode;

struct Goods
{
	int value;
	int weight;
};

class ZeroOneBagSpan {
private:
	static const int N = 10;
	int bestp;														//bestp������¼����ֵ
	int W;															//WΪ���ﳵ�������
	int n;																//nΪ��Ʒ�ĸ���
	int sumw;														//sumwΪ������Ʒ��������
	int sumv;														//sumvΪ������Ʒ���ܼ�ֵ
	bool bestx[N];												//���Ž�����
	Goods goods[N];											//�����洢�������Ʒ���ԣ�������ֵ������
	int bfs();														//bfs���������Ӽ����Ĺ����������
public:
	void ZOBSTest();
};


//!!=======���������ȶ���ʵ�ֵ�0-1���������һЩ���
typedef struct ShopBagNodePro{
	int cp;															//��ǰװ�빺�ﳵ����Ʒ��ֵ
	double up;													//��ֵ�Ͻ�
	int rw;															//���ﳵʣ������
	int id;															//��Ʒ���
	const static int N = 10;
	bool x[N];														//ÿ��״̬�ڵ㶼Ҫ����������Ʒ���еķ���״������һ����ʵ��ɵ
	ShopBagNodePro();
	ShopBagNodePro(int _cp, double _up, int _rw, int _id);
}SBNodePro;
bool operator <(const ShopBagNodePro &a, const ShopBagNodePro &b);

typedef struct TempShopObject {
	int id;															//��Ʒ���
	double d;														//��λ�����۸�
}TSObject;

//�����������ȼ���������Ʒ�ĵ�λ�����۸��ɴ�С����
bool cmp(TSObject a1, TSObject a2);				//return a1.d > a2.d


//!!!========ʹ�����ȶ���ʵ�ֵ�0-1��������
class ZeroOneBagSpanPro {
private:
	static const int N = 10;
	bool bestx[N];												//���Ž�����
	int w[N], v[N];												//�������飬���ڴ洢�����������ͼ�ֵ
	Goods goods[N];
	TSObject S[N];
	int bestp;														//����ֵ
	int W;															//�����������
	int n;																//��Ʒ�ĸ���
	int sumw;
	int sumv;
	double Bound(SBNodePro tnode);				//�Ͻ���㺯��
	int priorbfs();												//ʹ�����ȶ��еķ�֧�޽編ʵ��
public:
	void ZOBSPTest();
};

//6.3ʹ�����ȶ��й������ʵ�ֵ���������
typedef struct TravelingSalesmanNode {						//��㶨�壬��¼��ǰ�ڵ�Ľ���Ϣ
	const static int N = 20;
	double cl;														//��ǰ�߹���·������
	int id;															//�ڵ���
	int x[N];														//��¼��ǰ·��
	TravelingSalesmanNode();
	TravelingSalesmanNode(double _cl, int _id);
}TSNode;

//����֮���TSNode�������ȶ���
bool operator < (const TSNode &a, const TSNode &b);

class TravelingSalesmanSpan {
private:
	const static int INF = 1e7;								//��һ���ܴ������Ϊ�����
	const static int N = 20;
	double g[N][N]	;											//���������ͼ�������Ȩͼ���ڽӾ���
	int bestx[N];													//���Ž�����
	double bestl;												//���Ž�
	int n, m;														//�������������
	double Travelingbfs();									//ʹ�����ȶ��еķ�֧�޽磨������ȣ�ʵ�ֵ���������
	void init();
	void print();
	void TSSTest();
public:
	void TSSTest2();
};

//ʹ�÷����½���Ϊ���ȶ��е����ȼ�
typedef struct TsProNode {
	const static int N = 20;
	double cl;																							//��ǰ���߹���·������
	double rl;																							//ʣ��·�����ȵ��½�
	double zl;																							//��ǰ·�����ȵ��½� zl = cl + rl;
	int id;																								//�������
	int x[N];																							//��ǰ�ڵ������
	TsProNode();
	TsProNode(double _cl, double _rl, double _zl, int _id);
}TspNode;

bool operator < (const TspNode &a, const TspNode &b);

class TravelingSalesmanSpanPro {
private:
	const static int INF = 1e7;
	const static int N = 20;
	double g[N][N];																				//�����ͼ���ڽӾ���
	double minout[N];																			//��¼ÿ�����������С����
	double minsum;																				//��¼ÿ��������С����֮��
	int bestx[N];																						//��¼��ǰ����·��
	double	bestl;																					//��¼��ǰ���Ž�
	int n, m;																							//������������
	bool Bound();																					//��ȡ�½�
	double Travelingbfsopt();
	void Init();
	void print();
public:
	void TSSProTest();
	void TSSProTest2();
};

typedef struct PositionNodeTypedef {
	int x;
	int y;
}Position;

class FindPathSpan {
private:
	const static int N = 20;
	int grid[N][N];
	bool findpath(Position s, Position e, Position *&path, int &Pathlen);						//����������Ϊһ��ָ���ʵ��(����)
	void Init(int m, int n);
public:
	void FPSTest();
};





#endif // !__CHAPTER6_H
