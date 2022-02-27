#include "Vector.hpp"
// #include "set.hpp"
// #include "map.hpp"
// #include <vector>
// #include <deque>
// #include "stack.hpp"

template <class It>
void foo1234(It i, ft::input_iterator_tag){
    std::cout << "Input_iterator" << std::endl;
}
template <class It>
void foo1234(It i, ft::bidirectional_iterator_tag){
    std::cout << "bidirectional_iterator" << std::endl;
}
template <class It>
void foo1234(It i, ft::random_access_iterator_tag){
    std::cout << "random_iterator" << std::endl;
}
template <class It>
typename ft::iterator_traits<It>::iterator_category Iter_cat(It i)
{
    typename ft::iterator_traits<It>::iterator_category k;
    return (k);
}
template <class It>
void foo4321(It i) {
    foo1234(i, Iter_cat(i));
}
int main() {
    // ft::map<int, int> k;
    ft::vector<int> k1;
    // foo4321(k.begin());
    foo4321(k1.begin());
    return (0);
}