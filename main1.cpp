#include "enable_if.hpp"
#include "is_integral.hpp"
#include <vector>
#include <set>
#include <algorithm>

#include <iostream>

template <class T>
bool foo(T p, typename ft::enable_if<ft::is_integral<T>::value, T>::type * = NULL)
{
	return true;
}

template <class T>
bool foo(T p,  typename ft::enable_if<!ft::is_integral<T>::value, T>::type * = NULL)
{
	return false;
}

class A{
	public:
	A(){};
	~A(){};
};

int main(void){

	const int a = 0;

	if (foo(a))
	std::cout << "true" << std::endl;
	else 
	std::cout << "false" << std::endl;


	std::vector<int> vec;
	std::vector<int> vec1;
	std::set<int> set;

	for(int i = 0; i < 10; i++){
		// vec.push_back(i);
		set.insert(i);
	}

	std::vector<int>::iterator it;

	
	vec1.insert(vec1.begin(), 10, 10);
	it = vec1.begin();
	for (;it < vec1.end(); it++)
		std::cout << *it << " ";
		std::cout << std::endl;	
	vec1.insert(vec1.begin(), set.begin(), set.end());	
	it = vec1.begin();
	for (;it < vec1.end(); it++)
		std::cout << *it << " ";	
		std::cout << std::endl;	

	return 0;
}