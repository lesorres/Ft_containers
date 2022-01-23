//for reference:
#include <iterator>

namespace ft 
{
	struct input_iterator_tag  {}; //iterator 51 - https://en.cppreference.com/w/cpp/iterator/iterator_tags
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// template <class It>
	// int distance(It first, It second, bidirectional_iterator_tag * p = nullptr )
	// {
	// 		int i = 0;
	// 		while(first < second){
	// 			first++;
	// 			i++;
	// 		}
	// 		return i;
	// }

	// template <class It>
	// int distance(It first, It second, random_access_iterator_tag * p = nullptr )
	// {
	// 	int i = second.base() - first.base();
	// 		return i;
	// }

	// template <class It>
	// int distance(It first, It second)
	// {
	// 	typename It::iterator_category p;
	// 		return distance(first, second, &p);
	// }

	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T										value_type;
		typedef Distance 								difference_type;
		typedef Pointer									pointer;
		typedef Reference								reference;
		typedef Category								iterator_category;
	};

	template<class Iterator> //iterator 20
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type; //distance
		typedef typename Iterator::value_type 			value_type;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<class T> //iterator 31
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef random_access_iterator_tag				iterator_category;
	};

	template<class T> // plauger 116
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const									T* pointer;
		typedef const									T& reference;
		typedef random_access_iterator_tag				iterator_category;
	};


	// template <class T>
	// class vectorIt : public iterator <random_access_iterator_tag, T>
	// {
	// 	public:

	// 		typedef vectorIt<T>																iterator_type;
	// 		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
	// 		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
	// 		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
	// 		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
	// 		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

	// 	private: // protected?
	// 		pointer																			current;

	template <class Iter> // iterator 1097, 1314
	//Iter -> as a pointer
	class vectorIt
	{
		public:
			typedef Iter															iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type	;
			typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference			reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category 	iterator_category;
		private: // protected?
			pointer																			current;
		public:
			iterator_type base() const {return current;} // iterator 1431

			vectorIt() : current(NULL) {}; // iterator 1119

			explicit vectorIt(iterator_type const &_x) : current(_x) {};

			template <class _Up>
			vectorIt(const vectorIt<_Up>& _x) : current(_x.base()) {}; // iterator 1124

			// под вопросом, возможно is_convertible нужен чтобы в конструктор не приходили левые типы, но это 11 стандарт
			// template <class _Up>
			// move_iterator(const vectorIt<_Up>& __u, // iterator 1338
			// typename enable_if<is_convertible<_Up, iterator_type>::value>::type* = 0) : current(_x.base()) {};

			// реализауия из move_iterator:
			reference operator*() const { return static_cast<reference>(*current); } // iterator 1127 отличается
			pointer  operator->() const { return current;} //отличается
			vectorIt& operator++() {++current; return *this;}
			vectorIt  operator++(int) {vectorIt __tmp(*this); ++current; return __tmp;}
			vectorIt& operator--() {--current; return *this;}
			vectorIt  operator--(int) {vectorIt __tmp(*this); --current; return __tmp;}
			vectorIt  operator+ (difference_type __n) const {return vectorIt(current + __n);} //отличается
			vectorIt& operator+=(difference_type __n) {current += __n; return *this;} 
			vectorIt  operator- (difference_type __n) const {return vectorIt(current - __n);} //отличается
			vectorIt& operator-=(difference_type __n) {current -= __n; return *this;} //отличается
			reference operator[](difference_type __n) const { return static_cast<reference>(current[__n]); } //отличается

			// http://www.cplusplus.com/reference/iterator/reverse_iterator/operators/
			// no need in friend functions, because base is public
			// template <class _Iter1> // iterator 1451
			// friend bool operator==(const vectorIt<_Iter1>&, const vectorIt<_Iter1>&);
			// template <class _Iter1>
			// friend bool operator!=(const vectorIt<_Iter1>&, const vectorIt<_Iter1>&);
			// template <class _Iter1>
			// friend bool operator<(const vectorIt<_Iter1>&, const vectorIt<_Iter1>&);
			// template <class _Iter1>
			// friend bool operator>(const vectorIt<_Iter1>&, const vectorIt<_Iter1>&);
			// template <class _Iter1>
			// friend bool operator>=(const vectorIt<_Iter1>&, const vectorIt<_Iter1>&);
			// template <class _Iter1>
			// friend bool operator<=(const vectorIt<_Iter1>&, const vectorIt<_Iter1>&);
	};

	template <class _Iter1>
	inline bool operator==(const vectorIt<_Iter1>& __x, const vectorIt<_Iter1>& __y) { return __x.base() == __y.base(); }
	template <class _Iter1>
	inline bool operator!=(const vectorIt<_Iter1>& __x, const vectorIt<_Iter1>& __y) { return !(__x == __y); }
	template <class _Iter1>
	// add exeption "Attempted to compare incomparable iterators" // iterator 1535
	inline bool operator<(const vectorIt<_Iter1>& __x, const vectorIt<_Iter1>& __y) { return __x.base() < __y.base(); }
	template <class _Iter1>
	inline bool operator>(const vectorIt<_Iter1>& __x, const vectorIt<_Iter1>& __y) { return __y < __x; }
	template <class _Iter1>
	inline bool operator>=(const vectorIt<_Iter1>& __x, const vectorIt<_Iter1>& __y) { return !(__x < __y); }
	template <class _Iter1>
	inline bool operator<=(const vectorIt<_Iter1>& __x, const vectorIt<_Iter1>& __y) { return !(__y < __x); }
}


/* vector:
650 - reverse_iterator
794 - back_insert_iterator - плохо читаем
827 - front_insert_iterator - плохо читаем
860 - insert_iterator - плохо читаем
896 - istream_iterator - плохо читаем
957 - ostream_iterator - плохо читаем
986 - istreambuf_iterator - плохо читаем
1056 - ostreambuf_iterator - плохо читаем

1096 - move_iterator - относительно понятная реализация
1314 - __wrap_iter - относительно понятная реализация
*/