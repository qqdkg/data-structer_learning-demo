#include "stdafx.h"
#include "SString.h"
#include"iostream"

char & SString::operator[](const int n)
{
	// TODO: 在此处插入 return 语句
	return *(ch + n);
}


int Index_BF(SString S, SString T, int pos)
{
	//求子串T，在主串S中第pos个字符之后出第一次现的位置
	//其中，T非空，1<=pos<=S[0](第0个位置存储字符串长度)
	int i = pos, j = 1, sum = 0;
	while (i <= S[0] && j <= T[0])
	{
		sum++;
		if (S[i] == T[i])							//如果相等，则继续比较后面的字符串
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;							//i返回到上一轮开始比较位置的下一个字符s
			j = 1;										//子串滚回起始
		}
	}
	std::cout << "一共比较了" << sum << "次" << std::endl;
	if (j > T[0])									//匹配成功
		return i - T[0];
	else
		return 0;
}

void get_next(SString T, int* next)
{
	int j = 1;
	int k = 0;
	next[1] = 0;
	while(j < T[0])									//T[0]存储了字符串的长度
	{
		if (k == 0 || T[j] == T[k])
			next[++j] = ++k;
		else
			k = next[k];
	}
}

int Index_KPM(SString S, SString T, int pos)
{
	//利用字符串T的next函数求T在主串S中的位置
	//其中，T非空，1<=pos<=S[0]
	int i = pos;
	int j = 1;
	int *next=NULL;
	get_next(T,next);
	while (i < S[0] && j < T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];			//模式串向右移动
	}
	if (j > T[0])	//匹配成功
		return i - T[0];
	else
		return 0;
}

bool Virus_detection(SString S, SString T)
{
	int i, j;
	SString temp;//记录病毒变种
	for (i = T[0] + 1, j = 1; j <= T[0]; i++, j++)
		T[i] = T[j];
	for (i = 0; i < T[0]; i++)
	{
		temp[0] = T[0];				//病毒变种长度为T[0]
		for (j = 1; j < T[0]; j++)//取出一个病毒变种
			temp[j] = T[i + j];
		if (Index_KPM(S, T, 1))//检测到病毒
			return true;
	}
	return false;
}
