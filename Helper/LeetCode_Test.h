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

// 输入字符串，翻转元音字母位置
// 示例 1：

//输入："hello"
//输出："holle"
//示例 2：

//输入："leetcode"
//输出："leotcede"

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
		cout << "示例" << count << ":";
		cout << "输入：" << elem << endl;
		cout << "输出：" << reverseVowels(elem) << endl;
		cout << endl;
		count++;
	}
}


//给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

//示例 1：
//
//输入：ransomNote = "a", magazine = "b"
//输出：false
//示例 2：
//
//输入：ransomNote = "aa", magazine = "ab"
//输出：false
//示例 3：
//
//输入：ransomNote = "aa", magazine = "aab"
//输出：true
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ransom-note
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<list>
bool canConstruct(string ransomNote, string magazine) {

	// 我打算在中间删除元素，用list比价方便
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

	// 排序
	ranList.sort();
	magList.sort();

	// 比较，然后删除mag中对比成功的元素
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
		cout << "输入：" << "ransomNote = \"" << ran[i] << "\", magzine = \"" << mag[i] << "\"" << endl;
		cout << "输出: " << canConstruct(ran[i], mag[i]) << endl;
	}
}

// 迷你语法分析器

//给定一个用字符串表示的整数的嵌套列表，实现一个解析它的语法分析器。
//
//列表中的每个元素只可能是整数或整数嵌套列表
//
//提示：你可以假定这些字符串都是格式良好的：
//
//字符串非空
//字符串不包含空格
//字符串只包含数字0 - 9、[、 - 、, 、]
//
//
//示例 1：
//
//给定 s = "324",
//
//你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
//示例 2：
//
//给定 s = "[123,[456,[789]]]",
//
//返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
//
//1. 一个 integer 包含值 123
//2. 一个包含两个元素的嵌套列表：
//i.一个 integer 包含值 456
//ii.一个包含一个元素的嵌套列表
//a.一个 integer 包含值 789

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
			// 创建一个嵌套
			v.push_back(NestedInteger());
		}
		else if (c == ',')
		{
			// 说明是一个数组
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



