#ifndef __CHAPTER5
#define __CHAPTER5

/*
*��Ȥѧ�㷨�������£����ݷ���ʵ��
*/


//�������⣨Knapasck Problem��
//0-1��������Ļ��ݷ�ʵ��
class ZOPackBacktrackTank {
private:
	static const int M = 105;
	int i, j, n, W;														//n��ʾn����Ʒ��W��ʾ���ﳵ������
	double w[M], v[M];											//w[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ
	bool x[M];															//x[i]��ʾ��i����Ʒ�Ƿ񱻷��뱳����״̬
	double cw;														//��ǰ����
	double cp;														//��ǰ��ֵ
	double bestp;													//��ǰ���ż�ֵ
	bool bestx[M];													//��ǰ���Ž�
	double Bound(int i);											//�����Ͻ�
	void Backtrack(int t);											//���ݷ�ʵ��
	void Knapsack(double W, int n);						//����һЩ�жϺ��������
public:
	void ZOPBTest();												//�������Ĳ��Խӿ�
};



#endif // !__CHAPTER5

