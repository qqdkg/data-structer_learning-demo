#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <deque>
using std::string;
using std::pair;
using std::vector;
using std::deque;
using std::cout;
using std::endl;

// �����ַ�������תԪ����ĸλ��
// ʾ�� 1��

//���룺"hello"
//�����"holle"
//ʾ�� 2��

//���룺"leetcode"
//�����"leotcede"

string reverseVowels(string str)
{
	typedef pair<string, int> StrInt;
	typedef deque<StrInt> StrIntVec;
	typedef pair<StrInt, StrInt> compir;

	StrIntVec strInt_vec;
	StrInt strInt_pair;

	string str_vowels = { "aeiouAEIOU" };
	int idx = 0;
	for (auto& elem1 : str){
		for (auto& elem2 : str_vowels){
			if (elem1 == elem2)
			{
				strInt_pair.first = elem1;
				strInt_pair.second = idx;
				strInt_vec.emplace_back(strInt_pair = { strInt_pair });
			}
		}
		++idx;
	}
	StrIntVec strInt_tmp;
	while (!strInt_vec.empty())
	{
		std::swap(strInt_vec.front().second , strInt_vec.back().second);
		strInt_tmp.emplace_back(strInt_vec.front());
		strInt_tmp.emplace_back(strInt_vec.back());
		strInt_vec.pop_front();
		if (!strInt_vec.empty())
		{
			strInt_vec.pop_back();
		}
	}

	for (auto &elem : strInt_tmp)
	{
		str.at(elem.second) = *elem.first.c_str();
	}
	return str;
}

void reverseVowels_Test()
{
	vector<string> strVec = { {"hello"},{"leetcode"},{"badbad"},{"index"},{"aA"} };
	int count = 1;
	for (auto &elem : strVec)
	{
		cout << "ʾ��" << count << ":";
		cout << "���룺" << elem << endl;
		cout << "�����" << reverseVowels(elem) << endl;
		cout << endl;
		count++;
	}
}


//����һ�������(ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ����ɵڶ����ַ��� magazines ������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��
//
//(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼����־�ַ����е�ÿ���ַ�ֻ����������ַ�����ʹ��һ�Ρ�)

//ʾ�� 1��
//
//���룺ransomNote = "a", magazine = "b"
//�����false
//ʾ�� 2��
//
//���룺ransomNote = "aa", magazine = "ab"
//�����false
//ʾ�� 3��
//
//���룺ransomNote = "aa", magazine = "aab"
//�����true
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/ransom-note
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
#include<list>
bool canConstruct(string ransomNote, string magazine) {

	// �Ҵ������м�ɾ��Ԫ�أ���list�ȼ۷���
	std::list<char> ranList;
	std::list<char> magList;
	for (auto elem : ransomNote)
	{
		ranList.push_back(elem);
	}
	for (auto elem : magazine)
	{
		magList.push_back(elem);
	}

	// ����
	ranList.sort();
	magList.sort();

	// �Ƚϣ�Ȼ��ɾ��mag�жԱȳɹ���Ԫ��
	for (auto &elem1 : ranList)
	{
		bool flag = false;
		decltype(magList)::iterator pos;
		for (pos = magList.begin(); pos != magList.end(); ++pos)
		{
			if (elem1 == *pos)
			{
				magList.erase(pos);
				flag = true;
				break;
			}
		}

		if (false == flag)
		{
			return flag;
		}
	}
	return true;
}

void canConstructTest()
{
	vector<string> ran = { {"a"},{"aa"},{"aa"} ,{"dkg"} };
	vector<string> mag = { {"b"},{"ab"},{"aab"}, {"dog is the king of ground!"} };

	for (int i = 0; i < ran.size(); ++i)
	{
		cout << "���룺" << "ransomNote = \"" << ran[i] << "\", magzine = \"" << mag[i] << "\"" << endl;
		cout << "���: " << canConstruct(ran[i], mag[i]) << endl;
	}
}

// �����﷨������

//����һ�����ַ�����ʾ��������Ƕ���б�ʵ��һ�����������﷨��������
//
//�б��е�ÿ��Ԫ��ֻ����������������Ƕ���б�
//
//��ʾ������Լٶ���Щ�ַ������Ǹ�ʽ���õģ�
//
//�ַ����ǿ�
//�ַ����������ո�
//�ַ���ֻ��������0 - 9��[�� - ��, ��]
//
//
//ʾ�� 1��
//
//���� s = "324",
//
//��Ӧ�÷���һ�� NestedInteger ��������ֻ��������ֵ 324��
//ʾ�� 2��
//
//���� s = "[123,[456,[789]]]",
//
//����һ�� NestedInteger �������һ��������Ԫ�ص�Ƕ���б�
//
//1. һ�� integer ����ֵ 123
//2. һ����������Ԫ�ص�Ƕ���б�
//i.һ�� integer ����ֵ 456
//ii.һ������һ��Ԫ�ص�Ƕ���б�
//a.һ�� integer ����ֵ 789

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger();

	// Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
 };

NestedInteger deserialize(string s) {
	vector<NestedInteger> v;
	string curr = "";
	for (char c : s)
	{
		if (c == '[')
		{
			// ����һ��Ƕ��
			v.push_back(NestedInteger());
		}
		else if (c == ',')
		{
			// ˵����һ������
			if (!curr.empty())
			{
				v.back().add(stoi(curr));
				curr.clear();
			}
		}
		else if (c == ']')
		{
			if (!curr.empty())
			{
				v.back().add(stoi(curr));
				curr.clear();
			}
			if (v.size() > 1)
			{
				NestedInteger back = v.back();
				v.pop_back();
				v.back().add(back);
			}
		}
		else
		{
			curr.append(1, c);
		}
	}
	if (!curr.empty())
	{
		v.push_back(NestedInteger(stoi(curr)));
		curr.clear();
	}
	return v.back();
}



