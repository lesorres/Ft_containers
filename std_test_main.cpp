#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> v)
{
	std::cout << "vector content:\n";
	size_t s = v.size();
	for (size_t i = 0; i < s; i++)
		std::cout << v[i];
	std::cout << "\n\n";
}

int main()
{
	std::vector<int> v1;
	for (int i = 0; i < 12; i++)
		v1.push_back(2);
	std::vector<int> v2;
	for (int i = 0; i < 2; i++)
		v2.push_back(1);
	v1.insert(v1.begin(), v2.end(), v2.end());
	print_vector(v1);
	return (0);
}