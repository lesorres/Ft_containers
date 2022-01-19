/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:01:22 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/01/19 22:25:56 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <iostream>

//for reference:
#include <iterator>

template< class T, class Allocator = std::allocator<T> >
class vector
{
	// allocator_traits wasn't used because it is implemented only in C++11
	public:
		typedef				Allocator							allocator_type; //
		typedef typename	allocator_type::size_type			size_type;

	protected:
		typedef					T										value_type;
		typedef	typename		allocator_type::reference				reference;
		typedef const typename	allocator_type::const_reference			const_reference; // value_type&
		typedef typename		allocator_type::difference_type			difference_type; // std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
		typedef typename		allocator_type::pointer					pointer;
		typedef typename		allocator_type::const_pointer			const_pointer;
		typedef					pointer									iterator;
		typedef					const_pointer							const_iterator;
		// typedef typename		ft::vector_iterator<value_type>			iterator;
		// typedef typename		ft::vector_iterator<const value_type>	const_iterator;
		// typedef typename		ft::reverse_iterator<iterator>			reverse_iterator;
		// typedef typename		ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		pointer														_begin;
		pointer														_end;
		// __compressed_pair<pointer, allocator_type>					__end_cap_;
		pointer														_cap_end;
		allocator_type												_alloc;

	public:
		//MEMBER FUNCTIONS
		// explicit vector (const allocator_type& alloc = allocator_type())
		// 		: _begin(NULL), _end(NULL), _cap_end(NULL), _alloc(alloc) {}; // default constructor
		// explicit vector (size_type n, const const_reference val = value_type(), // fill constructor
		// 				const allocator_type& alloc = allocator_type());
		// template <class InputIt>
		// 		vector (InputIt first, InputIt last, // range constructor
		// 				const allocator_type& alloc = allocator_type());
		// vector (const vector& x); // copy constructor
		// virtual ~vector();
		// vector& operator= (const vector& x);

		// //ITERATORS
		// iterator				begin()  {return (_begin);};
		// const_iterator			begin() const;
		// iterator				end();
		// const_iterator			end() const;
		// reverse_iterator		rbegin();
		// const_reverse_iterator	rbegin() const;
		// reverse_iterator		rend();
		// const_reverse_iterator	rend() const;

		// //CAPACITY
		// size_type				size() const;
		// size_type				max_size() const;
		// void					resize (size_type n, value_type val = value_type());
		// size_type				capacity() const;
		// bool					empty() const;
		// void					reserve (size_type n);

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
		// void					assign (InputIterator first, InputIterator last);
		// void					assign (size_type n, const const_reference val);
		// void					push_back (const const_reference val);
		// void					pop_back();
		// iterator				insert (iterator position, const const_reference val)
		// void					insert (iterator position, size_type n, const const_reference val)
		// template <class InputIterator>
		// void					insert (iterator position, InputIterator first, InputIterator last)
		// iterator				erase (iterator position);
		// iterator				erase (iterator first, iterator last);
		// void					swap (vector& x);
		// void					clear();
		// allocator_type			get_allocator() const;

		//MEMBER FUNCTIONS
		explicit vector (const allocator_type& alloc = allocator_type())
				: _begin(NULL), _end(NULL), _cap_end(NULL), _alloc(alloc) {}; // default constructor

		explicit vector (size_type n, const const_reference val = value_type(), // fill constructor
						const allocator_type& alloc = allocator_type())
		{
			try
			{
				_begin = _alloc.allocate(n);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		};
		template <class InputIt>
				vector (InputIt first, InputIt last, // range constructor
						const allocator_type& alloc = allocator_type());
		vector (const vector& x); // copy constructor
		virtual ~vector();
		vector& operator= (const vector& x);

		//ITERATORS
		iterator				begin()  {return (_begin);};
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		// reverse_iterator		rbegin();
		// const_reverse_iterator	rbegin() const;
		// reverse_iterator		rend();
		// const_reverse_iterator	rend() const;

		//CAPACITY
		size_type				size() const;
		size_type				max_size() const;
		void					resize (size_type n, value_type val = value_type());
		size_type				capacity() const;
		bool					empty() const;
		void					reserve (size_type n);

		//ELEMENT ACCESS
		reference				operator[] (size_type n);
		const_reference			operator[] (size_type n) const;
		reference				at (size_type n);
		const_reference			at (size_type n) const;
		reference				front();
		const_reference			front() const;
		reference				ack();
		const_reference			back() const;

		//MODIFIERS
		template <class InputIterator>
		void					assign (InputIterator first, InputIterator last);
		void					assign (size_type n, const const_reference val);
		void					push_back (const const_reference val);
		void					pop_back();
		iterator				insert (iterator position, const const_reference val)
		{
			
		};
		void					insert (iterator position, size_type n, const const_reference val)
		{

		};
		template <class InputIterator>
		void					insert (iterator position, InputIterator first, InputIterator last) // vector 3153
		{
			difference_type __off = __position - _begin();
			iterator __p = __const_iterator_cast(__position);
			iterator __old_end = end();
			for (; size() != capacity() && __first != __last; ++__first)
			{
				++this->__size_;
				back() = *__first;
			}
			vector __v(__alloc());
			if (__first != __last)
			{
		#ifndef _LIBCPP_NO_EXCEPTIONS
				try
				{
		#endif  // _LIBCPP_NO_EXCEPTIONS
					__v.assign(__first, __last);
					difference_type __old_size = static_cast<difference_type>(__old_end - begin());
					difference_type __old_p = __p - begin();
					reserve(__recommend(size() + __v.size()));
					__p = begin() + __old_p;
					__old_end = begin() + __old_size;
		#ifndef _LIBCPP_NO_EXCEPTIONS
				}
				catch (...)
				{
					erase(__old_end, end());
					throw;
				}
		#endif  // _LIBCPP_NO_EXCEPTIONS
			}
			__p = _VSTD::rotate(__p, __old_end, end());
			insert(__p, __v.begin(), __v.end());
			return begin() + __off;
		};
		iterator				erase (iterator position);
		iterator				erase (iterator first, iterator last);
		void					swap (vector& x);
		void					clear();
		allocator_type			get_allocator() const;

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
