#pragma once
// һЩ����stringʹ�õ�����
// string/stringiter1.cpp
//	����string��������һЩӦ��ʵ��
// �ַ�����Сдת��
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

// string iter����һ��Ӧ��
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


// ��������ַ����������֣�Сд��ĸ����д��ĸ��������ĸ��˳�������
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


//## �ַ�����ѹ��
//
//###��Ŀ
//
//����һ������������ַ��������ؽ������ַ�����
//
//�������
//
//k[encoded_string] ����ʾ�������ڲ���encoded_string�����ظ�k�Ρ�kΪ������
//
//������Ϊ������ַ���������Ч�ģ������ַ�����û�ж���Ŀո�����ķ����������ʽҪ��
//
//���⣬������Ϊԭʼ���ݲ������֣���������ֻ��ʾ�ظ�����k�����粻�������3a����2[4]���������롣
//
//**ʾ��1��**
//
//���룺s = "3[a]2[bc]"
//
//�����"aaabcbcbc"
//
//**ʾ��2��**
//
//���룺s = ��3[a2[c]]��
//
//���룺"accaccacc"
//
//**ʾ��3��**
//
//���룺s = ��2[abc]3[cd]ef��
//
//�����s = "abcabccdcdcdef"
#include<map>
#include<vector>
using std::map;
using std::pair;
using std::vector;
class strUncompress {
	typedef pair<int, string> pis;
public:
	// ��ѹ��
	string unzip(string str)
	{
		string res = "";
		int num = 0;
		vector<pis> vstack;
		for (auto s : str)
		{
			if (s == '[')
			{
				pis tmp = { num,res };			// ��[ �����ֺ��ַ�ѹջ
				vstack.push_back(tmp);
				res = "";								// ���ַ������ֳ�ʼ�����ڴ���[]���ڲ�����Ϣ
				num = 0;
			}
			else if (s == ']')
			{
				pis tmp = vstack[vstack.size()-1];		// ȡ��ջ��Ԫ��
				string last_res = tmp.second;
				int cur_num = tmp.first;
				vstack.pop_back();							// ջ����ջ
				for (int i = 0; i < cur_num; ++i)
				{
					last_res += res;								// �����ڲ�"[]"���ݵ��ַ�����ѹ��������������ƴ��
				}
				res = last_res;
			}
			else if (s >= '0' && s <= '9')
			{
				num = num * 10 + s - '0';				//	�������ִ���10�����
			}
			else
			{
				res += s;											// �ַ����ۼ�
			}
		}
		return res;
	}
};















