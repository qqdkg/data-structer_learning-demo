#pragma once

#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
#include <memory>

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




