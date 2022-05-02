#include <iostream>
#include "config.hpp"

template <typename T>
void print_v_size_and_cap(ft::vector<T> &v)
{
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
}

template <typename T>
void print_vector(ft::vector<T> &v)
{
	std::cout << "vector content: ";
	size_t s = v.size();
	for (size_t i = 0; i < s; i++)
		std::cout << v[i];
	std::cout << "\n\n";
}

void pointer_func(const int* p, std::size_t size)
{
	std::cout << "data = ";
	for (std::size_t i = 0; i < size; ++i)
		std::cout << p[i] << ' ';
	std::cout << '\n';
}

class Object {
public:
	int i;
	Object(): i(1) {};
	Object(const int &ex)
	{
		this->i = ex;
	};
	virtual ~Object() {};
};

int main()
{
	// __________MEMBER FUNCTIONS__________ //

	//*************   constructors   *************//
	std::cout << "\n----------------Constructors test----------------\n";

	ft::vector<int> v_for_const_0;												// default constructor
	ft::vector<int> v_for_const_2(10, 5);										// fill constructor
	ft::vector<int> v_for_const_1(10, 4);										// fill constructor
	v_for_const_1 = v_for_const_2;												// copy assignment operator
	ft::vector<int> v_for_const_3(v_for_const_1);								// copy constructor
	ft::vector<int> v_for_const_4(v_for_const_1.begin(), v_for_const_1.end());	// range constructor
	v_for_const_0.push_back(v_for_const_4.size());
	v_for_const_0.push_back(v_for_const_4.capacity());
	v_for_const_0.push_back(v_for_const_1[2]);
	v_for_const_0.push_back(v_for_const_3[2]);
	v_for_const_0.push_back(v_for_const_4[2]);
	try
	{
		ft::vector<int> v_for_const_5(-1, -1);
	}
	catch (std::exception &e)
	{
		v_for_const_0.push_back(1);
	}
	print_vector (v_for_const_0);
	print_vector (v_for_const_1);
	print_vector (v_for_const_2);
	print_vector (v_for_const_3);
	print_vector (v_for_const_4);


	// __________ITERATORS__________ //

	//*************     iterators     *************//
	std::cout << "\n----------------Iterator test----------------\n";
	ft::vector<std::string> v_for_it_0;
	for (size_t i = 0; i < 5; i++)
		v_for_it_0.push_back("abcd");
	std::string s_for_it0 = "abcd";
	ft::vector<std::string>::iterator i_for_it_0 = v_for_it_0.begin() + 1;							// iterator
	ft::vector<std::string>::iterator i_for_it_1 = i_for_it_0;

	ft::vector<std::string>::iterator r = v_for_it_0.begin();
	ft::vector<std::string>::const_iterator u = r;													// const_iterator

	std::cout << *r << "\n";
	std::cout << *u << "\n";
	std::cout << *i_for_it_1 << "\n";

	ft::vector<int> v_for_it_1;
	v_for_it_1.push_back(9);
	v_for_it_1.push_back(8);
	v_for_it_1.push_back(7);
	v_for_it_1.push_back(6);
	v_for_it_1.push_back(5);

	ft::vector<int>::iterator i_for_it_4 = v_for_it_1.begin() + 2;
	ft::vector<int>::reverse_iterator i_for_it_2 = v_for_it_1.rbegin() + 2;;						// reverse_iterator
	ft::vector<int>::const_iterator i_for_it_5 = i_for_it_4;										// const_iterator
	
	std::cout << (*i_for_it_4 == *i_for_it_2);
	std::cout << *i_for_it_5;

	ft::vector<std::string> v_for_it_3;

	v_for_it_0.assign(1, "2");
	v_for_it_3.assign(1000, "d");
	v_for_it_0.push_back(*(v_for_it_3.rbegin()));
	v_for_it_0.push_back(*(v_for_it_3.rbegin() + 1));
	v_for_it_0.push_back(*(v_for_it_3.rbegin() + 2));
	v_for_it_0.push_back(*(v_for_it_3.rbegin() + 1000));

	print_vector(v_for_it_0);


	// __________CAPACITY__________ //

	//*************       max_size     *************//
	std::cout << "\n----------------max_size----------------\n";
	ft::vector<char> v_for_mx_0;
	std::cout.imbue(std::locale("en_US.UTF-8"));    
	std::cout <<  (v_for_mx_0.max_size() >= 9223372036854775807);

	//*************       resize     *************//
	std::cout << "\n----------------Resize test----------------\n";

	ft::vector<int> v_for_resize_0(14);

	std::cout << "vector size: " << v_for_resize_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_resize_0.capacity() << "\n";
	print_vector(v_for_resize_0);

	v_for_resize_0.resize(10, 2);
	std::cout << "vector size: " << v_for_resize_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_resize_0.capacity() << "\n";
	print_vector(v_for_resize_0);

	v_for_resize_0.resize(14, 2);
	std::cout << "vector size: " << v_for_resize_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_resize_0.capacity() << "\n";
	print_vector(v_for_resize_0);

	v_for_resize_0.resize(29, 2);
	std::cout << "vector size: " << v_for_resize_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_resize_0.capacity() << "\n";
	print_vector(v_for_resize_0);

	v_for_resize_0.resize(10, 2);
	std::cout << "vector size: " << v_for_resize_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_resize_0.capacity() << "\n";
	print_vector(v_for_resize_0);

	//*************       empty     *************//
	std::cout << "\n----------------Empty test----------------\n";
	ft::vector<int> v_for_emt_0;
	int i_for_emt_0 = 0;
	for (int i = 1; i <= 10; i++)
		v_for_emt_0.push_back(i);
	while (!v_for_emt_0.empty())
	{
		i_for_emt_0 +=  v_for_emt_0.back();
		v_for_emt_0.pop_back();
	}
	std::cout << "total: " << i_for_emt_0 << '\n';

	//*************       reserve     *************//
	std::cout << "\n----------------Reserve test----------------\n";
	ft::vector<Object> v_for_res_0;
	ft::vector<int> v_for_res_1(10, 2);

	print_vector(v_for_res_1);
	print_v_size_and_cap(v_for_res_0);
	print_v_size_and_cap(v_for_res_1);

	v_for_res_0.reserve(100);
	v_for_res_1.reserve(1532);
	
	print_v_size_and_cap(v_for_res_0);
	print_v_size_and_cap(v_for_res_1);


	// __________ELEMENT ACCES__________ //

	std::cout << "\n----------------Element acces----------------\n";
	ft::vector<int> v_for_ea_0;
	v_for_ea_0.push_back(2);
	v_for_ea_0.push_back(4);
	v_for_ea_0.push_back(6);
	v_for_ea_0.push_back(8);
 
	std::cout << "Second element: " << v_for_ea_0[1] << '\n';	// operator[]
	v_for_ea_0[0] = 5;
	std::cout << "All numbers:";
	for (size_t i = 0; i < v_for_ea_0.size(); i++)
		std::cout << ' ' << v_for_ea_0[i];						// operator[]
	std::cout << '\n';
	for (size_t i = 0; i < v_for_ea_0.size(); i++)
		std::cout << ' ' << v_for_ea_0.at(i);					// at
	std::cout << '\n';
	try															// bounds checking for at
	{
		std::cout << v_for_ea_0.at(v_for_ea_0.size() + 4);
	}
	catch (std::out_of_range const& exc)
	{
		std::cout << exc.what() << '\n';
	}

	ft::vector<char> v_for_ea_1;
	v_for_ea_1.push_back('o');
	v_for_ea_1.push_back('m');
	v_for_ea_1.push_back('g');
	v_for_ea_1.push_back('w');
	v_for_ea_1.push_back('t');
	v_for_ea_1.push_back('f');
 
	if (!v_for_ea_1.empty())
	{
		std::cout << "The first character is '" << v_for_ea_1.front() << "'.\n";	// front
		std::cout << "The last character is '" << v_for_ea_1.back() << "'.\n";		// back
	}
	ft::vector<int> v_for_ea_2;
	v_for_ea_1.push_back(1);
	v_for_ea_1.push_back(2);
	v_for_ea_1.push_back(3);
	v_for_ea_1.push_back(4);
	pointer_func(v_for_ea_2.data(), v_for_ea_2.size());								// data


	// __________MODIFIERS__________ //

	//*************       assign     *************//
	std::cout << "\n----------------Assign test----------------\n";

	ft::vector<int> v_for_assign_0;
	v_for_assign_0 = v_for_resize_0;

	v_for_assign_0.assign(2, 5);

	std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	print_vector(v_for_assign_0);

	v_for_assign_0.assign(6, 5);
	std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	print_vector(v_for_assign_0);

	v_for_assign_0.assign(30, 11);
	std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n";
	print_vector(v_for_assign_0);

	ft::vector<int> v_for_assign_1(6, 7);
	print_vector(v_for_assign_1);

	v_for_assign_0.assign(v_for_assign_1.begin(), v_for_assign_1.end());
	std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n";
	print_vector(v_for_assign_0);

	ft::vector<int> v_for_assign_2(14);
	ft::vector<int> v_for_assign_3(10, 12);

	v_for_assign_2.assign(v_for_assign_3.begin(), v_for_assign_3.end());

	//*************     push_back    *************//
	std::cout << "\n----------------Push_back test----------------\n";
	ft::vector<std::string> v_for_pb_0;
	ft::vector<std::string> v_for_pb_1;
	v_for_pb_0.push_back("asdfg");
	v_for_pb_1 = v_for_pb_0;

	print_vector(v_for_pb_0);
	print_vector(v_for_pb_1);

	//*************     pop_back    *************//
	std::cout << "\n----------------Pop_back test----------------\n";
	v_for_pb_1.pop_back();
	print_vector(v_for_pb_1);

	//*************     insert    *************//
	std::cout << "\n----------------Insert test----------------\n";
	
	// value
	ft::vector<std::string> v_for_ins_0(4, "s");

	std::cout << "vector size: " << v_for_ins_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_0.capacity() << "\n";
	print_vector(v_for_ins_0);

	v_for_ins_0.insert(v_for_ins_0.begin(), "v");

	std::cout << "vector size: " << v_for_ins_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_0.capacity() << "\n";
	print_vector(v_for_ins_0);

	ft::vector<std::string> v_for_ins_1 (99, "k");

	for (int i = 0; i < 90; i++)
		v_for_ins_1.pop_back();

	std::cout << "vector size: " << v_for_ins_1.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_1.capacity() << "\n";
	print_vector(v_for_ins_1);

	// fill
	ft::vector<std::string> v_for_ins_2 (4, "k");

	std::cout << "vector size: " << v_for_ins_2.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_2.capacity() << "\n";
	print_vector(v_for_ins_2);

	v_for_ins_2.insert(v_for_ins_2.begin(), 11, "v");

	std::cout << "vector size: " << v_for_ins_2.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_2.capacity() << "\n";
	print_vector(v_for_ins_2);

	//*************        end, begin, swap      *************//
	std::cout << "\n//*************   end, begin, erase, swap   *************//\n";
	ft::vector<std::string> v_for_ebs0 (14, "bla");
	ft::vector<std::string> v_for_ebs1 (3, "hi");

	v_for_ebs1.swap(v_for_ebs0);
	ft::vector<std::string>::iterator begin = v_for_ebs1.begin();
	ft::vector<std::string>::iterator end = v_for_ebs1.end();
	std::cout << (begin != end) << "\n";
	for (; begin != end; ++begin)
		std::cout << *begin << "\n";

	//*************        clear, get_allocator      *************//
	std::cout << "\n//*************   clear, get_allocator   *************//\n";
	v_for_ebs0.clear();
	v_for_ebs1.clear();

	print_vector(v_for_ebs0);
	print_vector(v_for_ebs1);

	v_for_ebs0.get_allocator();
	v_for_ebs1.get_allocator();

	return (0);
}