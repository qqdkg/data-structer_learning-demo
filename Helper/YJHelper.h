#ifndef __YJHELPE_H_
#define __YJHELPE_H_

#include <string>
#include <queue>
#include <stack>

//创建于2020-10-14
//主要用于尹洁师姐面试大华的大题助攻,虽然我当时实际上制作出了第一题，第三题次日做出来了，如果时间够的话，这种题是可以做出来的

void HelloWorld();

//题目：第一大题
//描述：现有一列春运火车，如果将第M节车厢的人数逐一减去后续车厢的人数（M+1,M+2,...,N-1,N）
//				中的人数，可以得到一组载客数差值
typedef struct TrainTypedef {
	int order;														//车厢编号
	int num;														//车厢载客数
}TrNode;

class FindMaxSub {
private:
	const static int N = 20;
	TrNode x[N];																		//车厢序号数组
	int n;																				//人数
	int Find();
	void Init();
public:
	void FMSTest();
};

//题目：第二大题
//描述：以下程序实现将输入的英文文本中的每一个单词的首字母转换成大写的形式。例如：输入"welcome to Dahua"，
//				输出为“Wellcome To Dahua”。
void test(char *p);
void mainTest();

//题目：第三大题
//描述：有一个简单的加密规则，秘钥固定位“ABCDabcd”,顺序也固定。使用该加密规则对一段字符串进行加密
//				被加密的字符串限定为英文大小写字母和数字，不考虑其他字符。
//加密步骤：
//			1.将被编码字符串的每个字符根据ASCII码数值转化为对应的二进制，如果长度不是8个bit，则高位补0。
//				如001010变成00001010。通过这个步骤我们把字符串变成了二进制串
//			2.从二进制串中，每次去3位分成一个小组（为什么是3位，因为2的3次方等于，可以表示ABCDabcd中所有字符的位置）
//				将每个小组二进制串转化为十进制，这个十进制是“索引值”，然后在ABCDabcd中查找对应搜索位置的字符。
//			3.注意：最后一次取3个bit可能要特殊处理，如果最后一个小组的长度小于3bit，则在低位补0

typedef struct EncodeNode {
	char ch;												//字符
	int ascii;												//字符对应的ASCII码
	int bin[8];												//字符对应的的二进制数，如果不满8bit则高位补0
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
	int n;																					//字符数量
	int ncode;																			//编码侯的字符数量
	eNode str[N];																	//输入结构体数组，包含：{输入字符:ch，字符对应的ASCII码:ascii，八位二进制数组:bin[8]}
	int binArr[8 * N];																//正规化之后的二进制编码序列
	char outch[3 * N];																//用于存储输出值的字符数组
	eKey enumKey;
	void Init();																			//初始化输入结构体数组
	void Encoding();																//编码
public:
	void ETest();																		//入口程序
};


//新华三笔试题第一题
//请字符串压缩，如：f :“abcccccDD” -> "abc5D2"
//																		5个c 2个D
class Solution {
public:
	std::string MyCompress(std::string pcStr);
	std::string dkgCompress(std::string pcStr);															//昨天栽在sting的操作上了，今天尝试一下
	void Test();
};

//新华三笔试题第二题
//寻找一个整数的所有因数中最中间的那个数
//举例：
//16有5个因数，分别是1,2,4,8,16.																			//最中间的是4
//12有6个因数，分别是1,2,3,4,6,12.																		//最中间的是4
class findMidTank {
private:
	long long MidFactor(long long llVal);
public:
	void findMidTest();
};


//趣学算法群的一个问题
class PalindromeTower {
private:
	const static int N = 10;
	char map[20][20];																										//绘图空间
	char pdArr[N];																											//回文内容数组
	int index;																													//指向回文数组中当前数组
	std::queue<char> left;																									//左侧字符，一个栈
	std::stack<char> right;																									//右侧字符，一个队列
	int n;
	void Init();
public:
	void ShowPalindromeTower();																					//显示回文塔（b）
};

class NumTower {
private:
	const static int N = 20;
	int n;																															//数字塔最大数字
	void Init();
	void ShowRows(int num);																							//展示某一行
public:
	void showNumTower();
};

class InterestingTower {
private:
	const static int N = 20;
	std::queue<char> q;
	void Init();
public:
	void ShowInteresting();
};







#endif // !__YJHELPE_H_

