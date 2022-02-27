#include <iostream>

#define STD 0

#if STD
#include <vector>
namespace ft = std;
#else
#include "Vector.hpp"
#endif

template <typename T>
void print_vector(ft::vector<T> v)
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

	ft::vector<int> v(14);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
	print_vector(v);

	v.resize(10, 2);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
	print_vector(v);

	v.resize(14, 2);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
	print_vector(v);

	v.resize(29, 2);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
	print_vector(v);

	v.resize(10, 2);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
	print_vector(v);

//assign

	v.assign(2, 5);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
	print_vector(v);

	v.assign(6, 5);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
	print_vector(v);

	v.assign(30, 11);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector cpct: " << v.capacity() << "\n";
	print_vector(v);

	ft::vector<int> v2(6, 7);
	print_vector(v2);
	
}