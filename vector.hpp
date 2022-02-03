/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:01:22 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/02/03 23:31:39 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iterators.hpp"
#include "Utils.hpp"

#if 0
// for reference:
#include <vector>
#include <iterator>
#endif

namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
		// allocator_traits wasn't used because it is implemented only in C++11
		public:
			typedef					Allocator							allocator_type; //
			/* Тип значения аллокатора определяет тип того объекта, под хранения которого выделяется память.
			Если данным типом является T, то вызов функции-члена allocate(n) позволяет сформировать запрос на
			 выделение пространства в машинной памяти для хранения n объектов типа T
			https://ru.wikipedia.org/wiki/Аллокатор*/
			typedef typename		allocator_type::size_type			size_type;

			typedef					T										value_type;
			typedef	typename		allocator_type::reference				reference;
			typedef const typename	allocator_type::const_reference			const_reference; // value_type&
			typedef typename		allocator_type::difference_type			difference_type; // std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
			typedef typename		allocator_type::pointer					pointer;
			typedef typename		allocator_type::const_pointer			const_pointer;
			typedef					ft::vectorIt<value_type>				iterator;
			typedef	typename		ft::vectorIt<const value_type>			const_iterator;
			// typedef	typename		ft::reverse_vectorIt<iterator>			reverse_iterator;
			// typedef	typename		ft::reverse_vectorIt<const_iterator>	const_reverse_iterator;

			// typedef vectorIt<value_type, бла бла > iterotor;
			// typedef typename		ft::vector_iterator<value_type>			iterator;
			// typedef typename		ft::vector_iterator<const value_type>	const_iterator;
			// typedef typename		ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef typename		ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			pointer														_begin; //buffer
			size_type													_size;
			size_type													_capacity;
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
			// iterator					insert (iterator position, const const_reference val);
			// void						insert (iterator position, size_type n, const const_reference val);
			// template <class Iterator>
			// void						insert (iterator position, InputIterator first, InputIterator last);
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
							const allocator_type& alloc = allocator_type())
			{

			};

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
			iterator				begin()							{return iterator(_begin);};
			const_iterator			begin() const					{return const_iterator(_begin);};
			iterator				end()							{return iterator(_begin + _size);};
			const_iterator			end() const 					{return const_iterator(_begin + _size);};
			// reverse_iterator		rbegin()						{return reverse_iterator(_begin);};
			// const_reverse_iterator	rbegin() const					{return const_reverse_iterator(_begin);};
			// reverse_iterator		rend()							{return reverse_iterator(_begin + _size);};
			// const_reverse_iterator	rend() const					{return const_reverse_iterator(_begin + _size);};

			//CAPACITY
			size_type				size() const					{ return (_size); };
			size_type				capacity() const				{ return (_capacity); };
			size_type				max_size() const				{ return (_alloc.max_size()); };;
			bool					empty() const					{ return (_size == 0); };;
			void					resize (size_type new_size, value_type val = value_type())
			{
				if (new_size > _capacity)
				{
					reserve();
					
				}
				if (new_size > _size)
				{
					
				}
				else
				{

				}
			}
			void					reserve (size_type new_cap)
			{
				// обработка std::length_error if new_cap > max_size(). не нужна, она есть в аллокаторе
				if (new_cap > _capacity)
				{
					pointer	tmp;
					tmp = _alloc.allocate(new_cap);
					for (size_type i = 0; i < _size; ++i)
						tmp[i] = _begin[i];
					if (_begin)
						_alloc.deallocate(_begin, _capacity);
					_begin = tmp;
					_capacity = new_cap;
				}
			};

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
			void					assign (InputIterator first, InputIterator last)
			{

			};
			void					assign (size_type n, const const_reference val)
			{

			};
			void					push_back (const const_reference val)
			{
				if (_capacity == 0)
					reserve(1);
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				_alloc.construct(_begin + _size, val); // The new element is initialized as a copy of value https://en.cppreference.com/w/cpp/container/vector/push_back
				_size++;
			};
			void					pop_back()
			{
				if (_size)
					_alloc.destroy(_begin + _size - 1);
				_size--;
			};
			iterator					insert (iterator position, const_reference val) {};
			void						insert (iterator position, size_type n, const_reference val) {};
			template <class InputIterator>
			void						insert (iterator position, InputIterator first, InputIterator last) {};
			iterator					erase (iterator position)
			{
				_alloc.destroy(position);
				iterator tmp = position;
				for (;tmp != end(); ++tmp)
					*tmp = *(tmp + 1);
				_size++;
				return position;
			};
			iterator					erase (iterator first, iterator last);
			void						swap (vector& x)
			{
				if (this != &x)
				{
					std::swap (_begin, x._begin);
					std::swap (_size, x._size);
					std::swap (_capacity, x._capacity);
					std::swap (_alloc, x._alloc);
				}
			};

			void					clear()
			{
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_begin + i);
				_size = 0;
			};

			allocator_type			get_allocator() const			 { return(_alloc); };

	};

	//NON-MEMBER FUNCTIONS , vector 3358
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
			const typename vector<T, Alloc>::size_type sz = lhs.size();
			return sz == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			// return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); - почему так нельзя?
	};

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	};

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return rhs < lhs;
	};

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	};

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}
