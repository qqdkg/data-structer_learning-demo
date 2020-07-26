#ifndef __ALGOGATE_H
#define __ALGOGATE_H



//2.4�߼��ӵ���������
typedef struct MeetType {
	int beg;		//���鿪ʼʱ��
	int end;		//�������ʱ��
	int num;	//��¼����ı��
}MeetType;


class setMeet {
public:
	void init();
	void solve();
private:
	int ans = 0;
	const int n = 10;
};

//2.5 ���·��
void Dijkstra(int u);
void TestDijkstra();
void findPath(int u);


//2.6 ����������
#define MAXBIT					100
#define MAXVALUE				10000
#define MAXLEAF				30
#define MAXNODE				(MAXLEAF*2-1)

typedef struct {
	double weight;					//Ȩֵ
	int parent;							//˫�׽ڵ�
	int lchild;							//����
	int rchild;							//�Һ���
	char value;						//�ýڵ��ʾ���ַ�
} HNodeType;						/*�ڵ�ṹ��*/

typedef struct {
	int bit[MAXBIT];
	int start;
} HCodeType;


/*�����������*/
void dkg_HuffmanTree(HNodeType HuffNode[MAXNODE], int n);
void dkg_HuffmanCode(HCodeType HuffCode[MAXLEAF], int n);
void HuffmanTest();







#endif // !__ALGOGATE_H

