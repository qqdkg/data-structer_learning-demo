#pragma once
#include <iostream>
#include <iomanip>
#include <utility>
#include <iterator>
#include <typeinfo>

// generic output for pairs(map elements)]
template<typename T1, typename T2>
std::ostream& operator << (std::ostream & strm, const std::pair<T1, T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]";
}

template<typename T>
void printHashTableState(const T & cont)
{
	// basic layout data
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	int tab1 = 20;
	int tab2 = 15;
	std::cout << std::setw(tab1) << "size:" << std::setw(tab2) << cont.size() << "\n";
	std::cout << std::setw(tab1) << "buckets:" << std::setw(tab2) << cont.bucket_count() << "\n";
	std::cout << std::setw(tab1) << "load factor:" << std::setw(tab2) << cont.load_factor() << "\n";
	std::cout << std::setw(tab1) << "max load factor:" << std::setw(tab2) << cont.max_load_factor() << "\n";

	// iterator category
	if (typeid(typename  std::iterator_traits
		<typename T::iterator>::iterator_category)
		== typeid(std::bidirectional_iterator_tag)) {
		std::cout << std::setw(tab1) << "changing style:" << std::setw(tab1) << "duobly-linked" << "\n";
	}
	else {
		std::cout << std::setw(tab1) << "changing style:" << std::setw(tab1) <<"single-lilnked" << "\n";
	}

	// elements per bucket
	std::cout << "data: " << "\n";
	for (int idx = 0; idx != cont.bucket_count(); ++idx)
	{
		std::cout << "b[" << std::setw(2) << idx << "]: ";
		for (auto pos = cont.begin(idx); pos != cont.end(idx); ++pos)
		{
			std::cout << *pos << " ";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}






