/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:14:08 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/04/17 15:10:12 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "Iterators.hpp"
#include "Utils.hpp"
#include "Enable_if.hpp"
#include "Is_integral.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef pair<const key_type,mapped_type>		value_type;    // PAIR
			typedef Compare									key_compare;
			typedef 										value_compare;    // НУЖНО ЛИ?
			typedef Allocator 								allocator_type;
			typedef allocator_type::reference				reference;
			typedef allocator_type::const_reference			const_reference;
			typedef allocator_type::pointer					pointer;
			typedef allocator_type::const_pointer			const_pointer;
			typedef ft::mapIt<value_type>				iterator;    // НУЖНО РЕАЛИЗОВАТЬ
			typedef 										const_iterator;
			typedef 										reverse_iterator;
			typedef 										const_reverse_iterator;
			typedef 										difference_type;
			typedef 										size_typ;
			//MEMBER FUNCTIONS
			explicit map (const key_compare& comp = key_compare(),				//empty
							const allocator_type& alloc = allocator_type());
		
			template <class InputIterator>										//range
					map (InputIterator first, InputIterator last,
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type());
		
					map (const map& x);											//copy
		
			virtual ~vector();
		
			map &					operator= (const map& x);
		
			//ITERATORS
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
		
			//CAPACITY
			bool					empty() const;
			size_type				size() const;
			size_type				max_size() const;
			
			//ELEMENT ACCESS
			mapped_type& operator[] (const key_type& k);
			
			//MODIFIERS
			pair<iterator,bool> 	insert (const value_type& val);						//single element
			iterator				insert (iterator position, const value_type& val);
			template <class InputIterator>											//with hint
			void					insert (InputIterator first, InputIterator last);	//range
			void					erase (iterator position);
			size_type				erase (const key_type& k);
			void					erase (iterator first, iterator last);
			void					swap (map& x);
			void					clear();
			
			//OBSERVERS
			key_compare				key_comp() const;
			value_compare			value_comp() const;
		
			//OPERATIONS
			iterator				find (const key_type& k);
			const_iterator			find (const key_type& k) const;
			size_type				count (const key_type& k) const;
			iterator				lower_bound (const key_type& k);
			const_iterator			lower_bound (const key_type& k) const;
			iterator				upper_bound (const key_type& k);
			const_iterator			upper_bound (const key_type& k) const;
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>				equal_range (const key_type& k);
			allocator_type			get_allocator() const;
	};
}

#endif