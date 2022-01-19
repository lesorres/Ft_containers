#include <vector>
#include <map>
#include <iostream>

#include <cstdlib>

int main ()
{
	// std::vector<int> intV(10, 5);
	// std::vector<std::string> intS(10, "string");
	std::vector<int> intV;
	std::vector<char> intC;
	std::vector<std::string> intS;

	std::cout << intV.max_size() << "\n"; //4611686018427387903
	std::cout << intC.max_size() << "\n"; //9223372036854775807
	std::cout << intS.max_size() << "\n"; // 768614336404564650

	int a = atoi("some tring");
	int b = atoi("565656");
	std::cout << a << "\n";
	std::cout << b << "\n";

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

	std::vector<int>::iterator v;
	// std::map<int, int>::iterator v;
	v.__i
	
	return(0);
}