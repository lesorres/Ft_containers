#include <iostream>
#include "config.hpp"

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	virtual ~MutantStack() {} //При работе с наследованием ваши деструкторы должны быть виртуальными https://ravesli.com/urok-165-virtualnye-destruktory-i-prisvaivanie/

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main()
{
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
		std::cout << *it;
	std::cout << std::endl;

	ft::stack<std::string> s_0;
	for (int i = 0; i < 15 ; i++)
		s_0.push("blabla");
	for (int i = 0; i < 10 ; i++)
		s_0.push("fgfgfg");
	ft::stack<std::string> s_1(s_0);
	ft::stack<std::string> s_2 = s_1;

	std::cout << s_0.top();
	std::cout << s_1.top();
	std::cout << s_2.top();

	for (int i = 0; i < 15 ; i++)
		s_0.pop();
	s_1.empty();

	std::cout << s_0.top();
	std::cout << s_1.top();
	std::cout << s_2.top();
	std::cout << (s_0 == s_1);
	std::cout << (s_0 != s_1);
	std::cout << (s_2 <= s_1);
	std::cout << (s_0 < s_2);
	std::cout << (s_2 >= s_2);
	std::cout << (s_1 > s_1);
	
	return (0);
}