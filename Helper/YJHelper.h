#ifndef __YJHELPE_H_
#define __YJHELPE_H_

//������2020-10-14
//��Ҫ��������ʦ�����Դ󻪵Ĵ�������,��Ȼ�ҵ�ʱʵ�����������˵�һ�⣬����������������ˣ����ʱ�乻�Ļ����������ǿ�����������

void HelloWorld();

//��Ŀ����һ����
//����������һ�д��˻𳵣��������M�ڳ����������һ��ȥ���������������M+1,M+2,...,N-1,N��
//				�е����������Եõ�һ���ؿ�����ֵ
typedef struct TrainTypedef {
	int order;														//������
	int num;														//�����ؿ���
}TrNode;

class FindMaxSub {
private:
	const static int N = 20;
	TrNode x[N];																		//�����������
	int n;																				//����
	int Find();
	void Init();
public:
	void FMSTest();
};

//��Ŀ���ڶ�����
//���������³���ʵ�ֽ������Ӣ���ı��е�ÿһ�����ʵ�����ĸת���ɴ�д����ʽ�����磺����"welcome to Dahua"��
//				���Ϊ��Wellcome To Dahua����
void test(char *p);
void mainTest();

//��Ŀ����������
//��������һ���򵥵ļ��ܹ�����Կ�̶�λ��ABCDabcd��,˳��Ҳ�̶���ʹ�øü��ܹ����һ���ַ������м���
//				�����ܵ��ַ����޶�ΪӢ�Ĵ�Сд��ĸ�����֣������������ַ���
//���ܲ��裺
//			1.���������ַ�����ÿ���ַ�����ASCII����ֵת��Ϊ��Ӧ�Ķ����ƣ�������Ȳ���8��bit�����λ��0��
//				��001010���00001010��ͨ������������ǰ��ַ�������˶����ƴ�
//			2.�Ӷ����ƴ��У�ÿ��ȥ3λ�ֳ�һ��С�飨Ϊʲô��3λ����Ϊ2��3�η����ڣ����Ա�ʾABCDabcd�������ַ���λ�ã�
//				��ÿ��С������ƴ�ת��Ϊʮ���ƣ����ʮ�����ǡ�����ֵ����Ȼ����ABCDabcd�в��Ҷ�Ӧ����λ�õ��ַ���
//			3.ע�⣺���һ��ȡ3��bit����Ҫ���⴦��������һ��С��ĳ���С��3bit�����ڵ�λ��0

typedef struct EncodeNode {
	char ch;												//�ַ�
	int ascii;												//�ַ���Ӧ��ASCII��
	int bin[8];												//�ַ���Ӧ�ĵĶ����������������8bit���λ��0
}eNode;

typedef enum Encodekey {
	ch_A = 0,
	ch_B = 1,
	ch_C = 2,
	ch_D = 3,
	ch_a = 4,
	ch_b = 5,
	ch_c = 6,
	ch_d = 7
}eKey;

class EncodeingTank {
private:
	const static int N = 100;
	int n;																					//�ַ�����
	int ncode;																			//�������ַ�����
	eNode str[N];																	//����ṹ�����飬������{�����ַ�:ch���ַ���Ӧ��ASCII��:ascii����λ����������:bin[8]}
	int binArr[8 * N];																//���滯֮��Ķ����Ʊ�������
	char outch[3 * N];																//���ڴ洢���ֵ���ַ�����
	eKey enumKey;
	void Init();																			//��ʼ������ṹ������
	void Encoding();																//����
public:
	void ETest();																		//��ڳ���
};



#endif // !__YJHELPE_H_

