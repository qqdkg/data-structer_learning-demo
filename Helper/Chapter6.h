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







#endif // !__CHAPTER6_H
