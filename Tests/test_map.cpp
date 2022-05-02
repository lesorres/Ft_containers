#include <iostream>
#include "config.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template <typename K, typename V>
void print_map(ft::map<K, V> &m)
{
	std::cout << "map content: ";
	typename ft::map<K, V>::iterator begin = m.begin();
	typename ft::map<K, V>::iterator end = m.end();
	while (begin != end)
	{
		std::cout << "key: " << (*begin).first;
		std::cout  << ", value: " << (*begin).first << "\n";
		begin++;
	}
	std::cout << "\n\n";
}

int main()
{
	const int seed = 348734;
	srand(seed);
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; ++i)
		map_int.insert(ft::make_pair(rand(), rand()));

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;
	ft::map<int, int> copy = map_int;

	// __________MEMBER FUNCTIONS__________ //

	//*************   Constructors   *************//
	std::cout << "\n----------------Constructors test----------------\n";

	ft::map<int, int> m_for_const_0;													// empty constructor
	for (int i = 0; i < 5; ++i)
		m_for_const_0.insert(ft::make_pair(rand(), rand()));
	ft::map<int, int> m_for_const_1(m_for_const_0);										// copy constructor
	m_for_const_1.begin()++;
	ft::map<int, int> m_for_const_2(m_for_const_1.begin()++, m_for_const_1.end()--);	// fill constructor
	m_for_const_0 = m_for_const_1;														// copy assignment operator

	std::cout << m_for_const_0.size();
	std::cout << m_for_const_1.size();
	std::cout << m_for_const_2.size();
	print_map(m_for_const_0);
	print_map(m_for_const_1);
	print_map(m_for_const_2);

	//*************     Iterators     *************//
	std::cout << "\n----------------Iterator test----------------\n";
	ft::map<char,int> m_for_it0;

	m_for_it0['b'] = 100;
	m_for_it0['a'] = 200;
	m_for_it0['c'] = 300;

	// show content:
	for (ft::map<char,int>::iterator it = m_for_it0.begin(); it != m_for_it0.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::map<char,int>::reverse_iterator rit = m_for_it0.rbegin();
	size_t i = 0;
	size_t size = m_for_it0.size();
	while (i++ != size)
	{
		std::cout << (*rit).first << " => " << (*rit).second << '\n';
		rit++;
	}

	//*************     Сapacity     *************//
	std::cout << "\n----------------Capacity test----------------\n";
	ft::map<int, int> m_for_cap_0;
	std::cout << m_for_cap_0.empty();
	for (int i = 0; i < 5; ++i)
		m_for_cap_0.insert(ft::make_pair(rand(), rand()));
	std::cout << m_for_cap_0.empty();
	std::cout << m_for_cap_0.size();
	m_for_cap_0.insert(ft::make_pair(1234, 4321));
	std::cout << m_for_cap_0.size();
	m_for_cap_0.erase(1234);
	std::cout << m_for_cap_0.size();
	std::cout <<  (m_for_cap_0.max_size() >= 9223372036854775807);

	//*************     Element access     *************//
	std::cout << "\n----------------Element access----------------\n";
	ft::map<char, std::string> m_for_ea_0;
	m_for_ea_0['b'] = "asdfghjkl";
	m_for_ea_0['d'] = "wedsfdfrefdv";
	m_for_ea_0['a'] = "lkrtogflkgl";
	m_for_ea_0['g'] = "orurtu";
	m_for_ea_0['c'] = "poeroer";
	m_for_ea_0['e'] = "rtrtrtr";

	std::cout << m_for_ea_0['a'];
	std::cout << m_for_ea_0['g'];
	std::cout << m_for_ea_0['e'];
	std::cout << m_for_ea_0.at('b');
	std::cout << m_for_ea_0.at('d');
	std::cout << m_for_ea_0.at('c');

	//*************        Modifiers       *************//
	std::cout << "\n----------------Modifiers----------------\n";
	ft::map<int, int> m_for_m_0;
	ft::map<int, int> m_for_m_1;
	for (int i = 0; i < 155; ++i)
		m_for_m_0.insert(ft::make_pair(rand(), rand()));
	for (int i = 0; i < 155; ++i)
		m_for_m_1.insert(ft::make_pair(0 + i, rand()));
	print_map(m_for_m_0);
	print_map(m_for_m_1);
	m_for_m_0.swap(m_for_m_1);
	for (int i = 15; i < 55; ++i)
		m_for_m_1.erase(i);
	print_map(m_for_m_0);
	print_map(m_for_m_1);
	m_for_m_0.clear();
	m_for_m_1.clear();
	print_map(m_for_m_0);
	print_map(m_for_m_1);

	//*************        Observers       *************//
	std::cout << "\n----------------Observers----------------\n";
	ft::map<char,int> m_for_o0;
	ft::map<char,int>::key_compare mycomp = m_for_o0.key_comp();
	m_for_o0['a']=100;
	m_for_o0['b']=200;
	m_for_o0['c']=300;
	std::cout << "m_for_o0 contains:\n";
	char highest0 = m_for_o0.rbegin()->first;	// key value of last element
	ft::map<char,int>::iterator it0 = m_for_o0.begin();
	do
		std::cout << it0->first << " => " << it0->second << '\n';
	while ( mycomp((*it0++).first, highest0) );
	std::cout << '\n';

	ft::map<char,int> m_for_o1;
	m_for_o1['x']=1001;
	m_for_o1['y']=2002;
	m_for_o1['z']=3003;
	std::cout << "m_for_o1 contains:\n";
	ft::pair<char,int> highest1 = *m_for_o1.rbegin();	// last element
	ft::map<char,int>::iterator it1 = m_for_o1.begin();
	do
	{
		std::cout << it1->first << " => " << it1->second << '\n';
	}
	while ( m_for_o1.value_comp()(*it1++, highest1) );

	//*************        Operations       *************//
	std::cout << "\n----------------Operations----------------\n";
	ft::map<char,int> m_for_op0;
	m_for_op0['a']=100;
	m_for_op0['a']=400;
	m_for_op0['b']=200;
	m_for_op0['b']=500;
	m_for_op0['b']=600;
	m_for_op0['c']=300;

	std::cout << m_for_op0.find('a')->second;
	std::cout << m_for_op0.find('b')->second;
	std::cout << m_for_op0.find('c')->second;
	std::cout << m_for_op0.count('a');
	std::cout << m_for_op0.count('b');
	std::cout << m_for_op0.count('c');
	std::cout << m_for_op0.lower_bound('b')->second;
	std::cout << m_for_op0.upper_bound('b')->second;
	std::cout << m_for_op0.equal_range('a').first->second;
	std::cout << m_for_op0.equal_range('b').first->second;


	//__________NON-MEMBER FUNCTIONS__________ //

	std::cout << (m_for_m_0 == m_for_m_1);
	std::cout << (m_for_m_0 != m_for_m_1);
	std::cout << (m_for_m_0 <= m_for_m_1);
	std::cout << (m_for_m_0 < m_for_m_1);
	std::cout << (m_for_m_0 >= m_for_m_1);
	std::cout << (m_for_m_0 > m_for_m_1);

	return (0);
}