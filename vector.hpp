/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:01:22 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/01/24 22:51:24 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iterators.hpp"

//for reference:
#include <vector>
#include <iterator>

namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
		// allocator_traits wasn't used because it is implemented only in C++11
		public:
			typedef				Allocator							allocator_type; //
			typedef typename	allocator_type::size_type			size_type;

		public: //protected:
			typedef					T										value_type;
			typedef	typename		allocator_type::reference				reference;
			typedef const typename	allocator_type::const_reference			const_reference; // value_type&
			typedef typename		allocator_type::difference_type			difference_type; // std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
			typedef typename		allocator_type::pointer					pointer;
			typedef typename		allocator_type::const_pointer			const_pointer;
			typedef	typename		ft::vectorIt<value_type>				iterator;
			typedef	typename		ft::vectorIt<const value_type>			const_iterator;
			typedef	typename		ft::reverse_vectorIt<value_type>		reverse_iterator;
			typedef	typename		ft::reverse_vectorIt<const value_type>	const_reverse_iterator;

			// typedef vectorIt<value_type, бла бла > iterotor;
			// typedef typename		ft::vector_iterator<value_type>			iterator;
			// typedef typename		ft::vector_iterator<const value_type>	const_iterator;
			// typedef typename		ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef typename		ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		
			pointer														_begin; //buffer
			// pointer														_end;
			// pointer														_cap_end;
			size_type													_size; //?
			size_type													_capacity; //?
			allocator_type												_alloc;

		public:
			//MEMBER FUNCTIONS
			// explicit vector (const allocator_type& alloc = allocator_type())				// default constructor
			// 				: _begin(NULL), _end(NULL), _cap_end(NULL), _alloc(alloc);
			// explicit vector (size_type n, const const_reference val = value_type(),		// fill constructor
			// 				const allocator_type& alloc = allocator_type());
			// template <class InputIt>														// range constructor
			// vector (InputIt first, InputIt last,
			// 				const allocator_type& alloc = allocator_type());
			// vector (const vector& x);													// copy constructor
			// virtual ~vector();															// destructor
			// vector& operator= (const vector& x);											// copy assignment operator

			// //ITERATORS
			// iterator					begin()  {return (_begin);};
			// const_iterator			begin() const;
			// iterator					end();
			// const_iterator			end() const;
			// reverse_iterator			rbegin();
			// const_reverse_iterator	rbegin() const;
			// reverse_iterator			rend();
			// const_reverse_iterator	rend() const;

			// //CAPACITY
			// size_type				size() const;
			// size_type				max_size() const;
			// void						resize (size_type n, value_type val = value_type());
			// size_type				capacity() const;
			// bool						empty() const;
			// void						reserve (size_type n);

			// //ELEMENT ACCESS
			// reference				operator[] (size_type n);
			// const_reference			operator[] (size_type n) const;
			// reference				at (size_type n);
			// const_reference			at (size_type n) const;
			// reference				front();
			// const_reference			front() const;
			// reference				ack();
			// const_reference			back() const;

			// //MODIFIERS
			// template <class InputIterator>
			// void						assign (InputIterator first, InputIterator last);
			// void						assign (size_type n, const const_reference val);
			// void						push_back (const const_reference val);
			// void						pop_back();
			// iterator					insert (iterator position, const const_reference val)
			// void						insert (iterator position, size_type n, const const_reference val)
			// template <class Iterator>
			// void						insert (iterator position, InputIterator first, InputIterator last)
			// iterator					erase (iterator position);
			// iterator					erase (iterator first, iterator last);
			// void						swap (vector& x);
			// void						clear();
			// allocator_type			get_allocator() const;

			//MEMBER FUNCTIONS
			explicit vector (const allocator_type& alloc = allocator_type())			// default constructor
							: _begin(NULL), _size(0), _capacity(0), _alloc(alloc) {};

			explicit vector (size_type n, const const_reference val = value_type(),		// fill constructor
							const allocator_type& alloc = allocator_type())
			{
				if (n < 0)
					throw std::length_error ("vector");
				_begin = _alloc.allocate(n);
				_size = n;
				_capacity = n;
				for (size_type i = 0; i < n; ++i)
					_begin[i] = val;
			};

			template <class InputIt>
					vector (InputIt first, InputIt last,								// range constructor
							const allocator_type& alloc = allocator_type());

			vector (const vector& x)													// copy constructor
					: _begin(0), _capacity(x._capacity), _size(x._size), _alloc(x.get_allocator())
			{
				_begin = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_begin[i] = x._begin[i];
			};

			virtual ~vector()
			{
				clear();
				_alloc.deallocate(_begin, _capacity);
			};

			vector& operator= (const vector& x)
			{

			};

			//ITERATORS
			iterator				begin()  {return (_begin);};
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			//CAPACITY
			size_type				size() const					{ return (_size); };
			size_type				capacity() const				{ return (_capacity); };
			size_type				max_size() const;
			void					resize (size_type n, value_type val = value_type());
			bool					empty() const;
			void					reserve (size_type n);

			//ELEMENT ACCESS
			reference				at (size_type n)											//With bounds checking
			{
				if (n >= _size)
					throw std::out_of_range ("vector");
				return (_begin[n]);
			};
			const_reference			at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range ("vector");
				return (_begin[n]);
			};
			reference				operator[] (size_type n)		{ return (_begin[n]); };	//No bounds checking
			const_reference			operator[] (size_type n) const	{ return (_begin[n]); };
			reference				front()							{ return (*_begin); };
			const_reference			front() const					{ return (*_begin); };
			reference				back()							{ return (*(_begin + _size - 1)); };
			const_reference			back() const					{ return (*(_begin + _size - 1)); };
			pointer					data()							{ return (_begin); };
			const_pointer			data() const					{ return (_begin); };

			//MODIFIERS
			template <class InputIterator>
			void					assign (InputIterator first, InputIterator last);
			void					assign (size_type n, const const_reference val);
			void					push_back (const const_reference val);
			void					pop_back();
			// iterator				insert (iterator position, const const_reference val) // vector 3097
			// {
			// 	iterator __r;
			// 	if (size() < capacity())
			// 	{
			// 		const_iterator __old_end = end();
			// 		++__size_;
			// 		_VSTD::copy_backward(__position, __old_end, end());
			// 		__r = __const_iterator_cast(__position);
			// 	}
			// 	else
			// 	{
			// 		vector __v(__alloc());
			// 		__v.reserve(__recommend(__size_ + 1));
			// 		__v.__size_ = __size_ + 1;
			// 		__r = _VSTD::copy(cbegin(), __position, __v.begin());
			// 		_VSTD::copy_backward(__position, cend(), __v.end());
			// 		swap(__v);
			// 	}
			// 	*__r = val;
			// 	return __r;
			// };
			// void					insert (iterator position, size_type n, const const_reference val) // vector 3121
			// {
			// 	iterator __r;
			// 	size_type __c = capacity();
			// 	if (__n <= __c && size() <= __c - __n)
			// 	{
			// 	    const_iterator __old_end = end();
			// 	    __size_ += __n;
			// 	    _VSTD::copy_backward(__position, __old_end, end());
			// 	    __r = __const_iterator_cast(__position);
			// 	}
			// 	else
			// 	{
			// 	    vector __v(__alloc());
			// 	    __v.reserve(__recommend(__size_ + __n));
			// 	    __v.__size_ = __size_ + __n;
			// 	    __r = _VSTD::copy(cbegin(), __position, __v.begin());
			// 	    _VSTD::copy_backward(__position, cend(), __v.end());
			// 	    swap(__v);
			// 	}
			// 	_VSTD::fill_n(__r, __n, __x);
			// 	return __r;
			// };
			// template <class InputIterator>
			// void					insert (iterator position, InputIterator first, InputIterator last) // vector 3153
			// {
			// 	difference_type __off = __position - _begin();
			// 	iterator __p = __const_iterator_cast(__position);
			// 	iterator __old_end = end();
			// 	for (; size() != capacity() && __first != __last; ++__first)
			// 	{
			// 		++this->__size_;
			// 		back() = *__first;
			// 	}
			// 	vector __v(__alloc());
			// 	if (__first != __last)
			// 	{
			// #ifndef _LIBCPP_NO_EXCEPTIONS
			// 		try
			// 		{
			// #endif  // _LIBCPP_NO_EXCEPTIONS
			// 			__v.assign(__first, __last);
			// 			difference_type __old_size = static_cast<difference_type>(__old_end - begin());
			// 			difference_type __old_p = __p - begin();
			// 			reserve(__recommend(size() + __v.size()));
			// 			__p = begin() + __old_p;
			// 			__old_end = begin() + __old_size;
			// #ifndef _LIBCPP_NO_EXCEPTIONS
			// 		}
			// 		catch (...)
			// 		{
			// 			erase(__old_end, end());
			// 			throw;
			// 		}
			// #endif  // _LIBCPP_NO_EXCEPTIONS
			// 	}
			// 	__p = _VSTD::rotate(__p, __old_end, end());
			// 	insert(__p, __v.begin(), __v.end());
			// 	return begin() + __off;
			// };
			iterator				erase (iterator position);
			iterator				erase (iterator first, iterator last);
			void					swap (vector& x);

			void					clear()
			{
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_begin + i);
				_size = 0;
			};

			allocator_type			get_allocator() const			 { return(_alloc); };

	};

	//NON-MEMBER FUNCTIONS
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}
