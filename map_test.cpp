#include <map>
#include <iostream>

int main () {
std::map<int, int> x;

x.insert(std::pair<int, int> (1, 1));
x.insert(std::pair<int, int> (2, 2));

std::cout << x.at(3);

return(0);
}