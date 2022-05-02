#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
	// https://www.cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	// https://www.cplusplus.com/reference/algorithm/equal/
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1; ++first2;
		}
		return true;
	}
	
// DONE : логика переписана 
	template <class K, typename V>
	struct pair
	{
		typedef K		first_type;
		typedef V		second_type;

		first_type first;
		second_type second;

		pair() : first(), second() {}
		pair(first_type const& x, second_type const& y) : first(x), second(y) {}

		template <class T1, class T2>
		pair(const pair<T1, T2>& z) : first(z.first), second(z.second) {}

		pair& operator=(pair const& z)
		{
			second = z.second;
			first = z.first;
			return (*this);
		}
	};

	template <class K, class V>
	inline bool operator==(const pair<K, V>& lhs, const pair<K, V>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class K, class V>
	inline bool operator!=(const pair<K, V>& lhs, const pair<K, V>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class K, class V>
	inline bool operator< (const pair<K, V>& lhs, const pair<K, V>& rhs)
	{
		return ((lhs.second < rhs.second && !(rhs.first < lhs.first)) || lhs.first < rhs.first);
	}

	template <class K, class V>
	inline bool operator> (const pair<K, V>& lhs, const pair<K, V>& rhs)
	{
		return (rhs < lhs);
	}

	template <class K, class V>
	inline bool operator>=(const pair<K, V>& lhs, const pair<K, V>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class K, class V>
	inline bool operator<=(const pair<K, V>& lhs, const pair<K, V>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class K, class V>
	inline pair<K, V> make_pair(K lhs, V rhs)
	{
		return (pair<K, V>(lhs, rhs));
	}
}

#endif