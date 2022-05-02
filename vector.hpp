/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:01:22 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/04/30 22:57:52 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "Iterators.hpp"
#include "Utils.hpp"
#include "Enable_if.hpp"
#include "Is_integral.hpp"

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
			typedef					Allocator							allocator_type;
			/* Тип значения аллокатора определяет тип того объекта, под хранения которого выделяется память.
			Если данным типом является T, то вызов функции-члена allocate(n) позволяет сформировать запрос на
			выделение пространства в машинной памяти для хранения n объектов типа T
			https://ru.wikipedia.org/wiki/Аллокатор */
			typedef typename		allocator_type::size_type			size_type;

			typedef					T										value_type;
			typedef	typename		allocator_type::reference				reference;
			typedef const typename	allocator_type::const_reference			const_reference; // value_type&
			typedef typename		allocator_type::difference_type			difference_type; // std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
			typedef typename		allocator_type::pointer					pointer;
			typedef typename		allocator_type::const_pointer			const_pointer;
			typedef typename		ft::vectorIt<value_type>				iterator;
			typedef	typename		ft::vectorIt<const value_type>			const_iterator;
			typedef	typename		ft::reverse_vectorIt<iterator>			reverse_iterator;
			typedef	typename		ft::reverse_vectorIt<const_iterator>	const_reverse_iterator;

			// typedef vectorIt     <value_type, бла бла > iterotor;
			// typedef typename		ft::vector_iterator<value_type>			iterator;
			// typedef typename		ft::vector_iterator<const value_type>	const_iterator;
			// typedef typename		ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef typename		ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			pointer														_begin;
			size_type													_size;
			size_type													_capacity;
			allocator_type												_alloc;

			template <class It>
			difference_type distance(It first, It second) //!!! ПРОВЕРЯТЬ РАСПОЛОЖЕНИЕ first относительно last, в случае если first > last возвращать ноль, проверит как это отражается на функциях, которые вызывают dofference 
			{
				difference_type i = 0;
				while(first < second)
				{
					first++;
					i++;
				}
				return i;
			}

		public:
			/*
			MEMBER FUNCTIONS
			explicit vector (const allocator_type& alloc = allocator_type())				// default constructor
							: _begin(NULL), _end(NULL), _cap_end(NULL), _alloc(alloc);
			explicit vector (size_type n, const const_reference val = value_type(),		// fill constructor
							const allocator_type& alloc = allocator_type());
			template <class InputIt>														// range constructor
			vector (InputIt first, InputIt last,
							const allocator_type& alloc = allocator_type());
			vector (const vector& x);													// copy constructor
			virtual ~vector();															// destructor
			vector& operator= (const vector& x);											// copy assignment operator

			ITERATORS
			_DONE	iterator			begin();
			OK_DONE	const_iterator		begin() const;
			_DONE	iterator			end();
			_DONE	const_iterator		end() const;
					reverse_iterator		rbegin();
					const_reverse_iterator	rbegin() const;
					reverse_iterator		rend();
					const_reverse_iterator	rend() const;

			CAPACITY
			DONE	size_type			size() const;
			OK_DONE	size_type			max_size() const;
			DONE	void				resize (size_type n, value_type val = value_type());
			DONE	size_type			capacity() const;
			DONE	bool				empty() const;
			OK_DONE	void				reserve (size_type n);

			ELEMENT ACCESS
			DONE	reference			operator[] (size_type n);
			DONE	const_reference		operator[] (size_type n) const;
			DONE	reference			at (size_type n);
			DONE	const_reference		at (size_type n) const;
			DONE	reference			front();
			DONE	const_reference		front() const	
			DONE	reference			back();
			DONE	const_reference		back() const;
			OK_DONE pointer				data();
			OK_DONE pointer				data() const;

			MODIFIERS
					template <class InputIterator>
					void				assign (InputIterator first, InputIterator last);
			DONE 	void				assign (size_type n, const const_reference val);
			OK_DONE void				push_back (const const_reference val);
			_DONE 	void				pop_back();
					iterator			insert (iterator position, const const_reference val);
					void				insert (iterator position, size_type n, const const_reference val);
					template <class Iterator>
					void				insert (iterator position, InputIterator first, InputIterator last);
			DONE 	iterator			erase (iterator position);
					iterator			erase (iterator first, iterator last);
			DONE	void				swap (vector& x);
			OK_DONE	void				clear();
					allocator_type		get_allocator() const;
			*/

			//MEMBER FUNCTIONS
			explicit vector (const allocator_type& alloc = allocator_type())			// default constructor
							: _begin(NULL), _size(0), _capacity(0), _alloc(alloc) {};

			explicit vector (size_type n, const_reference val = value_type(),			// fill constructor
							const allocator_type& alloc = allocator_type())
			{
				if (n < 0)
					throw std::length_error ("vector");
				_alloc = alloc;
				_begin = _alloc.allocate(n);
				_size = n;
				_capacity = n;
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(_begin + i, val);
					// _begin[i] = val;
			};

			template <class InputIt>													// range constructor
			vector (InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type* = nullptr)
					: _size(0), _capacity(0), _alloc (alloc)
			{
				_begin = _alloc.allocate(_capacity);
				assign(first, last);
			};

			vector (const vector& x)													// copy constructor
					: _begin(0), _size(x._size), _capacity(x._capacity), _alloc(x.get_allocator())
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
				if(this == &x)
					return *this;
				clear();
				_alloc.deallocate(_begin, _capacity);
				_size = x._size;
				_capacity = x._capacity;
				_begin = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_begin + i, x._begin[i]);
					// _begin[i] = x._begin[i];
				return *this;
			};

			//ITERATORS
			iterator				begin()							{return iterator(_begin);};
			const_iterator			begin() const					{return const_iterator(_begin);};
			iterator				end()							{return iterator(_begin + _size);};
			const_iterator			end() const 					{return const_iterator(_begin + _size);};
			reverse_iterator		rbegin()						{return reverse_iterator(--this->end());};
			const_reverse_iterator	rbegin() const					{return const_reverse_iterator(--this->end());};
			reverse_iterator		rend()							{return reverse_iterator(this->begin());};
			const_reverse_iterator	rend() const					{return const_reverse_iterator(this->begin());};

			//CAPACITY
			size_type				size() const					{ return (_size); };
			size_type				capacity() const				{ return (_capacity); };
			size_type				max_size() const				{ return (_alloc.max_size()); };;
			bool					empty() const					{ return (_size == 0); };;
			void					resize (size_type count, value_type val = value_type())
			{
				if (count > _size)
				{
					if (count > _capacity * 2)
						reserve(count);
					else if (count > _capacity)
						reserve(_capacity * 2);
					while (_size != count)
						push_back(val);
				}
				else if (count < _size)
				{
					while (_size != count)
						pop_back();
				}
			};

			void					reserve (size_type new_cap)
			{
				// обработка std::length_error if new_cap > max_size() не нужна, она есть в аллокаторе
				if (new_cap > _capacity)
				{
					pointer	tmp;
					tmp = _alloc.allocate(new_cap);
					for (size_type i = 0; i < _size; ++i)
						// _alloc.construct(tmp + i, _begin[i]);
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
			void					assign (size_type n, const const_reference val)
			{
				if (n < 0)
					throw std::length_error("vector");
				clear();
				if (n > _capacity)
					reserve(n);
				while (_size != n)
					push_back(val);
			};

			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
									assign (InputIterator first, InputIterator last)
			{
				int diff = distance(first, last);
				if (diff < 0)
					throw std::length_error("vector");
				clear();
				reserve(diff);
				for (; first != last; ++first)
				{
					this->push_back(*first);
				}
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

			iterator				insert (iterator position, const_reference val)
			{
				size_type indx = distance(begin(), position); // If the new size() is greater than capacity(), all iterators and references are invalidated https://en.cppreference.com/w/cpp/container/vector/insert
				insert(position, 1, val);
				return (iterator(_begin + indx));
			};

			void					insert (iterator position, size_type n, const_reference val)
			{
				size_type new_size = _size + n;
				size_type indx = distance(begin(), position);

				if (n < 0)
					throw std::length_error("vector");
				else if (n > 0)
				{
					if (n >= _capacity)
						reserve(_capacity + n);
					else if (new_size > _capacity)
						reserve(_capacity * 2);
					for (size_type i = indx ; i < _size ; ++i) //перенос вправо блока, на место которого будет осуществлена вставка
						_begin[i + n] = _begin[i];
					// for (size_type i = _size - 1 ; i >= indx ; --i) //перенос вправо блока, на место которого будет осуществлена вставка
						// tmp_vector._begin[i + n] = tmp_vector._begin[i];
					for (size_type i = indx ; i < indx + n ; ++i) //вставка новых занчений
						_begin[i] = val;
					_size = new_size;
				}
			};

			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
									insert (iterator position, InputIterator first, InputIterator last)
			{
				if (first >= last)
					return;
				else
				{
					vector tmp_vector = *this;
					size_type n = distance(first, last);
					size_type new_size = _size + n;
					size_type indx = distance(begin(), position);

					if (n < 0)
						throw std::length_error("vector");
					else if (n > 0)
					{
						try
						{
							if (n >= _capacity)
								tmp_vector.reserve(_capacity + n);
							else if (new_size > _capacity)
								tmp_vector.reserve(_capacity * 2);
							for (size_type i = indx ; i < _size ; ++i) //перенос вправо блока, на место которого будет осуществлена вставка
								tmp_vector._begin[i + n] = tmp_vector._begin[i];
							// for (size_type i = _size - 1 ; i >= indx ; --i) //перенос вправо блока, на место которого будет осуществлена вставка
							// 	tmp_vector._begin[i + n] = tmp_vector._begin[i];
							for (size_type i = indx ; i < indx + n ; ++i) //вставка новых занчений
							{
								// _alloc.destroy()
								// _alloc.construct(_begin + i, *first);
								tmp_vector._begin[i] = *first;
								first++;
							}
						}
						catch(...) { throw std::exception(); }
						*this = tmp_vector;
						_size = new_size;
					}
				}
			};

			iterator				erase (iterator position)
			{
				_alloc.destroy(position.base());
				size_type i = static_cast<size_type>(distance(begin(), position));
				for (; i < _size; ++i)
					_begin[i] = _begin[i + 1];
				_size--;
				return position;
			};

			iterator				erase (iterator first, iterator last)
			{
				if (first == last)
					return (last);
				difference_type diff = distance(first, last);
				difference_type start = distance(begin(), first);
				iterator tmp = last;
				_size -= diff;
				for (size_t i = start; i < _size; ++i)
					_begin[i] = _begin[i + diff];
				return(iterator(_begin + start));
			};

			void					swap (vector& x)
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

namespace std
{
	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
	{
		x.swap(y);
	};
}

#endif