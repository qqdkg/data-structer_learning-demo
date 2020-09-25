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

//���令���ӣ���������⣩
class BigestRollTank {
private:
	static const int N = 100;
	int a[N][N];														//���ڽӾ����ʾ��ͼ
	bool x[N];															//�Ƿ񽫵�i������������
	bool bestx[N];													//��¼����ֵ
	int bestn;															//��¼����ֵ
	int cn;																//��ǰ�ѷ������еĽڵ�����
	int n, m;															//nΪͼ�еĽ������mΪͼ�еı���
	bool Place(int t);
	void Backtrack(int t);
public:
	void BigestRollTest();
};

//��ͼ��ɫ���⣨�����֯�ṹΪһ��m������
class ColorMapQuesTank {
private:
	static const int Mx = 50;
	int x[Mx];															//��������Ԫ�飩
	int map[Mx][Mx];												//ͼ���ڽӾ���
	int sum = 0;														//��¼��ĸ����ı���
	int n, m, edge;													//�ڵ�������ɫ��������
	void CreatMap();												//��������ͨ����ͼ�����ڽӾ���
	bool OK(int t);													//Լ������
	void Backtrack(int t);											//��������
public:
	void CMQTest();
};


//N�ʺ�����
class NQueenTank {
private:
	static const int M = 105;
	int n;																	//n��ʾn���ʺ�
	int x[M];															//x[i]����ʾ��i���ʺ���ڵ�i�еĵ�x[i]��
	int count = 0;
	bool Place(int t);												//�жϵ�t���ʺ��ܷ�����ڵ�i��λ��
	void Backtrack(int t);											//���ݷ���������
public:
	void NQueenTest();
};

//���żӹ�˳�����⣨��Ŀռ�ṹΪһ����������
//��Ҫ�����Ž��������޽��������ڽ�ռ���һ����������ǰ���£���ռ���ÿ�����ж���һ�����н⣬���Բ���Ҫ��Լ��������

//��¼��������ʵ��ʾ��
class ArrayTree {
private:
	const static int MX = 50;
	int x[MX];
	int n;
	void myarray(int t);
public:
	void ArrayTreeTest();
};

struct BPOnode
{
	int x, y;								//��������ڵ�һ̨�����ϼӹ���ʱ����ڵڶ�̨�����ϼӹ���ʱ��
	int id;
};

//=======!!!
//���ڴ���sort��Ϊ�Ƚ����ݵĺ�������Ϊ����������������һ����ĳ�Ա������������˽�л��ǹ���������
bool BPOcmp(BPOnode a, BPOnode b);					//�ȽϺ���������ֵΪ�棬a����bǰ��

class BestProcessOrderTank {
private:
	const static int INF = 0x3f3f3f3f;
	const static int MX = 1000;
	int n;																	//�������Ŀ
	int bestf;															//��ǰ���żӹ�ʱ��
	int f1, f2;															//��ǰ��һ̨�����͵ڶ�̨������ɼӹ���ʱ��
	int x[MX], bestx[MX];
	BPOnode T[MX];
	void Backtrack(int t);
public:
	void BPOTest();
	void BPOTest_Pro();											//ʹ�ñ����������õĽ��۵���ʵ��
};


#endif // !__CHAPTER5

