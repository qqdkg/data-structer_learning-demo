#pragma once
// 一些关于string使用的例子
// string/stringiter1.cpp
//	关于string迭代器的一些应用实例
// 字符串大小写转换
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <regex>
using std::string;
using std::cout;
using std::endl;

void STL_stringUpDown()
{
	string s = { "The zip code of Braunschweig in Germany is 38100" };
	cout << "original: " << s << endl;

	// lowercase all characters
	std::transform(s.cbegin(), s.cend(),
		s.begin(),
		[](char c) {
		return std::tolower(c); 
	});
	cout << "lowered: " << s << endl;

	// uppercase all characters
	std::transform(s.cbegin(),s.cend(),
		s.begin(),
		[](char c) {
		return std::toupper(c);
	});
	cout << "uppered: " << s << endl;

	// search case-insensitive for Germany
	string g("Germany");
	string::const_iterator pos;
	pos = std::search(s.cbegin(), s.cend(),
		g.cbegin(),g.cend(),
		[](char c1, char c2) {
		return std::toupper(c1) == std::toupper(c2); });
	if (pos != s.end()) {
		cout << "subsstring \"" << g << "\" found at indexs "
			<< pos - s.cbegin() << endl;
	}
}

// string iter的另一种应用
void STL_StringIter()
{
	const string hello("Hello, how are you?");
	string s(hello.cbegin(), hello.cend());
	for (const auto &elem : s)
	{
		cout << elem;
	}
	cout << endl;

	// reverse the order of the string
	std::reverse(s.begin(), s.end());
	cout << "reverse: " << s << endl;

	// sort all charactor
	std::sort(s.begin(), s.end());
	cout << "ordered: " << s << endl;

	// remove all duplicates
	std::copy(hello.cbegin(), hello.cend(),
		s.begin());
	s.erase(std::unique(s.begin(), s.end()),
		s.end());
	cout << "no duplicates: " << s << endl;
}


// 将输入的字符串按照数字，小写字母，大写字母，其他字母的顺序输出。
void sor_nlo()
{
	char s[100];
	char num[100];
	char let_l[100];
	char let_h[100];
	char other[100];

	for (int i = 0; i < 100; i++)
	{
		num[i] = 0;
		let_l[i] = 0;
		let_h[i] = 0;
		other[i] = 0;
	}

	int id_num = 0;
	int id_let_l = 0;
	int id_let_h = 0;
	int id_other = 0;
	scanf("%s", s);
	//str(s);

	int n = strlen(s);

	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			num[id_num] = s[i];
			id_num++;
		}
		else if (s[i] >= 65 && s[i] <= 90)
		{
			let_h[id_let_h] = s[i];
			id_let_h++;
		}
		else if (s[i] >= 97 && s[i] <= 122)
		{
			let_l[id_let_l] = s[i];
			id_let_l++;
		}
		else
		{
			other[id_other] = s[i];
			id_other++;
		}

	}

	printf("%s%s%s%s\n", num, let_l, let_h, other);
}


//## 字符串解压缩
//
//###题目
//
//给定一个经过编码的字符串，返回解码后的字符串。
//
//编码规则：
//
//k[encoded_string] ，表示中括号内部的encoded_string正好重复k次。k为整数。
//
//可以认为输入的字符串总是有效的；输入字符串中没有额外的空格，输入的方括号满足格式要求。
//
//此外，可以认为原始数据不含数字，所有数字只表示重复次数k，例如不会出现向3a或者2[4]这样的输入。
//
//**示例1：**
//
//输入：s = "3[a]2[bc]"
//
//输出："aaabcbcbc"
//
//**示例2：**
//
//输入：s = “3[a2[c]]”
//
//输入："accaccacc"
//
//**示例3：**
//
//输入：s = “2[abc]3[cd]ef”
//
//输出：s = "abcabccdcdcdef"
#include<map>
#include<vector>
using std::map;
using std::pair;
using std::vector;
class strUncompress {
	typedef pair<int, string> pis;
public:
	// 解压缩
	string unzip(string str)
	{
		string res = "";
		int num = 0;
		vector<pis> vstack;
		for (auto s : str)
		{
			if (s == '[')
			{
				pis tmp = { num,res };			// 将[ 的数字和字符压栈
				vstack.push_back(tmp);
				res = "";								// 将字符和数字初始化用于处理“[]”内部的信息
				num = 0;
			}
			else if (s == ']')
			{
				pis tmp = vstack[vstack.size()-1];		// 取出栈顶元素
				string last_res = tmp.second;
				int cur_num = tmp.first;
				vstack.pop_back();							// 栈顶出栈
				for (int i = 0; i < cur_num; ++i)
				{
					last_res += res;								// 将最内层"[]"内容的字符串解压缩并与外左外侧的拼接
				}
				res = last_res;
			}
			else if (s >= '0' && s <= '9')
			{
				num = num * 10 + s - '0';				//	处理数字大于10的情况
			}
			else
			{
				res += s;											// 字符串累加
			}
		}
		return res;
	}
};















