#pragma once

#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
#include <memory>
#include "print.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::for_each;

// cont/refsem1.cpp
class Item {
private:
	std::string m_name;
	float m_price;
public:
	Item(const std::string & name, float p = 0) : m_name(name), m_price(p){
	}
	std::string getName() const {
		return m_name; 
	}
	void setName(const std::string& name){
		m_name = name;
	}
	float getPrice() const {
		return m_price;
	}
	void setPrice(float p) {
		m_price = p;
	}
};

template<typename Coll>
void PrintItem(const std::string & msg, const Coll & coll) 
{
	std::cout << msg << std::endl;
	for (const auto& elem : coll)
	{
		std::cout << " " << elem->getName() << ": " << elem->getPrice() << std::endl;
	}
}

void ItemTest() {
	// two different collection sharing Items
	typedef std::shared_ptr<Item> ItemPtr;
	std::set<ItemPtr> allItems;
	std::deque<ItemPtr> bestsellers;


	// insert object into the collections
	// - bestseller are in both collections
	bestsellers = { ItemPtr(new Item("Kong Yize",20.10)),
							ItemPtr(new Item("A Midsummer Night's Dream",14.99)),
							ItemPtr(new Item("The Maltese Falcon",9.88)) };

	allItems = {	ItemPtr(new Item("Water", 0.44)),
						ItemPtr(new Item("Pizza", 2.22)) };
	allItems.insert(bestsellers.begin(), bestsellers.end());

	// print content of both collections
	PrintItem("bestsellers:", bestsellers);
	PrintItem("all:", allItems);

	std::cout << std::endl;

	// double price of bestseller
	for_each	(bestsellers.begin(), bestsellers.end(), 
					[]	(shared_ptr<Item>& elem) {
						elem->setPrice(elem->getPrice() * 2);
	});

	// replace second bestseller by first item with name "Pizza"
	bestsellers[1] = *(std::find_if(allItems.begin(), allItems.end(), 
		[](shared_ptr<Item> elem) {
		return elem->getName() == "Pizza";
	}));

	// set price of first bestseller
	bestsellers[0]->setPrice(44.77);
	
	// print content of both collections
	PrintItem("bestsellers:", bestsellers);
	PrintItem("all:", allItems);

}


// cont/array1.cpp
#include <array>
#include <functional>
#include <numeric>
using std::array;

void ArrayTest()
{
	// create arrat with 10 ints
	array<int, 10> a = { 11, 22, 33, 44 };
	
	PRINT_ELEMENTS(a);

	// modify last two elements
	a.back() = 99999;
	a[a.size() - 2] = 42;
	PRINT_ELEMENTS(a);

	// process sum of all elements
	cout << "sum : " 
		<< std::accumulate(a.begin(), a.end(), 0)
		<< endl;

	// negate all elements
	std::transform(a.begin(), a.end(),
		a.begin(),
		std::negate<int>());

	PRINT_ELEMENTS(a);
}

// cont/setcmp1.cpp

#include <set>
using std::set;

// type for runtime sorting criterion
class RuntimeCmp {
public:
	enum cmp_mode { normal, reverse };
private:
	cmp_mode mode;
public:
	// constructior for sorting criterion
	// - default criterion use value normal
	RuntimeCmp(cmp_mode m = normal) : mode(m) {
	}
	// comparison of elements
	// - memberfunction of any element type
	template <typename T>
	bool operator() (const T &t1, const T & t2) const {
		return mode == normal ? t1 < t2 : t2 < t1;
	}
	// comparsion of sorting criteria
	bool operator== (const RuntimeCmp & rc) const {
		return mode == rc.mode;
	}
};

// type of set that use this that use this criterion
typedef set<int, RuntimeCmp> IntSet;

void SetTest()
{
	// creat fill and print with normal sorting element order
	// - using default sorting criterion
	IntSet coll1 = { 4, 7, 5, 1, 6, 2, 5 };
	PRINT_ELEMENTS(coll1, "coll1: ");

	// creating sorting criterion with reverse element order
	RuntimeCmp reverse_order(RuntimeCmp::reverse);

	// creat fill and print with reverse sorting element order
	IntSet coll2(reverse_order);
	coll2 = { 4,7, 5, 1, 6, 2, 5 };
	PRINT_ELEMENTS(coll2, "coll2: ");

	// assign elements  and sorting criterion
	coll1 = coll2;
	coll1.insert(3);
	PRINT_ELEMENTS(coll1, "coll1: ");

	// to make sure  weather the type of criterion method is same between coll1 and coll2
	if (coll1.value_comp() == coll2.value_comp()) {
		std::cout << "coll1 and coll2 have the same sorting criterion" << std::endl;
	}
	else
	{
		std::cout << "coll2 and coll2 have a different sorting criterion" << std::endl;
	}

}

// cnt/map.cpp
#include <map>
using std::map;
using std::string;
using std::pair;

void mapTest_lambda()
{
	map<string, double> coll{	{ "tim", 9.9 }, 
												{ "strippi", 11.77 } };

	// square the value of each element:
	for_each (coll.begin(),coll.end(), 
		[](pair<const string, double> & elem) {
		elem.second *= elem.second;
	});

	// print each element
	for_each(coll.begin(), coll.end(), 
		[](const pair< string, double> &elem) {
		cout << elem.first << ": " << elem.second << endl;
	});

}

// create map / associative array
// - keys are strings
// - values are floats
typedef map<string, float> StringFlateMap;
#include <iomanip>
template<typename M>
void PrintMap(M & map) {
	cout << std::left;
	 typename M::iterator pos;
	for (pos = map.begin(); pos != map.end(); ++pos)
	{
		cout << "stocks: " << std::setw(12) << pos->first
			<< "prices: " << pos->second << endl;
	}
}

// use map as an associate array

void mapTest_associate()
{
	StringFlateMap stocks;										// empty container
	// inster elements
	stocks["BAFS"] = 369.50;
	stocks["VW"] = 413.50;
	stocks["Diamler"] = 819.00;
	stocks["BMW"] = 834.00;
	stocks["Siemens"] = 842.2;

	// print elements
	PrintMap<StringFlateMap>(stocks);
	cout << endl;

	// boom(all price doubled)
	StringFlateMap::iterator pos;
	for (pos = stocks.begin(); pos != stocks.end(); ++pos)
	{
		pos->second *= 2;
	}

	// print all elements
	PrintMap<StringFlateMap>(stocks);
	cout << endl;

	// rename key from "VW" to "Volkswagen"
	// - provided only by exchanging elements
	stocks["VolksWagen"] = stocks["VW"];
	stocks.erase("VW");

	//print 
	PrintMap<StringFlateMap>(stocks);
}


// use multimap as dictionary
using std::multimap;
using std::ios;
void mapTest_dictionary ()
{
	// create multimap as string / string dictionary
	multimap<string, string> dict;

	// insert some elements in random order
	dict.insert({
	{"day", "Tag"} , {"strange","fremd"}, 
	{"car","Auto"} , {"smart","elegant"}, 
	{"trait","Merkma"}, {"strange","seltsam"}, 
	{"smart","raffiniert"}, {"smart","klug"}, 
	{"clever","raffiniert"}
	});

	// print elements
	cout.setf(std::ios::left, std::ios::adjustfield);
	cout << ' ' << std::setw(10) << "English" << "geramn " << endl;
	cout << std::setfill('-') << std::setw(20) << ""
		<< std::setfill(' ') << endl;
	for (const auto &elem : dict)
	{
		cout << ' ' << std::setw(10) << elem.first
			<< elem.second << endl;
	}
	cout << endl;

	// print all value for key"smart"
	string word("smart");
	cout << word << ":" << endl;
	for (auto & const pos = dict.lower_bound(word); pos != dict.upper_bound(word); ++pos)
	{
		cout << "    " << pos->second << endl;
	}

	// print all key for "raffiniert "
	word = ("raffiniert");
	cout << word << ": " << endl;
	for (auto & const pos : dict)
	{
		if (pos.second == word)
		{
			cout << "    " << pos.first << endl;
		}
	}
}


// using find_if search key or value
#include <utility>

void mapTest_FindIf()
{
	// map with keys as key and value
	// - initializing keys and values are automatically converted to float
	map<float, float> coll = { {1,7}, {2,4}, {3,2}, {4,3},
	{5,6}, {6,1}, {7,3} };

	// search an element with key 3.0 (logarithmic complexity)
	auto posKey = coll.find(3.0);
	if (posKey != coll.end())
	{
		cout << "key 3.0 found ( "
			<< posKey->first << " : "
			<< posKey->second << " )" << endl;
	}

	auto posVal = std::find_if(coll.begin(), coll.end(), 
		[](const pair<float, float> &elem) {
		return elem.second == 3.0;
	});
	if (posVal != coll.end())
	{
		cout << "value 3.0 found ( "
			<< posVal->first << " : "
			<< posVal->second << " )" << endl;
	}
}


// Generaly ussage for map
#include <cctype>
using std::toupper;

// function object to compare string
// - allows you to set the comparsion criterion at runtime
// - allows you to compare case insensitive
class RunTimeStringCmp {
public:
	// constant for the comparsion criterion
	enum cmp_mode {normal, nocase};

private:
	// acctural comparison mode
	const cmp_mode mode;

	// auxiliary (辅助) function to compare case insensitive
	static bool nocase_compare(char ch1, char ch2){
		return toupper(ch1) < toupper(ch2);
	}
public:
	// constructor initializes the comparison criterion
	RunTimeStringCmp(cmp_mode m = normal) : mode(m) {
	}

	// the comparison
	bool operator() (const string &s1, const string &s2) const {
		if (mode == normal)
		{
			return s1 < s2;
		}
		else
		{
			return std::lexicographical_compare(s1.begin(), s1.end(),
				s2.begin(), s2.end(),
				nocase_compare);
		}
	}
};

// container type:
// - map with
//		- string keys
//		- string value
//		- the special comparison object type
typedef map<string, string, RunTimeStringCmp> StringStringMap;

// function that fills and print such containers
void fillAndPrint(StringStringMap & coll) {
	coll["Deutschland"] = "Germany";
	coll["deutschland"] = "German";
	coll["Haken"] = "snag";
	coll["arbeiten"] = "work";
	coll["Hund"] = "dog";
	coll["gehen"] = "go";
	coll["Unternehmen"] = "enterprise";
	coll["unternehmen"] = "undertake";
	coll["gehen"] = "walk";
	coll["Bestatter"] = "undertaker";

	// print elements
	cout.setf(ios::left, ios::adjustfield);
	for (const auto & elem : coll){
		cout << std::setw(15) << elem.first << " "
			<< elem.second << endl;
	}
	cout << endl;
}

void mapTest_General()
{
	// creater a container with the default comparison criterion
	StringStringMap coll1;
	fillAndPrint(coll1);

	// create an object for case-insensitive comparisons
	RunTimeStringCmp ignorcase(RunTimeStringCmp::nocase);

	// create a container with the default comparsion criterion
	StringStringMap coll2(ignorcase);
	fillAndPrint(coll2);
}


// 关于unordered_set一类的无序泛型容器的使用例子
// cont/unordset1.cpp

#include <unordered_set>
#include <numeric>
using std::unordered_set;

void unordSet_Test()
{
	// create and initialize unordered set
	unordered_set<int> coll = { 1,3,5,7,11,13,17,19,77 };
	
	// print elements
	// - elements are in arbitrary order
	PRINT_ELEMENTS(coll);

	// insert some additional elements
	// - might cause rehashing and create different order
	coll.insert({ -7,17,33,-11,17,19,1,13 });
	PRINT_ELEMENTS(coll);

	// remove element with specific value
	coll.erase(33);


	// insert sum of all existing elements
	coll.insert(std::accumulate(coll.begin(), coll.end(), 0));
	PRINT_ELEMENTS(coll);

	// check if value 19 is in the set
	if (coll.find(19) != coll.end())
	{ 
		cout << "19 is avaliable" << endl;
	}


	// remove all negative values
	unordered_set<int>::iterator pos;
	for (pos = coll.begin(); pos != coll.end(); )
	{
		if (*pos < 0)
		{
			pos = coll.erase(pos);
		}
		else
		{
			++pos;
		}
	}
	PRINT_ELEMENTS(coll);
}


// 针对unordered的容器提供自定义hash函数和等价准则的例子
// cnt/hashfunc1.cpp
#include "hashval.h"
class Customer {
private:
	string fname;
	string lname;
	long no;
public:
	Customer(const string & fn, const string &ln, long n)
		: fname(fn), lname(ln), no(n) {
	}
	
	string firstname() const {
		return fname;
	};

	string lastname() const {
		return lname;
	};

	long number() const {
		return no;
	};
	friend std::ostream& operator<< (std::ostream & strm, const Customer & c) {
		return strm << "[" << c.fname << "," << c.lname << "," << c.no << "]";
	}
};

void unordSet_udfHashFunc()
{
	// lambda for user-define hash function
	auto hash = [](const Customer& c) {
		return hash_val(c.firstname() , c.lastname() , c.number());
	};

	// lambda for user-define equality criterion
	auto eq = [](const Customer &c1, const Customer &c2) {
		return c1.number() == c2.number();
	};

	unordered_set<Customer, decltype(hash), decltype(eq)> custset(10, hash, eq);

	custset.insert(Customer("noic", "josuttis", 42));
	PRINT_ELEMENTS(custset);
}


// cont /unordinspect1.cpp
// 使用bucket接口鉴于unordered容器的内部结构的例子
#include "buckets.h"

void unordmap_buckets()
{
	// create and initialize an unordered set
	unordered_set<int> intset;
	intset = { 1,2,3,5,7,11,13,17,19 };
	printHashTableState(intset);

	// insert some addition value may cause rehashing
	intset.insert({ -7,17,33,4 });
	printHashTableState(intset);
}


// 另一个例子，建立一个以string value 映射到另一个string value的字典
// cont/unordmultimap1.cpp
#include <unordered_map>
using std::unordered_map;
using std::unordered_multimap;
void unordmap_strmap()
{
	// create and initialize an unordered nultimap
	std::unordered_multimap<string, string> dict = {
		{"day","tag"}, {"strange","fremd"}, 
		{"car","Auto"}, {"smart","elegant"}, 
		{"trati","Merkmal"}, {"strange","seltsam"} 
	};
	printHashTableState(dict);

	// insert some additional elements (may cause rehashing)
	dict.insert({ 
		{"smart","raffiniert"},{"smart","klug"},{"clever","raffiniert"} 
	});
	printHashTableState(dict);

	// modify maximum load factor (may cause rehashing)
	dict.max_load_factor(0.7);
	printHashTableState(dict);
}






