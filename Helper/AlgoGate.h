#ifndef __ALGOGATE_H
#define __ALGOGATE_H



//2.4高级钟点秘书问题
typedef struct MeetType {
	int beg;		//会议开始时间
	int end;		//会议结束时间
	int num;	//记录会议的编号
}MeetType;


class setMeet {
public:
	void init();
	void solve();
private:
	int ans = 0;
	const int n = 10;
};

//2.5 最短路径
void Dijkstra(int u);
void TestDijkstra();
void findPath(int u);






#endif // !__ALGOGATE_H

