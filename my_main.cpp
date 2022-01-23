#define STD 1

#include <iostream>
#include <cstdlib>

#if STD
#include <vector>
#include <map>
#else
#include "vector.hpp"
// #include "map.hpp"
#endif



#if STD
namespace ft = std;
// source: https://en.cppreference.com/w/cpp/container/vector/vector
template<typename T>
std::ostream& operator<<(std::ostream& s, const ft::vector<T>& v) 
{
	s.put('[');
	char comma[3] = {'\0', ' ', '\0'};
	for (const auto& e : v) {
		s << comma << e;
		comma[0] = ',';
	}
	return s << ']';
}
#endif

int main ()
{
	// std::vector<int> intV(10, 5);
	// std::vector<std::string> intS(10, "string");
	// std::vector<int> intV;
	// std::vector<char> intC;
	// std::vector<std::string> intS;

	// std::cout << intV.max_size() << "\n"; //4611686018427387903
	// std::cout << intC.max_size() << "\n"; //9223372036854775807
	// std::cout << intS.max_size() << "\n"; // 768614336404564650

	// int a = atoi("some tring");
	// int b = atoi("565656");
	// std::cout << a << "\n";
	// std::cout << b << "\n";

	//____________________SWAP_BEGIN____________________
	// std::vector<int> foo (3,100);   // three ints with a value of 100
	// std::vector<int> bar (5,200);   // five ints with a value of 200

	// std::cout << foo.capacity() << "\n";
	// std::cout << bar.capacity() << "\n";
	// std::cout << foo.size() << "\n";
	// std::cout << bar.size() << "\n";

	// foo.swap(bar);

	// std::cout << "foo contains:";
	// for (unsigned i=0; i<foo.size(); i++)
	// 	std::cout << ' ' << foo[i];
	// std::cout << '\n';

	// std::cout << "bar contains:";
	// for (unsigned i=0; i<bar.size(); i++)
	// 	std::cout << ' ' << bar[i];
	// std::cout << '\n';

	// std::cout << foo.capacity() << "\n";
	// std::cout << bar.capacity() << "\n";
	// std::cout << foo.size() << "\n";
	// std::cout << bar.size() << "\n";
	//____________________SWAP_END____________________

	// std::vector<int>::iterator v;
	// // std::map<int, int>::iterator v;
	// const int i = 3;
	// int const * ptr = &i;

	// ft::vector<int> myVect;



	//*************   fill constructor test   *************//
	// ft::vector<std::string> strV1 (3, "hi");
	// ft::vector<std::string> strV2 (0, "bla");
	// std::vector<std::string> strV3 (-3, "hi"); //terminating with uncaught exception of type std::length_error: vector
	//*************   fill constructor test   *************//

	#if STD
	//*************   [] operator test   *************//
	// std::cout << "strV1 " << strV1 << "\n";
	// std::cout << "strV1 " << strV2 << "\n";
	// std::cout << "strV1[1] " << strV2.at(1) << "\n";
	// std::cout << "strV1[7] " << strV2.at(7) << "\n"; //terminating with uncaught exception of type std::out_of_range: vector
	//*************   [] operator test   *************//

	//*************   assignment operator test   *************//
	ft::vector<std::string> strV1 (3, "hi");
	ft::vector<std::string> strV2 (14, "bla");
	ft::vector<std::string> strV3;
	ft::vector<std::string> strV4;
	for (int i = 0 ; i < 10 ; ++i)
		strV4.push_back("kkk");
	std::cout << "strV1 cap: " << strV1.capacity() << "	strV1 size: " << strV1.size() << "\n";
	std::cout << "strV2 cap: " << strV2.capacity() << "	strV2 size: " << strV2.size() << "\n";
	std::cout << "strV3 cap: " << strV3.capacity() << "	strV3 size: " << strV3.size() << "\n";
	std::cout << "strV4 cap: " << strV4.capacity() << "	strV4 size: " << strV4.size() << "\n";

	strV4 = strV2;
	std::cout << "\nafter strV4 = strV2\n\n";
	std::cout << "strV1 cap: " << strV1.capacity() << "	strV1 size: " << strV1.size() << "\n";
	std::cout << "strV2 cap: " << strV2.capacity() << "	strV2 size: " << strV2.size() << "\n";
	std::cout << "strV3 cap: " << strV3.capacity() << "	strV3 size: " << strV3.size() << "\n";
	std::cout << "strV4 cap: " << strV4.capacity() << "	strV4 size: " << strV4.size() << "\n";
	//*************   assignment operator test   *************//

	#else
	// for (size_t i = 0; i < strV1._size; ++i)
	// 	 std::cout << "strV1 " << strV1[i] << "\n";
	// for (size_t i = 0; i < strV2._size; ++i)
	// 	 std::cout << "strV1 " << strV2[i] << "\n";
	// // std::cout << "strV1 " << strV3 << "\n";
	std::cout << "strV1[1] " << strV2.at(1) << "\n"; //same as std::vector
	std::cout << "strV1[7] " << strV2.at(7) << "\n"; //same as std::vector
	#endif
	
	return(0);
}