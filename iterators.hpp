/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:13:53 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/04/26 23:39:39 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "Enable_if.hpp"
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

	// template <class Iter> // iterator 1097, 1314
	// //Iter -> as a pointer
	// class vectorIt
	// {
	// 	public:
	// 		typedef Iter															iterator_type;
	// 		typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
	// 		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type	;
	// 		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
	// 		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
	// 		typedef typename ft::iterator_traits<iterator_type>::iterator_category 	iterator_category;

	template <class T>
	class vectorIt : public iterator <random_access_iterator_tag, T> // в итераторе нет operator=
	{
		public:
			typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

		private: // protected?
			pointer																			current;

			explicit vectorIt(pointer const _x) : current(_x) {}
			template <typename, typename> friend class vector;

		public:
			pointer base() const {return current;} // iterator 1431
			vectorIt() : current(NULL) {}; // iterator 1119
			// explicit vectorIt(pointer const &_x) : current(_x) {};
			// explicit vectorIt(iterator_type const &_x) : current(_x.current) {};
			template <class _Up>
			vectorIt(const vectorIt<_Up>& _x, typename ft::enable_if<std::is_convertible<_Up, T>::value>::type* = 0)
					 : current(_x.base()) {}; // iterator 1124    // !!!!!!!!! добавить enable_if
			~vectorIt() {};
			// под вопросом, возможно is_convertible нужен чтобы в конструктор не приходили левые типы, но это 11 стандарт
			// template <class _Up>
			// move_iterator(const vectorIt<_Up>& __u, // iterator 1338
			// typename enable_if<is_convertible<_Up, iterator_type>::value>::type* = 0) : current(_x.base()) {};

			// реализация из move_iterator:
			reference operator*() const {return static_cast<reference>(*current);} // iterator 1127 отличается
			pointer   operator->() const {return current;} //отличается
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
			// template <class T> // iterator 1451
			// friend bool operator==(const vectorIt<T>&, const vectorIt<T>&);
			// template <class T>
			// friend bool operator!=(const vectorIt<T>&, const vectorIt<T>&);
			// template <class T>
			// friend bool operator<(const vectorIt<T>&, const vectorIt<T>&);
			// template <class T>
			// friend bool operator>(const vectorIt<T>&, const vectorIt<T>&);
			// template <class T>
			// friend bool operator>=(const vectorIt<T>&, const vectorIt<T>&);
			// template <class T>
			// friend bool operator<=(const vectorIt<T>&, const vectorIt<T>&);
	};

	template <class T>
	inline bool operator==(const vectorIt<T>& __x, const vectorIt<T>& __y) { return __x.base() == __y.base(); }
	template <class T>
	inline bool operator!=(const vectorIt<T>& __x, const vectorIt<T>& __y) { return !(__x == __y); }
	template <class T>
	// add exeption "Attempted to compare incomparable iterators" // iterator 1535
	inline bool operator<(const vectorIt<T>& __x, const vectorIt<T>& __y) { return __x.base() < __y.base(); }
	template <class T>
	inline bool operator>(const vectorIt<T>& __x, const vectorIt<T>& __y) { return __y < __x; }
	template <class T>
	inline bool operator>=(const vectorIt<T>& __x, const vectorIt<T>& __y) { return !(__x < __y); }
	template <class T>
	inline bool operator<=(const vectorIt<T>& __x, const vectorIt<T>& __y) { return !(__y < __x); }

	template <class Iter>
	class reverse_vectorIt : public iterator <random_access_iterator_tag, Iter>
	// class reverse_vectorIt			// раотает и без наследования которое на строчке выше 
	{
		public:

			typedef Iter																	iterator_type;
			typedef typename iterator_traits<Iter>::reference								reference;
			typedef typename iterator_traits<Iter>::pointer									pointer;
			typedef typename iterator_traits<Iter>::difference_type							difference_type;
			typedef typename iterator_traits<Iter>::difference_type							iterator_category; //по сути тут не нужен

		private: // protected?
			iterator_type																			current;

			//  explicit reverse_vectorIt(pointer const _x) : current(_x) {};
			template <typename, typename> friend class vector;  // СКОРЕЕ ВСЕГО МОЖНО УБРАТЬ

		public:
			pointer base() const {return current;} // iterator 1431
			reverse_vectorIt() : current() {}; // iterator 1119
			template <class _Up>
			reverse_vectorIt(const reverse_vectorIt<_Up>& _x) : current(_x.base()) {}; // iterator 1124
			~reverse_vectorIt(){};
			 explicit reverse_vectorIt(Iter _x) : current(_x) {};

			reference operator*() const { return *current; } // iterator 1127 отличается
			pointer  operator->() const { return current;} //отличается
			reverse_vectorIt& operator++() {--current; return *this;}
			reverse_vectorIt  operator++(int) {reverse_vectorIt __tmp(*this); --current; return __tmp;}
			reverse_vectorIt& operator--() {++current; return *this;}
			reverse_vectorIt  operator--(int) {reverse_vectorIt __tmp(*this); ++current; return __tmp;}
			reverse_vectorIt  operator+ (difference_type __n) const {return reverse_vectorIt(current - __n);} //отличается
			reverse_vectorIt& operator+=(difference_type __n) {current -= __n; return *this;} 
			reverse_vectorIt  operator- (difference_type __n) const {return reverse_vectorIt(current + __n);} //отличается
			reverse_vectorIt& operator-=(difference_type __n) {current += __n; return *this;} //отличается
			reference operator[](difference_type __n) const { return static_cast<reference>(current[__n]); } //отличается
	};

	template <class T>
	inline bool operator==(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return __x.base() == __y.base(); }
	template <class T>
	inline bool operator!=(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return !(__x == __y); }
	template <class T>
	// add exeption "Attempted to compare incomparable iterators" // iterator 1535
	inline bool operator<(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return __x.base() < __y.base(); }
	template <class T>
	inline bool operator>(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return __y < __x; }
	template <class T>
	inline bool operator>=(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return !(__x < __y); }
	template <class T>
	inline bool operator<=(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return !(__y < __x); }

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

//DONE
	template <class T, class Pair>
	class mapIt : public iterator <bidirectional_iterator_tag, Pair> // в итераторе нет operator=
	{
	public:
		typedef T																			iterator_type;
		typedef typename ft::iterator<bidirectional_iterator_tag, Pair>::value_type			value_type;
		typedef typename ft::iterator<bidirectional_iterator_tag, Pair>::difference_type	difference_type;
		typedef typename ft::iterator<bidirectional_iterator_tag, Pair>::pointer			pointer;
		typedef const typename  ft::iterator<bidirectional_iterator_tag, Pair>::pointer		const_pointer;
		typedef typename ft::iterator<bidirectional_iterator_tag, Pair>::reference			reference;
		typedef const typename ft::iterator<bidirectional_iterator_tag, Pair>::reference	const_reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;

		iterator_type base() const { return treeNode; }
		mapIt(T value = NULL) : treeNode(value) {};
		template <class U, class P>
		mapIt(const mapIt<U, P>& _x,
			typename ft::enable_if<std::is_convertible<U, T>::value>::type* = 0)
				: treeNode(_x.base()) {};
		~mapIt() {};

		reference		operator*() {return *(treeNode->pair);}
		const_reference operator*() const {return *(treeNode->pair);}
		pointer			operator->() {return treeNode->pair;}
		const_pointer	operator->() const {return treeNode->pair;}
		mapIt			&operator++()
		{
			moveToNextNode();
			return *this;
		}
		mapIt			operator++(int)
		{
			mapIt __tmp(*this);
			moveToNextNode();
			return __tmp;
		}
		mapIt			&operator--()
		{
			moveToPreviousNode();
			return *this;
		}
		mapIt			operator--(int)
		{
			mapIt __tmp(*this);
			moveToPreviousNode();
			return __tmp;
		}
		bool			operator==(mapIt const &__x) const {return treeNode == __x.treeNode;}
		bool			operator!=(mapIt const &__x) const {return treeNode != __x.treeNode;}
		bool 			operator>(mapIt const &__x) const {return treeNode->pair > __x.treeNode->pair;}
		bool 			operator<(mapIt const &__x) const {return __x.treeNode->pair > treeNode->pair;}
		bool 			operator<=(mapIt const &__x) const {return treeNode->pair <= __x.treeNode->pair;}
		bool 			operator>=(mapIt const &__x) const {return treeNode->pair >= __x.treeNode->pair;}
	
	private:
		T treeNode;

		void moveToPreviousNode()
		{
			T tmp;

			if (treeNode->NIL)
				treeNode = treeNode->parent;
			else if (!treeNode->left->NIL)
			{
				treeNode = treeNode->left;
				while (!treeNode->right->NIL)
					treeNode = treeNode->right;
			}
			else
			{
				tmp = treeNode;
				treeNode = treeNode->parent;
				while (treeNode->right != tmp)
				{
					tmp = treeNode;
					if (!treeNode->parent)
					{
						treeNode = tmp->left - 1;
						break;
					}
					treeNode = treeNode->parent;
				}
			}
		}

		void moveToNextNode()
		{
			T curnt;
			T tmp;

			if (treeNode->NIL && treeNode->begin != treeNode)
				treeNode = treeNode->begin;
			else if (!treeNode->right->NIL)
			{
				treeNode = treeNode->right;
				while (!treeNode->left->NIL)
					treeNode = treeNode->left;
			}
			else
			{
				tmp = treeNode;
				curnt = treeNode;
				treeNode = treeNode->parent;
				if (!treeNode)
				{
					treeNode = curnt->right;
					return;
				}
				while (treeNode->left != tmp)
				{
					if (!treeNode->parent)
					{
						treeNode = curnt->right;
						break;
					}
					tmp = treeNode;
					treeNode = treeNode->parent;
				}
			}
		}
	};

	template <class T>
	class reverse_iterator : public iterator <bidirectional_iterator_tag, T>
	{
		T iterator;
	public:
		typedef T                                                					iterator_type;
		typedef typename iterator_traits<T>::difference_type     					difference_type;
		typedef typename iterator_traits<T>::value_type         					value_type;
		typedef typename iterator_traits<T>::reference           					reference;
		typedef const typename iterator_traits<T>::reference     					const_reference;
		typedef typename iterator_traits<T>::pointer             					pointer;
		typedef const typename iterator_traits<T>::pointer       					const_pointer;
		typedef typename iterator_traits<T>::iterator_category  					iterator_category;

		reverse_iterator(iterator_type value = nullptr) : iterator(value) 				{};
		~reverse_iterator()										{}
		template <class U> reverse_iterator(const reverse_iterator<U>& other,
				typename ft::enable_if<std::is_convertible<U, T>::value>::type* = 0)
						: iterator(other.base()) 					{}
		reverse_iterator	&operator=(const reverse_iterator &obj)					{ iterator = obj.iterator; return *this; }
		iterator_type 		base() const								{ return iterator; }
		reference 		operator*()		                         			{ return *iterator; }
		pointer 		operator->()		                          			{ return &(operator*()); }
		reverse_iterator&	operator++()                     					{ --iterator; return *this; }
		reverse_iterator 	operator++(int)                    					{ reverse_iterator tmp(*this); iterator--; return tmp; }
		reverse_iterator& 	operator--()                      					{ ++iterator; return *this; }
		reverse_iterator 	operator--(int)                    					{ reverse_iterator tmp(*this); iterator++; return tmp; }
		reverse_iterator 	operator+(difference_type n) const 					{ return reverse_iterator(iterator - n); }
		reverse_iterator& 	operator+=(difference_type n)     					{ iterator -= n; return *this; }
		reverse_iterator 	operator-(difference_type n) const 					{ return reverse_iterator(iterator + n); }
		reverse_iterator& 	operator-=(difference_type n)     					{ iterator += n; return *this; }
		reference 		operator[](difference_type n) const       				{ return *(*this + n); }
		bool			operator==(reverse_iterator const &obj) const 				{ return iterator == obj.iterator; }
		bool			operator!=(reverse_iterator const &obj) const 				{ return iterator != obj.iterator; }
		bool 			operator<(reverse_iterator const &obj) const 				{ return iterator < obj.iterator; }
		bool 			operator>(reverse_iterator const &obj) const 				{ return iterator > obj.iterator; }
		bool 			operator<=(reverse_iterator const &obj) const 				{ return iterator <= obj.iterator; }
		bool 			operator>=(reverse_iterator const &obj) const 				{ return iterator >= obj.iterator; }
	};
}
#endif