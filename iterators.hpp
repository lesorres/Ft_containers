//for reference:
#include <iterator>

namespace ft 
{
	struct input_iterator_tag  {}; //iterator 51 - https://en.cppreference.com/w/cpp/iterator/iterator_tags
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class Iterator> //iterator 20
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type; //distance
		typedef typename Iterator::value_type 			value_type;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::iterator_category	iterator_category;
		// typedef typename Iterator::const_pointer 	const_pointer;
		// typedef typename Iterator::const_reference	const_reference;
	};

	template<class T> //iterator 31
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef random_access_iterator_tag				iterator_category;
		// typedef const T*								const_pointer;
	    // typedef const T&								const_reference;
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
			// typedef typename ft::iterator_traits<iterator_type>::const_pointer	const_pointer;
			// typedef typename ft::iterator_traits<iterator_type>::const_reference	const_reference;
		private: // protected?
			iterator_type															current;
		public:
			iterator_type base() const {return curren;} // iterator 1431

			vectorIt() : current(NULL) {}; // iterator 1119

			explicit vectorIt(iterator_type _x) : current(_x) {};

			template <class _Up>
			vectorIt(const vectorIt<_Up>& _x) : current(_x.base()) {}; // iterator 1124

			// под вопросом, возможно is_convertible нужен чтобы в конструктор не приходили левые типы, но это 11 стандарт
			// template <class _Up>
			// move_iterator(const __wrap_iter<_Up>& __u, // iterator 1338
			// typename enable_if<is_convertible<_Up, iterator_type>::value>::type* = 0) : current(_x.base()) {};

			// реализауия из move_iterator:
			reference operator*() const { return static_cast<reference>(*current); } // iterator 1127 отличается
			pointer  operator->() const { return current;} //отличается
			move_iterator& operator++() {++current; return *this;}
			move_iterator  operator++(int) {move_iterator __tmp(*this); ++current; return __tmp;}
			move_iterator& operator--() {--current; return *this;}
			move_iterator  operator--(int) {move_iterator __tmp(*this); --current; return __tmp;}
			move_iterator  operator+ (difference_type __n) const {return move_iterator(current + __n);} //отличается
			move_iterator& operator+=(difference_type __n) {current += __n; return *this;} 
			move_iterator  operator- (difference_type __n) const {return move_iterator(current - __n);} //отличается
			move_iterator& operator-=(difference_type __n) {current -= __n; return *this;} //отличается
			reference operator[](difference_type __n) const { return static_cast<reference>(current[__n]); } //отличается

			template <class _Iter1, class _Iter2>
			bool operator==(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&);

			template <class _Iter1, class _Iter2>
			bool operator<(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&);

			template <class _Iter1, class _Iter2>
			bool operator!=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&);

			template <class _Iter1, class _Iter2>
			bool operator>(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&);

			template <class _Iter1, class _Iter2>
			bool operator>=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&);

			template <class _Iter1, class _Iter2>
			bool operator<=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&);
	};
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