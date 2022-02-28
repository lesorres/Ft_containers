#include <iostream>
#include "/Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include/sys/time.h"

volatile static time_t g_start2;
volatile static time_t g_end2;
int _ratio = 10000;

#define STD 0

#if STD
#include <vector>
namespace ft = std;
#else
#include "Vector.hpp"
#endif

#include <vector>

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

template <typename T>
void print_vector(std::vector<T> v)
{
	std::cout << "vector content:\n";
	size_t s = v.size();
	for (size_t i = 0; i < s; i++)
		std::cout << v[i];
	std::cout << "\n\n";
}

int main() {

	// ft::vector<int> vector;
    // ft::vector<int> v;
    // vector.assign(1000, 1);
    // v.push_back(*(vector.end() - 1));
    // v.push_back(*(vector.end() - 2));

	// ft::vector<int> vector1;
    // ft::vector<int> v1;
    // vector1.assign(1000, 1);
    // v1.push_back(*(vector1.end() - 1));
    // v1.push_back(*(vector1.end() - 2));

//resize

// 	ft::vector<int> v(14);
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);

// 	v.resize(10, 2);
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);

// 	v.resize(14, 2);
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);

// 	v.resize(29, 2);
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);

// 	v.resize(10, 2);
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);

// //assign

// 	v.assign(2, 5);
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);

// 	v.assign(6, 5);
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);

// 	v.assign(30, 11);
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);

// 	ft::vector<int> v2(6, 7);
// 	print_vector(v2);

// 	v.assign(v2.begin(), v2.end());
// 	std::cout << "vector size: " << v.size() << "\n";
// 	std::cout << "vector cpct: " << v.capacity() << "\n";
// 	print_vector(v);


// 	ft::vector<int> v5(14);
// 	ft::vector<int> v4(10, 12);

// 	v5.assign(v4.begin(), v4.end());

// //erase

//     ft::vector<int> v1;
// 	ft::vector<int> vector;
//     for (int i = 0; i < 9900 * _ratio; ++i)
//         vector.push_back(i);
// 	std::cout << vector.capacity() << "\n";
// 	print_vector(v1);
// 	std::cout << vector.size() << "\n";
//     g_start2 = timer();
//     v1.push_back(*(vector.erase(vector.begin() + 8 * _ratio, vector.end() - 1500 * _ratio)));
// 	print_vector(v1);
//     g_end2 = timer();
//     v1.push_back(*(vector.begin() + 82 * _ratio));
// 	print_vector(v1);
// 	std::cout << vector.size() << "\n";
//     v1.push_back(vector.size());
// 	print_vector(v1);
//     v1.push_back(vector.capacity());
// 	print_vector(v1);

// 	std::vector<int> v3;
// 	std::vector<int> vector2;
//     for (int i = 0; i < 9900 * _ratio; ++i)
//         vector2.push_back(i);
// 	std::cout << vector2.capacity() << "\n";
// 	print_vector(v3);
// 	std::cout << vector2.size() << "\n";
//     g_start2 = timer();
//     v3.push_back(*(vector2.erase(vector2.begin() + 8 * _ratio, vector2.end() - 1500 * _ratio)));
// 	print_vector(v3);
//     g_end2 = timer();
//     v3.push_back(*(vector2.begin() + 82 * _ratio));
// 	print_vector(v3);
// 	std::cout << vector2.size() << "\n";
//     v3.push_back(vector2.size());
// 	print_vector(v3);
//     v3.push_back(vector2.capacity());
// 	print_vector(v3);
// 	print_vector(v3);

std::vector<std::string> v1;
std::vector<std::string> v2;
for (int i = 0; i < 4; i++)
	v1.push_back("asdfg");
v2 = v1;

std::cout << &v1[1] << "\n";
std::cout << &v2[1] << "\n";
	
}