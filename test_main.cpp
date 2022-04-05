#include <iostream>
#include "/Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include/sys/time.h"

volatile static time_t g_start1;
volatile static time_t g_start2;
volatile static time_t g_end1;
volatile static time_t g_end2;
int _ratio = 10000;

#define STD 0

#if STD

#include <vector>
namespace ft = std;
#else
#include <vector> //for cases when both ft and std are needed simultaneously
#include "Vector.hpp"

template <typename T>
void print_vector(std::vector<T> v)
{
	std::cout << "vector content:\n";
	size_t s = v.size();
	for (size_t i = 0; i < s; i++)
		std::cout << v[i];
	std::cout << "\n\n";
}

#endif

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

template <typename T>
void print_vector(ft::vector<T> v)
{
	std::cout << "vector content:\n";
	size_t s = v.size();
	for (size_t i = 0; i < s; i++)
		std::cout << v[i];
	std::cout << "\n\n";
}

int main()
{
	// ft::vector<int> vector;
	// ft::vector<int> v;
	// vector.assign(1000, 1);
	// v.push_back(*(vector.end() - 1));
	// v.push_back(*(vector.end() - 2));

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

//*************       assign     *************//
	std::cout << "\n----------------Assign test----------------\n";

	// ft::vector<int> v_for_assign_0;
	// v_for_assign_0 = v_for_resize_0;

	// v_for_assign_0.assign(2, 5);

	// std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	// std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n";
	// print_vector(v_for_assign_0);

	// v_for_assign_0.assign(6, 5);
	// std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	// std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n";
	// print_vector(v_for_assign_0);

	// v_for_assign_0.assign(30, 11);
	// std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	// std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n";
	// print_vector(v_for_assign_0);

	// ft::vector<int> v_for_assign_1(6, 7);
	// print_vector(v_for_assign_1);

	// v_for_assign_0.assign(v_for_assign_1.begin(), v_for_assign_1.end());
	// std::cout << "vector size: " << v_for_assign_0.size() << "\n";
	// std::cout << "vector cpct: " << v_for_assign_0.capacity() << "\n";
	// print_vector(v_for_assign_0);

	// ft::vector<int> v_for_assign_2(14);
	// ft::vector<int> v_for_assign_3(10, 12);

	// v_for_assign_2.assign(v_for_assign_3.begin(), v_for_assign_3.end());

//*************       erase      *************//
	// std::cout << "\n----------------Erase test----------------\n";

	// ft::vector<int> v1;
	// ft::vector<int> vector;
	// for (int i = 0; i < 9 * _ratio; ++i)
	// 	vector.push_back(i);
	// std::cout << "vector capacity:" << vector.capacity() << "\n";
	// print_vector(v1);
	// std::cout << vector.size() << "\n";
	// g_start2 = timer();
	// v1.push_back(*(vector.erase(vector.begin() + 1, vector.end() - 2)));
	// print_vector(v1);
	// g_end2 = timer();
	// std::cout << "here1\n";
	// v1.push_back(*(vector.begin() + 2 * _ratio)); //exeption in new via construct in push_back
	// std::cout << "here2\n";
	// print_vector(v1);
	// std::cout << vector.size() << "\n";
	// v1.push_back(vector.size());
	// print_vector(v1);
	// v1.push_back(vector.capacity());
	// print_vector(v1);

	// std::vector<int> v3;
	// std::vector<int> vector2;
	// for (int i = 0; i < 9900 * _ratio; ++i)
	// 	vector2.push_back(i);
	// std::cout << vector2.capacity() << "\n";
	// print_vector(v3);
	// std::cout << vector2.size() << "\n";
	// g_start2 = timer();
	// std::cout << "here3\n";
	// v3.push_back(*(vector2.erase(vector2.begin() + 8 * _ratio, vector2.end() - 1500 * _ratio))); // ?
	// std::cout << "here4\n";
	// print_vector(v3);
	// g_end2 = timer();
	// v3.push_back(*(vector2.begin() + 82 * _ratio));
	// print_vector(v3);
	// std::cout << vector2.size() << "\n";
	// v3.push_back(vector2.size());
	// print_vector(v3);
	// v3.push_back(vector2.capacity());
	// print_vector(v3);
	// print_vector(v3);

	// std::vector<std::string> v_for_er_0;

	// for (int i = 0; i < 16; i++)
	// 	v_for_er_0.push_back("asdfg");

	// std::cout << "before erase: size: " << v_for_er_0.size() << ", capacity: " << v_for_er_0.capacity() << "\n";
	// v_for_er_0.erase(v_for_er_0.begin() + 3, v_for_er_0.begin() + 11);
	// std::cout << "after erase:  size: " << v_for_er_0.size() << ", capacity: " << v_for_er_0.capacity() << "\n";
	// std::cout << "capacity shouldn't be shrank after erase\n";

//*************     push_back    *************//
	std::cout << "\n----------------Push_back test----------------\n";

	std::vector<std::string> v_for_pb_0;
	std::vector<std::string> v_for_pb_1;
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
	// 	std::vector<int> v2;
	// 	std::vector<int> vector3;
	// 	std::vector<int> tmp0(vector3);
	// 	std::vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
	// 	tmp = tmp2;
	// 	std::vector<int> tmp3(tmp);
	// 	g_start1 = timer();
	// 	std::vector<int> tmp4(tmp.begin(), tmp.end());
	// 	g_end1 = timer();
	// 	v2.push_back(tmp4.size());
	// 	v2.push_back(tmp4.capacity());
	// 	v2.push_back(tmp[2]);
	// 	v2.push_back(tmp3[2]);
	// 	v2.push_back(tmp4[2]);
	// 	try { std::vector<int> tmp5(-1, -1); }
	// 	catch (std::exception &e) { v2.push_back(1); }

		// ft::vector<int> v4;
		// ft::vector<int> vector4;
		// ft::vector<int> tmp0(vector4);
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

	// ft::vector<int> vector;
    // ft::vector<int> v;
    // vector.assign(1100 * _ratio, 11);
    // ft::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
    // g_start2 = timer();
    // v.push_back(vector[2]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    // long *adr1 = reinterpret_cast<long *>(&vector);
    // long *adr2 = reinterpret_cast<long *>(&tmp);
    // vector.swap(tmp);
    // if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    // 	v.push_back(1);
    // v.push_back(vector[2]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    // vector.swap(tmp3);
    // v.push_back(vector[2]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    // std::swap(vector, tmp2);
    // v.push_back(vector[2]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    // std::swap(vector, tmp4);
    // g_end2 = timer();
    // v.push_back(vector[2]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());

//*************        insert       *************//

	// // 1
	// ft::vector<std::string> v_for_ins_0;
	// for (int i = 0; i < 4; i++)
	// 	v_for_ins_0.push_back("a");
	// v_for_ins_0.push_back("a");
	// v_for_ins_0.push_back("b");
	// v_for_ins_0.push_back("c");
	// v_for_ins_0.push_back("d");

	// std::cout << "here\n";

	// std::cout << "vector size: " << v_for_ins_0.size() << "\n";
	// std::cout << "vector cpct: " << v_for_ins_0.capacity() << "\n";
	// print_vector(v_for_ins_0);

	// v_for_ins_0.insert(v_for_ins_0.begin() + 1, "v");

	// std::cout << "vector size: " << v_for_ins_0.size() << "\n";
	// std::cout << "vector cpct: " << v_for_ins_0.capacity() << "\n";
	// print_vector(v_for_ins_0);

	// // 2
	// ft::vector<std::string> v_for_ins_1 (99, "k");
	// for (int i = 0; i < 90; i++)
	// 	v_for_ins_1.pop_back();

	// std::cout << "vector size: " << v_for_ins_1.size() << "\n";
	// std::cout << "vector cpct: " << v_for_ins_1.capacity() << "\n";
	// print_vector(v_for_ins_1);

	// v_for_ins_1.insert(v_for_ins_1.end(), "v");

	// std::cout << "vector size: " << v_for_ins_1.size() << "\n";
	// std::cout << "vector cpct: " << v_for_ins_1.capacity() << "\n";
	// print_vector(v_for_ins_1);

	// // 3
	// ft::vector<std::string> v_for_ins_2 (5, "k");

	// std::cout << "vector size: " << v_for_ins_2.size() << "\n";
	// std::cout << "vector cpct: " << v_for_ins_2.capacity() << "\n";
	// print_vector(v_for_ins_2);

	// v_for_ins_2.insert(v_for_ins_2.begin(), 11, "v");

	// std::cout << "vector size: " << v_for_ins_2.size() << "\n";
	// std::cout << "vector cpct: " << v_for_ins_2.capacity() << "\n";
	// print_vector(v_for_ins_2);


	ft::vector<int> vector;
	ft::vector<int> v;
	vector.assign(1000, 1);
	g_start2 = timer();
	std::cout << "here\n";
	vector.insert(vector.end() - 50, 4200 * _ratio , 2);
	std::cout << "here2\n";
	g_end2 = timer();
	v.push_back(vector[2121]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());

}