#include <iostream>
#include "config.hpp"

template <typename K>
void print_set(ft::set<K> &s)
{
	std::cout << "set content: ";
	typename ft::set<K>::iterator begin = s.begin();
	typename ft::set<K>::iterator end = s.end();
	while (begin != end)
	{
		std::cout << "key: " << (*begin) << "\n";
		begin++;
	}
	std::cout << "\n\n";
}

int main()
{
	const int seed = 348734;
	srand(seed);

// __________MEMBER FUNCTIONS__________ //

	//*************   Constructors   *************//
	std::cout << "\n----------------Constructors test----------------\n";

	ft::set<int> s_for_const_0;														// empty constructor
	for (int i = 0; i < 5; ++i)
		s_for_const_0.insert(rand());
	ft::set<int> s_for_const_1(s_for_const_0);										// copy constructor
	s_for_const_1.begin()++;
	ft::set<int> s_for_const_2(s_for_const_1.begin()++, s_for_const_1.end()--);		// fill constructor
	s_for_const_0 = s_for_const_1;													// copy assignment operator

	std::cout << s_for_const_0.size();
	std::cout << s_for_const_1.size();
	std::cout << s_for_const_2.size();
	print_set(s_for_const_0);
	print_set(s_for_const_1);
	print_set(s_for_const_2);

	//*************     Iterators     *************//
	std::cout << "\n----------------Iterator test----------------\n";
	ft::set<char> s_for_it0;

	s_for_it0.insert('b');
	s_for_it0.insert('a');
	s_for_it0.insert('b');
	s_for_it0.insert('c');

	// show content:
	for (ft::set<char,int>::iterator it = s_for_it0.begin(); it != s_for_it0.end(); ++it)
		std::cout << *it << '\n';

	ft::set<char,int>::reverse_iterator rit = s_for_it0.rbegin();
	size_t i = 0;
	size_t size = s_for_it0.size();
	while (i++ != size)
	{
		std::cout << *rit << '\n';
		rit++;
	}

	//*************     Сapacity     *************//
	std::cout << "\n----------------Capacity test----------------\n";
	ft::set<int> s_for_cap_0;
	std::cout << s_for_cap_0.empty();
	for (int i = 0; i < 5; ++i)
		s_for_cap_0.insert(rand());
	std::cout << s_for_cap_0.empty();
	std::cout << s_for_cap_0.size();
	s_for_cap_0.insert(1234);
	std::cout << s_for_cap_0.size();
	s_for_cap_0.erase(1234);
	std::cout << s_for_cap_0.size();
	std::cout <<  (s_for_cap_0.max_size() >= 9223372036854775807);

// 	//*************        Modifiers       *************//
	std::cout << "\n----------------Modifiers----------------\n";
	ft::set<int> s_for_m_0;
	ft::set<int> s_for_m_1;
	for (int i = 0; i < 155; ++i)
		s_for_m_0.insert(rand());
	for (int i = 0; i < 155; ++i)
		s_for_m_1.insert(0 + i);
	print_set(s_for_m_0);
	print_set(s_for_m_1);
	s_for_m_0.swap(s_for_m_1);
	for (int i = 15; i < 55; ++i)
		s_for_m_1.erase(i);
	print_set(s_for_m_0);
	print_set(s_for_m_1);
	s_for_m_0.clear();
	s_for_m_1.clear();
	print_set(s_for_m_0);
	print_set(s_for_m_1);

// 	//*************        Observers       *************//
	std::cout << "\n----------------Observers----------------\n";
	ft::set<int> s_for_ob0;
	int highest0;
	ft::set<int>::key_compare mycomp0 = s_for_ob0.key_comp();
	for (int i = 0; i <= 5; i++)
		s_for_ob0.insert(i);
	std::cout << "s_for_ob0 contains:";
	highest0 = *s_for_ob0.rbegin();
	ft::set<int>::iterator it0 = s_for_ob0.begin();
	do
		std::cout << ' ' << *it0;
	while (mycomp0(*(++it0), highest0));
	std::cout << '\n';

	ft::set<int> s_for_ob1;
	ft::set<int>::value_compare mycomp1 = s_for_ob1.value_comp();
	for (int i = 0; i <= 5; i++)
		s_for_ob1.insert(i);
	std::cout << "s_for_ob1 contains:";
	int highest1 = *s_for_ob1.rbegin();
	ft::set<int>::iterator it1 = s_for_ob1.begin();
	do
		std::cout << ' ' << *it1;
	while (mycomp1(*(++it1), highest1));
	std::cout << '\n';

	//*************        Operations       *************//
	std::cout << "\n----------------Operations----------------\n";
	
	ft::set<std::string> s_for_ea_0;
	s_for_ea_0.insert("asdfghjkl");
	s_for_ea_0.insert("wedsfdfrefdv");
	s_for_ea_0.insert("lkrtogflkgl");
	s_for_ea_0.insert("orurtu");
	s_for_ea_0.insert("poeroer");
	s_for_ea_0.insert("poeroer");
	s_for_ea_0.insert("poeroer");
	s_for_ea_0.insert("rtrtrtr");
	s_for_ea_0.insert("rtrtrtr");
	s_for_ea_0.insert("rtrtrtr");
	s_for_ea_0.insert("rtrtrtr");

	std::cout << *s_for_ea_0.find("lkrtogflkgl");
	std::cout << *s_for_ea_0.find("asdfghjkl");
	std::cout << *s_for_ea_0.find("rtrtrtr");
	std::cout << s_for_ea_0.count("lkrtogflkgl");
	std::cout << s_for_ea_0.count("asdfghjkl");
	std::cout << s_for_ea_0.count("rtrtrtr");
	std::cout << *s_for_ea_0.lower_bound("poeroer");
	std::cout << *s_for_ea_0.upper_bound("rtrtrtr");
	std::cout << *s_for_ea_0.equal_range("poeroer").first;
	std::cout << *s_for_ea_0.equal_range("rtrtrtr").first;
	std::cout << *s_for_ea_0.equal_range("poeroer").second;
	std::cout << *s_for_ea_0.equal_range("rtrtrtr").second;


// //__________NON-MEMBER FUNCTIONS__________ //

	std::cout << (s_for_m_0 == s_for_m_1);
	std::cout << (s_for_m_0 != s_for_m_1);
	std::cout << (s_for_m_0 <= s_for_m_1);
	std::cout << (s_for_m_0 < s_for_m_1);
	std::cout << (s_for_m_0 >= s_for_m_1);
	std::cout << (s_for_m_0 > s_for_m_1);


	return (0);
}