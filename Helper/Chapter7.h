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



#endif // !__CHAPTER3_H_
