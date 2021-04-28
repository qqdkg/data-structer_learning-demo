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




