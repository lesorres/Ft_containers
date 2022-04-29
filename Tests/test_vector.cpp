#include <iostream>
#include "config.hpp"

template <typename T>
void print_v_size_and_cap(ft::vector<T> v)
{
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
}

template <typename T>
void print_vector(ft::vector<T> v)
{
	std::cout << "vector content:\n";
	size_t s = v.size();
	for (size_t i = 0; i < s; i++)
		std::cout << v[i];
	std::cout << "\n\n";
	// print_v_size_and_cap(v); - some cases of different capacity
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
	// MEMBER FUNCTIONS
	//*************   constructors   *************//
	std::cout << "\n----------------Constructors test----------------\n";

	ft::vector<int> v_for_const_0;												// default constructor
	ft::vector<int> v_for_const_1(1000 * _ratio, 4);							// fill constructor
	ft::vector<int> v_for_const_2(1000 * _ratio, 5);							// fill constructor
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

	// ITERATORS
	//*************     iterator     *************//
	std::cout << "\n----------------Iterator test----------------\n";

	ft::vector<std::string> v_for_it_0;
	for (size_t i = 0; i < 5; i++)
		v_for_it_0.push_back("abcd");
	std::string s_for_it0 = "abcd";
	ft::vector<std::string>::iterator i_for_it_0 = v_for_it_0.begin() + 1;							// iterator
	ft::vector<std::string>::iterator i_for_it_1 = i_for_it_0;
	// ft::vector<std::string>::iterator i_for_it_2(s_for_it0); - не должен принимать строку

	ft::vector<std::string>::iterator r = v_for_it_0.begin();
	ft::vector<std::string>::const_iterator u = r;													// const_iterator

	std::cout << *r << "\n";
	std::cout << *u << "\n";

	ft::vector<int> v_for_it_1;
	v_for_it_1.push_back(9);
	v_for_it_1.push_back(8);
	v_for_it_1.push_back(7);
	v_for_it_1.push_back(6);
	v_for_it_1.push_back(5);

	ft::vector<int>::iterator i_for_it_4 = v_for_it_1.begin() + 2;
	ft::vector<int>::reverse_iterator i_for_it_2 = v_for_it_1.rbegin() + 2;;						// reverse_iterator
	ft::vector<int>::const_iterator i_for_it_5 = i_for_it_4;										// const_iterator
	// ft::vector<int>::const_reverse_iterator i_for_it_3(v_for_it_1.rend()); - does not work //	// const_reverse_iterator
	// ft::vector<int>::const_reverse_iterator i_for_it_3 = i_for_it_2; - does not work
	
	std::cout << (*i_for_it_4 == *i_for_it_2);

	// ft::vector<int> v_for_it_0;
	// ft::vector<int> v_for_it_1;
	// v_for_it_0.assign(1, 2);
    // v_for_it_1.assign(1000, 1);
    // v_for_it_0.push_back(*v_for_it_1.rbegin());
    // v_for_it_0.push_back(*(v_for_it_1.rbegin() + 1));
	// v_for_it_0.push_back(*(v_for_it_1.rbegin() + 2));
	// v_for_it_0.push_back(*(v_for_it_1.rbegin() + 1000));

	// print_vector(v_for_it_0);



	// CAPACITY
	// max_size() const
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
	//*************       reserve     *************//
	std::cout << "\n----------------Reserve test----------------\n";

	// ELEMENT ACCES
	// operator[
	// operator[] (size_type n) const
	// at (size_type n)
	// at (size_type n) const
	// front()
	// front() const
	// back()
	// back() const
	// data()
	// data() const

	// MODIFIERS
	//*************       assign     *************//
	std::cout << "\n----------------Assign test----------------\n";

	ft::vector<int> v_for_assign_0;
	v_for_assign_0 = v_for_resize_0;

	v_for_assign_0.assign(2, 5);

	std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	// std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n"; - does not work
	print_vector(v_for_assign_0);

	v_for_assign_0.assign(6, 5);
	std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	// std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n"; - does not work
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

	std::cout << v_for_pb_0[1] << "\n";
	std::cout << v_for_pb_1[0] << "\n";


	// pop_back
	// insert
	// insert
	// insert
	//*************       erase      *************//
	// swap
	// clear
	// get_allocator
}