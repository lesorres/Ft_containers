# ifndef CONFIG_HPP
# define CONFIG_HPP

#define STD 1

#if STD

#include <vector>
#include <stack>
#include <map>
#include <set>
namespace ft = std;

#else
// #include <vector> //for cases when both ft and std are needed simultaneously
#include "../Vector.hpp"
#include "../Stack.hpp"
#include "../Map.hpp"
#include "../Set.hpp"

#endif

int _ratio = 1000;
#endif
