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


//2.6 哈夫曼编码
#define MAXBIT					100
#define MAXVALUE				10000
#define MAXLEAF				30
#define MAXNODE				(MAXLEAF*2-1)

typedef struct {
	double weight;					//权值
	int parent;							//双亲节点
	int lchild;							//左孩子
	int rchild;							//右孩子
	char value;						//该节点表示的字符
} HNodeType;						/*节点结构体*/

typedef struct {
	int bit[MAXBIT];
	int start;
} HCodeType;


/*构造哈夫曼树*/
void dkg_HuffmanTree(HNodeType HuffNode[MAXNODE], int n);
void dkg_HuffmanCode(HCodeType HuffCode[MAXLEAF], int n);
void HuffmanTest();







#endif // !__ALGOGATE_H

