// Helper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Gragh.h"
using namespace std;

int main()
{
	ALGragh G;
	CreateALGragh(G);
	BFS_AL(G, 0);
    return 0;

}

