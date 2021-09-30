#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int g_conut = 0;
const int NUM = 22;
int str_size = 0;

int BFS(string str, int level, int start_id, int length)
{
	// �Ϸ��Լ��
	if (start_id >= str_size || (start_id + length) >= str_size)
	{
		return -1;
	}
	// ��ֹ����
	if (level == 1)			// level ��0��ʼ
	{
		if (start_id == 1 && length == 2)
		{
			int stop = 1;
		}
		int tmp = atoi(str.c_str());
		if (tmp >= NUM && tmp % NUM == 0)
		{
			g_conut++;
		}
		return 0;
	}

	// ����
	for (int i = start_id; i < str_size; i++)
	{
		for (int j = length; j + i < str_size; j++)
		{
			BFS(str.substr(i, j), level + 1, i, j);
		}
	}

	// ȡ������
	// ������߲���Ҫȡ������Ϊʵ����û�ı䱾�����ݵĹؼ�״̬��
}

int BigNumD22()
{
	string str_num;
	cin >> str_num;

	str_size = str_num.size();
	g_conut = 0;

	BFS(str_num, 0, 0, 0);

	cout << g_conut << endl;

	return 0;
}
