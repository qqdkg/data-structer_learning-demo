#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "AlgoGate.h"
using namespace std;



//2.4高级钟点秘书问题

MeetType meet[1000];

void setMeet::init()
{
	int begArr[10] = {3,1,5,2,5,3,8,6,8,12};
	int endArr[10] = {6,4,7,5,9,8,11,10,12,14};
	cout << "会议总次数n为：" << n << endl;
	cout << "会议的开始和结束时间为：" << endl;
	cout << "会议编号" << "  会议开始时间" << "  会议结束时间" << endl;
	for (int i = 0; i < n; i++)
	{
		meet[i].beg = begArr[i];
		meet[i].end = endArr[i];
		meet[i].num = i + 1;
		cout << "  " << meet[i].num << "\t\t" << meet[i].beg << "\t\t" << meet[i].end << endl;
	}
}

//用于sort的比较函数
bool cmp(MeetType x, MeetType y)
{
	if (x.end == y.end)
		return x.beg > y.beg;
	return x.end < y.end;
}


void setMeet::solve()
{
	sort(meet, meet + n, cmp);
	int i;
	cout << endl;
	cout << "排序之后的会议时间如下:" << endl;
	cout << "会议编号" << "  会议开始时间" << "  会议结束时间" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "  " << meet[i].num << "\t\t" << meet[i].beg << "\t\t" << meet[i].end << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << "选择的会议的过程：" << endl;
	cout << "  选择第" << meet[0].num << "个会议" << endl;			//选中第一个会议
	ans = 1;
	int last = meet[0].end;																	//记录这一个会议的结束时间
	for (i = 1; i < n; i++)
	{
		if (meet[i].beg >= last)
		{
			//如果会议i的开始时间大于等于选中的最后一个会议的结束时间
			ans++;
			last = meet[i].end;
			cout << "  选择第" << meet[i].num << "个会议" << endl;
		}
	}
	cout << "最多可以安排" << ans << "个会议" << endl;

}

