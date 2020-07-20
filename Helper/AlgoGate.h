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






#endif // !__ALGOGATE_H

