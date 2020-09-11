#ifndef __CHAPTER5
#define __CHAPTER5

/*
*��Ȥѧ�㷨�������£����ݷ���ʵ��
*/


//�������⣨Knapasck Problem��
//0-1��������Ļ��ݷ�ʵ��

struct ObjectNode														//������Ʒ�ṹ�壬������Ʒ����ź͵�λ������ֵ
{
	int id;																//��Ʒ���
	double d;															//��λ������ֵ
};

bool cmp(ObjectNode a1, ObjectNode a2);

class ZOPackBacktrackTank {
private:
	/*���ݳ�Ա*/
	static const int M = 105;
	int i, j, n, W;														//n��ʾn����Ʒ��W��ʾ���ﳵ������
	double w[M], v[M];											//w[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ
	bool x[M];															//x[i]��ʾ��i����Ʒ�Ƿ񱻷��뱳����״̬
	double cw;														//��ǰ����
	double cp;														//��ǰ��ֵ
	double bestp;													//��ǰ���ż�ֵ
	bool bestx[M];													//��ǰ���Ž�
	/*������Ա*/
	double Bound(int i);											//�����Ͻ�
	double BoundPro(int i);									//�Ż��汾���Ͻ��޽纯�������Ӽ�֦����
	void Backtrack(int t);											//���ݷ�ʵ��
	void Knapsack(double W, int n);						//����һЩ�жϺ��������
	void KnapsackPro(double W, int n);					//�ֻ��汾����ִ�к�������Ҫ��������������������
public:
	void ZOPBTest();												//�������Ĳ��Խӿ�
	void ZOPBTestPro();
};



#endif // !__CHAPTER5

