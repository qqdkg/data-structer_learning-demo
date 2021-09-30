#pragma once
#include<string>
#include<vector>
using std::vector;
using std::string;

int char2int(char c)
{
	int out = 0;
	switch (c)
	{
	case  '0': out = 0; break;
	case	'1': out = 1; break;
	case	'2': out = 2; break;
	case	'3': out = 3; break;
	case	'4': out = 4; break;
	case	'5': out = 5; break;
	case	'6': out = 6; break;
	case	'7': out = 7; break;
	case	'8': out = 8; break;
	case	'9': out = 9; break;
	}
	return out;
}

char int2char(int c)
{
	char out = '0';
	switch (c)
	{
	case  0: out = '0'; break;
	case	1: out = '1'; break;
	case	2: out = '2'; break;
	case	3: out = '3'; break;
	case	4: out = '4'; break;
	case	5: out = '5'; break;
	case	6: out = '6'; break;
	case	7: out = '7'; break;
	case	8: out = '8'; break;
	case	9: out = '9'; break;
	}
	return out;
}

int str2num(string str)
{
	int n = str.length();
	int out = 0;
	int tmp = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		out += tmp * char2int(str.at(i));
		tmp *= 10;
	}
	return out;
}

string num2str(int num)
{
	string str = "";
	vector<char> vec;
	while (num / 10 >= 0)
	{
		if (num == 0)
			break;
		vec.emplace_back(int2char(num % 10));
		num /= 10;
	}
	while (!vec.empty())
	{
		str += vec.back();
		vec.pop_back();
	}

	return str;
}