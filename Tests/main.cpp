#include <iostream>
#include "/Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include/sys/time.h"
#include "config.hpp"

volatile static time_t g_start1;
volatile static time_t g_start2;
volatile static time_t g_end1;
volatile static time_t g_end2;
int _ratio = 10000;

template <typename T>
void print_vector(ft::vector<T> v)
{
	std::cout << "vector content:\n";
	size_t s = v.size();
	for (size_t i = 0; i < s; i++)
		std::cout << v[i];
	std::cout << "\n\n";
}

time_t timer()
{
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

	class B {
	public:
		char *l;
		int i;
		B():l(nullptr), i(1) {};
		B(const int &ex) {
			this->i = ex;
			this->l = new char('a');
		};
		virtual ~B() {
			delete this->l;
			this->l = nullptr;
		};
	};

	class A : public B {
	public:
		A():B(){};
		A(const B* ex){
			this->l = new char(*(ex->l));
			this->i = ex->i;
			if (ex->i == -1) throw "n";
		}
		~A() {
			delete this->l;
			this->l = nullptr;
		};
	};

int main()
{

// MEMBER FUNCTIONS
//*************   constructors   *************//
// default constructor
// fill constructor
// range constructor
// copy constructor
// destructor
// copy assignment operator

// ITERATORS
//*************     iterator     *************//
// const_iterator
// reverse_iterator
// const_reverse_iterator

// CAPACITY
// size() const
// max_size() const
//*************       resize     *************//
// capacity() const
// empty() const
// reserve (size_type n)

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
//*************     push_back    *************//
// pop_back
// insert
// insert
// insert
//*************       erase      *************//
// swap
// clear
// get_allocator

	// ft::vector<int> vector;
	// ft::vector<int> v;
	// vector.assign(1000, 1);
	// v.push_back(*(vector.end() - 1));
	// v.push_back(*(vector.end() - 2));

//*************       resize     ************//
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

//*************       assign     *************//
	std::cout << "\n----------------Assign test----------------\n";

	ft::vector<int> v_for_assign_0;
	v_for_assign_0 = v_for_resize_0;

	v_for_assign_0.assign(2, 5);

	std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n";
	print_vector(v_for_assign_0);

	v_for_assign_0.assign(6, 5);
	std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n";
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

//*************       erase      *************//
	std::cout << "\n----------------Erase test----------------\n";

	ft::vector<int> v1;
	ft::vector<int> vector;
	for (int i = 0; i < 9 * _ratio; ++i)
		vector.push_back(i);
	std::cout << "vector capacity:" << vector.capacity() << "\n";
	print_vector(v1);
	std::cout << vector.size() << "\n";
	g_start2 = timer();
	v1.push_back(*(vector.erase(vector.begin() + 1, vector.end() - 2)));
	print_vector(v1);
	g_end2 = timer();
	std::cout << "here1\n";
	v1.push_back(*(vector.begin() + 2 * _ratio)); //exeption in new via construct in push_back
	std::cout << "here2\n";
	print_vector(v1);
	std::cout << vector.size() << "\n";
	v1.push_back(vector.size());
	print_vector(v1);
	v1.push_back(vector.capacity());
	print_vector(v1);

	ft::vector<int> v3;
	ft::vector<int> vector2;
	for (int i = 0; i < 9900 * _ratio; ++i)
		vector2.push_back(i);
	std::cout << vector2.capacity() << "\n";
	print_vector(v3);
	std::cout << vector2.size() << "\n";
	g_start2 = timer();
	std::cout << "here3\n";
	v3.push_back(*(vector2.erase(vector2.begin() + 8 * _ratio, vector2.end() - 1500 * _ratio))); // ?
	std::cout << "here4\n";
	print_vector(v3);
	g_end2 = timer();
	v3.push_back(*(vector2.begin() + 82 * _ratio));
	print_vector(v3);
	std::cout << vector2.size() << "\n";
	v3.push_back(vector2.size());
	print_vector(v3);
	v3.push_back(vector2.capacity());
	print_vector(v3);
	print_vector(v3);

	ft::vector<std::string> v_for_er_0;

	for (int i = 0; i < 16; i++)
		v_for_er_0.push_back("asdfg");

	std::cout << "before erase: size: " << v_for_er_0.size() << ", capacity: " << v_for_er_0.capacity() << "\n";
	v_for_er_0.erase(v_for_er_0.begin() + 3, v_for_er_0.begin() + 11);
	std::cout << "after erase:  size: " << v_for_er_0.size() << ", capacity: " << v_for_er_0.capacity() << "\n";
	std::cout << "capacity shouldn't be shrank after erase\n";

//*************     push_back    *************//
	std::cout << "\n----------------Push_back test----------------\n";

	ft::vector<std::string> v_for_pb_0;
	ft::vector<std::string> v_for_pb_1;
	for (int i = 0; i < 4; i++)
		v_for_pb_0.push_back("asdfg");
	v_for_pb_1 = v_for_pb_0;

	std::cout << &v_for_pb_0[1] << "\n";
	std::cout << &v_for_pb_1[1] << "\n";


//*************     iterator     *************//
	std::cout << "\n----------------Iterator test----------------\n";
	ft::vector<std::string> v_for_it_0;
	for (size_t i = 0; i < 5; i++)
		v_for_it_0.push_back("abcd");
	std::string s_for_it0 = "abcd";
	ft::vector<std::string>::iterator i_for_it_0 = v_for_it_0.begin() + 1;
	ft::vector<std::string>::iterator i_for_it_1 = i_for_it_0;
	// ft::vector<std::string>::iterator i_for_it_2(s_for_it0);

	ft::vector<std::string>::iterator r = v_for_it_0.begin();
	ft::vector<std::string>::const_iterator u = r;

	std::cout << *r << "\n";
	std::cout << *u << "\n";

//*************   constructor   *************//
	std::cout << "\n----------------Constructor test----------------\n";
		ft::vector<int> v2;
		ft::vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
		tmp = tmp2;
		ft::vector<int> tmp3(tmp);
		g_start1 = timer();
		ft::vector<int> tmp4(tmp.begin(), tmp.end());
		g_end1 = timer();
		v2.push_back(tmp4.size());
		v2.push_back(tmp4.capacity());
		v2.push_back(tmp[2]);
		v2.push_back(tmp3[2]);
		v2.push_back(tmp4[2]);
		try { ft::vector<int> tmp5(-1, -1); }
		catch (std::exception &e) { v2.push_back(1); }

		// ft::vector<int> v4;
		// ft::vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5); //не выполняется деструктор для этого блока памяти (выделен с помощью fill constructor) - Invalid free() / delete / delete[] / realloc()
		// tmp = tmp2;
		// ft::vector<int> tmp3(tmp);
		// g_start2 = timer();
		// ft::vector<int> tmp4(tmp.begin(), tmp.end());
		// g_end2 = timer();
		// v4.push_back(tmp4.size());
		// v4.push_back(tmp4.capacity());
		// v4.push_back(tmp[2]);
		// v4.push_back(tmp3[2]);
		// v4.push_back(tmp4[2]);
		// std::cout << "here5\n";
		// // try { ft::vector<int> tmp5(-1, -1); }
		// // catch (std::exception &e) { v4.push_back(1); }
		// std::cout << "here6\n";

//*************        swap       *************//

	ft::vector<int> vector9;
    ft::vector<int> v;
    vector9.assign(1100 * _ratio, 11);
    ft::vector<int> tmp9(500 * _ratio, 5), tmp12(1000 * _ratio, 10), tmp13(1500 * _ratio, 15), tmp14(3000 * _ratio, 30);
    g_start2 = timer();
    v.push_back(vector9[2]);
    v.push_back(vector9.size());
    v.push_back(vector9.capacity());
    long *adr1 = reinterpret_cast<long *>(&vector9);
    long *adr2 = reinterpret_cast<long *>(&tmp9);
    vector9.swap(tmp9);
    if (reinterpret_cast<long *>(&vector9) == adr1 && reinterpret_cast<long *>(&tmp9) == adr2)
    	v.push_back(1);
    v.push_back(vector9[2]);
    v.push_back(vector9.size());
    v.push_back(vector9.capacity());
    vector9.swap(tmp13);
    v.push_back(vector9[2]);
    v.push_back(vector9.size());
    v.push_back(vector9.capacity());
    std::swap(vector9, tmp12);
    v.push_back(vector9[2]);
    v.push_back(vector9.size());
    v.push_back(vector9.capacity());
    std::swap(vector9, tmp14);
    g_end2 = timer();
    v.push_back(vector9[2]);
    v.push_back(vector9.size());
    v.push_back(vector9.capacity());

//*************        insert       *************//
	std::cout << "\n----------------Insert test----------------\n";

	// value
	
	// 1
	ft::vector<std::string> v_for_ins_0;
	for (int i = 0; i < 4; i++)
		v_for_ins_0.push_back("a");
	v_for_ins_0.push_back("a");
	v_for_ins_0.push_back("b");
	v_for_ins_0.push_back("c");
	v_for_ins_0.push_back("d");

	std::cout << "here\n";

	std::cout << "vector size: " << v_for_ins_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_0.capacity() << "\n";
	print_vector(v_for_ins_0);

	v_for_ins_0.insert(v_for_ins_0.begin() + 1, "v");

	std::cout << "vector size: " << v_for_ins_0.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_0.capacity() << "\n";
	print_vector(v_for_ins_0);

	// 2
	ft::vector<std::string> v_for_ins_1 (99, "k");
	for (int i = 0; i < 90; i++)
		v_for_ins_1.pop_back();

	std::cout << "vector size: " << v_for_ins_1.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_1.capacity() << "\n";
	print_vector(v_for_ins_1);

	v_for_ins_1.insert(v_for_ins_1.end(), "v");

	std::cout << "vector size: " << v_for_ins_1.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_1.capacity() << "\n";
	print_vector(v_for_ins_1);

	//fill

	// 3
	ft::vector<std::string> v_for_ins_2 (5, "k");

	std::cout << "vector size: " << v_for_ins_2.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_2.capacity() << "\n";
	print_vector(v_for_ins_2);

	v_for_ins_2.insert(v_for_ins_2.begin(), 11, "v");

	std::cout << "vector size: " << v_for_ins_2.size() << "\n";
	std::cout << "vector cpct: " << v_for_ins_2.capacity() << "\n";
	print_vector(v_for_ins_2);


	// range

	std::cout << "here\n";
	ft::vector<std::string> v_for_ins_3 (5, "c");
	ft::vector<std::string> v_for_ins_4 (2, "h");

	// std::cout << "here\n";
	std::cout << v_for_ins_3.begin().base() << "\n";
	// std::cout << v_for_ins_3.insert(v_for_ins_3.begin(), v_for_ins_4.end(), v_for_ins_4.begin()).base();
	v_for_ins_3.insert(v_for_ins_3.begin(), v_for_ins_4.begin(), v_for_ins_4.end());
	print_vector(v_for_ins_3);
		// std::cout << "here\n";


    // std::unique_ptr<B> k2(new B(3)); //enable if в итераторе 
    // std::unique_ptr<B> k3(new B(4));
    // std::unique_ptr<B> k4(new B(-1));
    // ft::vector<B*> v1;

    // v1.push_back(&(*k2));
    // v1.push_back(&(*k3));
    // v1.push_back(&(*k4));

//*************        iterator       *************//
	std::cout << "\n----------------Iterator----------------\n";

	// ft::vector<B*>::iterator ii = v1.begin();
	// std::cout << ii.base() << "\n";
	// std::cout << v1.end().base() << "\n";
	// ii = v1.end();
	// std::cout << ii.base() << "\n";

	ft::vector<int> v6;
	ft::vector<int> vector6;
	v6.assign(1, 2);
    vector6.assign(1000, 1);
    g_start2 = timer();
    v6.push_back(*vector6.rbegin());
    v6.push_back(*(vector6.rbegin() + 1));
	v6.push_back(*(vector6.rbegin() + 2));
	v6.push_back(*(vector6.rbegin() + 1000));
    g_end2 = timer();

	print_vector(v6);

	ft::vector<int>::reverse_iterator o;              // НЕ РАБОТАЕТ
	ft::vector<int>::const_reverse_iterator o1;
	ft::vector<int>::iterator o2;
	ft::vector<int>::const_iterator o13;

	ft::stack<int> stk;
	ft::vector<int> v7;
	ft::stack<int> stack;
	for (int i = 0; i < 100 * _ratio; ++i)
		stack.push(i);
	for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
		stk.push(i);
	g_start2 = timer();
	ft::stack<int> stack2(stk);
	ft::stack<int> stack3;
	stack3 = stack2;
	g_end2 = timer();
	while (stack.size() > 0) {
		v7.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v7.push_back(stack2.top());
		stack2.pop();
	}
}