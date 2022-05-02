/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:13:53 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/05/02 16:19:18 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "Enable_if.hpp"

namespace ft 
{
	struct input_iterator_tag  {}; // https://en.cppreference.com/w/cpp/iterator/iterator_tags
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type 			value_type;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef random_access_iterator_tag				iterator_category;
	};

	template<class T>
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

	template <class T>
	class vectorIt : public iterator <random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

		private:
			pointer current;

			explicit vectorIt(pointer const _x) : current(_x) {}
			template <typename, typename> friend class vector;

		public:
			pointer base() const {return current;}
			vectorIt() : current(NULL) {};
			template <class _Up>
			vectorIt(const vectorIt<_Up>& _x, typename ft::enable_if<std::is_convertible<_Up, T>::value>::type* = 0)
					 : current(_x.base()) {};
			~vectorIt() {};

			reference operator*() const {return static_cast<reference>(*current);}
			pointer   operator->() const {return current;}
			vectorIt& operator++() {++current; return *this;}
			vectorIt  operator++(int) {vectorIt __tmp(*this); ++current; return __tmp;}
			vectorIt& operator--() {--current; return *this;}
			vectorIt  operator--(int) {vectorIt __tmp(*this); --current; return __tmp;}
			vectorIt  operator+ (difference_type __n) const {return vectorIt(current + __n);}
			vectorIt& operator+=(difference_type __n) {current += __n; return *this;} 
			vectorIt  operator- (difference_type __n) const {return vectorIt(current - __n);}
			vectorIt& operator-=(difference_type __n) {current -= __n; return *this;}
			reference operator[](difference_type __n) const { return static_cast<reference>(current[__n]); }
	};

	template <class T>
	inline bool operator==(const vectorIt<T>& __x, const vectorIt<T>& __y) { return __x.base() == __y.base(); }
	template <class T>
	inline bool operator!=(const vectorIt<T>& __x, const vectorIt<T>& __y) { return !(__x == __y); }
	template <class T>
	inline bool operator<(const vectorIt<T>& __x, const vectorIt<T>& __y) { return __x.base() < __y.base(); }
	template <class T>
	inline bool operator>(const vectorIt<T>& __x, const vectorIt<T>& __y) { return __y < __x; }
	template <class T>
	inline bool operator>=(const vectorIt<T>& __x, const vectorIt<T>& __y) { return !(__x < __y); }
	template <class T>
	inline bool operator<=(const vectorIt<T>& __x, const vectorIt<T>& __y) { return !(__y < __x); }

	template <class Iter>
	class reverse_vectorIt : public iterator <random_access_iterator_tag, Iter>
	{
		public:
			typedef Iter												iterator_type;
			typedef typename iterator_traits<Iter>::reference			reference;
			typedef typename iterator_traits<Iter>::pointer				pointer;
			typedef typename iterator_traits<Iter>::difference_type		difference_type;
			typedef typename iterator_traits<Iter>::difference_type		iterator_category;

		private:
			iterator_type current;

		public:
			pointer base() const {return current;}
			reverse_vectorIt() : current() {};
			template <class _Up>
			reverse_vectorIt(const reverse_vectorIt<_Up>& _x, typename ft::enable_if<std::is_convertible<_Up, Iter>::value>::type* = 0)
				 : current(_x.base()) {};
			~reverse_vectorIt(){};
			 explicit reverse_vectorIt(Iter _x) : current(_x) {};

			reference operator*() const { return *current; }
			pointer  operator->() const { return current;}
			reverse_vectorIt& operator++() {--current; return *this;}
			reverse_vectorIt  operator++(int) {reverse_vectorIt __tmp(*this); --current; return __tmp;}
			reverse_vectorIt& operator--() {++current; return *this;}
			reverse_vectorIt  operator--(int) {reverse_vectorIt __tmp(*this); ++current; return __tmp;}
			reverse_vectorIt  operator+ (difference_type __n) const {return reverse_vectorIt(current - __n);}
			reverse_vectorIt& operator+=(difference_type __n) {current -= __n; return *this;} 
			reverse_vectorIt  operator- (difference_type __n) const {return reverse_vectorIt(current + __n);}
			reverse_vectorIt& operator-=(difference_type __n) {current += __n; return *this;}
			reference operator[](difference_type __n) const { return static_cast<reference>(current[__n]); }
	};

	template <class T>
	inline bool operator==(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return __x.base() == __y.base(); }
	template <class T>
	inline bool operator!=(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return !(__x == __y); }
	template <class T>
	inline bool operator<(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return __x.base() < __y.base(); }
	template <class T>
	inline bool operator>(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return __y < __x; }
	template <class T>
	inline bool operator>=(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return !(__x < __y); }
	template <class T>
	inline bool operator<=(const reverse_vectorIt<T>& __x, const reverse_vectorIt<T>& __y) { return !(__y < __x); }

	template <class T, class Pair>
	class mapIt : public iterator <bidirectional_iterator_tag, Pair>
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
		
		private:
			iterator_type treeNode;

		public:
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
			bool 			operator<(mapIt const &__x) const {return __x.treeNode->pair > treeNode->pair;}
			bool 			operator>(mapIt const &__x) const {return treeNode->pair > __x.treeNode->pair;}
			bool 			operator>=(mapIt const &__x) const {return treeNode->pair >= __x.treeNode->pair;}
			bool 			operator<=(mapIt const &__x) const {return treeNode->pair <= __x.treeNode->pair;}

		private:
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

	template <class Iter>
	class reverse_mapIt : public iterator <bidirectional_iterator_tag, Iter>
	{
		public:
			typedef Iter												iterator_type;
			typedef typename iterator_traits<Iter>::difference_type		difference_type;
			typedef typename iterator_traits<Iter>::value_type			value_type;
			typedef typename iterator_traits<Iter>::reference			reference;
			typedef const typename iterator_traits<Iter>::reference		const_reference;
			typedef typename iterator_traits<Iter>::pointer				pointer;
			typedef const typename iterator_traits<Iter>::pointer		const_pointer;
			typedef typename iterator_traits<Iter>::iterator_category	iterator_category;

		private:
			iterator_type iter;

		public:
			iterator_type base() const {return iter;}
			reverse_mapIt(iterator_type value = NULL) : iter(value) {};
			template <class _Up>
			reverse_mapIt(const reverse_mapIt<_Up>& _x, typename ft::enable_if<std::is_convertible<_Up, Iter>::value>::type* = 0)
					: iter(_x.base()) {}
			~reverse_mapIt() {}
			reverse_mapIt	&operator=(const reverse_mapIt &obj)	{ iter = obj.iter; return *this; }
			reference 		operator*()								{return *iter;}
			pointer 		operator->()							{return &(operator*());}
			reverse_mapIt&	operator++()							{--iter; return *this;}
			reverse_mapIt 	operator++(int)							{reverse_mapIt tmp(*this); iter--; return tmp;}
			reverse_mapIt& 	operator--()							{++iter; return *this;}
			reverse_mapIt 	operator--(int)							{reverse_mapIt tmp(*this); iter++; return tmp;}
			reverse_mapIt 	operator+(difference_type __n) const	{return reverse_mapIt(iter - __n);}
			reverse_mapIt& 	operator+=(difference_type __n)			{iter -= __n; return *this;}
			reverse_mapIt 	operator-(difference_type __n) const	{return reverse_mapIt(iter + __n);}
			reverse_mapIt& 	operator-=(difference_type __n)			{iter += __n; return *this;}
			reference 		operator[](difference_type __n) const	{return *(*this + __n);}

			bool			operator==(reverse_mapIt const &__x) const			{return iter == __x.iter;}
			bool			operator!=(reverse_mapIt const &__x) const			{return iter != __x.iter;}
			bool 			operator<(reverse_mapIt const &__x) const			{return iter < __x.iter;}
			bool 			operator>(reverse_mapIt const &__x) const			{return iter > __x.iter;}
			bool 			operator>=(reverse_mapIt const &__x) const			{return iter >= __x.iter;}
			bool 			operator<=(reverse_mapIt const &__x) const			{return iter <= __x.iter;}
	};
}
#endif