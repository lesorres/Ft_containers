/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:14:08 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/05/01 17:39:11 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "Iterators.hpp"
#include "Utils.hpp"
#include "Enable_if.hpp"
#include "Is_integral.hpp"
#include "Tree.hpp"

namespace ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> class map
	{
	public:
		typedef Key															key_type;
		typedef T															mapped_type;
		typedef ft::pair<const key_type, mapped_type>						value_type;
		typedef Compare														key_compare;
		typedef Allocator													allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef ft::mapIt<Node<value_type>*, value_type>					iterator;
		typedef ft::mapIt<const Node<value_type>*, value_type>				const_iterator;
		typedef ft::reverse_mapIt<iterator>									reverse_iterator;
		typedef ft::reverse_mapIt<const_iterator>							const_reverse_iterator;
		typedef std::ptrdiff_t												difference_type;
		typedef typename allocator_type::size_type							size_type;
		typedef typename allocator_type::template rebind<Node<value_type> >::other	node_allocator;
		typedef typename allocator_type::template rebind<Tree<value_type> >::other	tree_allocator;

		class value_compare												//https://www.cplusplus.com/reference/map/map/value_comp/
		: public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			protected:
				key_compare comp;
				value_compare(key_compare c) : comp(c) {}
			public:
				bool operator()(const value_type& x, const value_type& y) const
					{ return (comp(x.first, y.first)); }
		};

	private:
		Tree<value_type > * _tree;
		Compare		 		_cmp;
		allocator_type 		_alloc;
		tree_allocator		_tree_allocator;
		node_allocator		_node_allocator;

	public:

		//MEMBER FUNCTIONS

		explicit map (const key_compare& comp = key_compare(),			//empty
					const allocator_type& alloc = allocator_type())
					: _cmp(comp), _alloc(alloc)
		{
			init_construct();
		}

		template <class InputIterator>									//range
		map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _cmp(comp), _alloc(alloc)
		{
			init_construct();
			for (; first != last; ++first)
				insert(ft::make_pair(first->first, first->second));
		}

		map(const map &x) : _cmp(x._cmp), _alloc(x._alloc)			//copy
		{
			_tree = _tree_allocator.allocate(sizeof(Tree<value_type>));
			_tree_allocator.construct(_tree, *(x._tree));
			fill_with_node(x._tree->root);
		}

		virtual ~map()
		{
			make_map_empty();
		}

		map& 					operator=(const map& x)
		{
			if (this == &x)
				return *this;
			make_map_empty();
			_tree = _tree_allocator.allocate(sizeof(Tree<value_type>));
			_cmp = x._cmp;
			_alloc = x._alloc;
			_tree_allocator.construct(_tree, *x._tree);
			fill_with_node(x._tree->root);
			return *this;
		}

		//ITERATORS

		iterator 				begin()				{return (_tree->first_node());}
		const_iterator 			begin() const		{return (_tree->first_node());}
		iterator 				end()				{return (_tree->next_to_last_node());}
		const_iterator 			end() const			{return (_tree->next_to_last_node());}
		reverse_iterator 		rbegin()			{return (reverse_iterator(iterator(_tree->last_node())));}
		const_reverse_iterator 	rbegin() const		{return (const_reverse_iterator(const_iterator(_tree->last_node())));}
		reverse_iterator 		rend()				{return (reverse_iterator(iterator(_tree->next_to_last_node())));}
		const_reverse_iterator 	rend() const		{return (const_reverse_iterator(const_iterator(_tree->next_to_last_node())));}

		//CAPACITY

		bool 					empty() const		{return (size() == 0);}
		size_type				size() const 		{return (_tree->size);}
		size_type				max_size() const 	{return (std::min((size_type) std::numeric_limits<difference_type>::max(),
													std::numeric_limits<size_type>::max() / (sizeof(Node<value_type>) + sizeof(T*))));}

		//ELEMENT ACCESS

		mapped_type& operator[](const key_type& k)
		{
			return (insert(ft::make_pair(k, mapped_type())).first->second);
		}

		mapped_type& at(const key_type& k)
		{
			iterator tmp = find(k);
			if (tmp == end())
				throw std::out_of_range("key not found");
			else
				return (tmp->second);
		}

		const mapped_type&	at(const Key& key) const
		{
			return (static_cast<const mapped_type>(at(key)));
		}

		//MODIFIERS

		pair<iterator, bool> insert(const value_type& val)
		{
			return (node_insert(_tree->root, val));
		}

		iterator insert (iterator position, const value_type& val)
		{
			if (position == end())
				return (node_insert(_tree->root, val).first);
			else if (position->first != val.first)
			{
				if (position->first > val.first)
				{
					iterator prev = position;
					while (val.first <= prev->first && --prev != end())
						position--;
				}
				else
				{
					iterator next = position;
					while (val.first >= next->first && ++next != end())
						position++;
				}
			}
			return (node_insert(position.base(), val).first);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
				insert(ft::make_pair(first->first, (first++)->second));
		}

		void erase(iterator position)
		{
			_tree->delete_node(position.base());
		}

		size_type erase(const key_type& k)
		{
			return (_tree->delete_node(find(k).base()));
		}

		void erase(iterator first, iterator last)
		{
			iterator tmp = first;
			while (tmp != last)
				_tree->delete_node((tmp++).base());
		}

		void swap(map& x)
		{
			std::swap(_tree, x._tree);
		}

		void clear()
		{
			make_map_empty ();
			init_construct ();
		}

		//OBSERVERS

		key_compare key_comp() const
		{
			return (_cmp);
		}

		value_compare value_comp() const
		{
			return (value_compare(key_comp()));
		}

		//OPERATIONS

		iterator find(const key_type& k)
		{
			Node<value_type> *curnt = _tree->root;
			while (!curnt->NIL)
			{
				if (k == curnt->pair->first)
					return (curnt);
				else if (_cmp(k, curnt->pair->first))
					curnt = curnt->left;
				else
					curnt = curnt->right;
			}
			return (end());
		}

		const_iterator find(const key_type& k) const
		{
			Node<value_type> *curnt = _tree->root;
			while (!curnt->NIL)
			{
				if (k == curnt->pair->first)
					return (curnt);
				else if (_cmp(k, curnt->pair->first))
					curnt = curnt->left;
				else
					curnt = curnt->right;
			}
			return (end());
		}

		size_type count(const key_type& k) const
		{
			if (find(k) == end())
				return (0);
			else
				return (1);
		}

		iterator lower_bound(const key_type& k)
		{
			Node<value_type> *curnt = _tree->root;
			while (!curnt->NIL)
			{
				if (k == curnt->pair->first)
					return (iterator(curnt));
				else if (_cmp(k, curnt->pair->first) && !curnt->left->NIL)
						curnt = curnt->left;
				else if (_cmp(k, curnt->pair->first))
						return (iterator(curnt));
				else if (!curnt->right->NIL)
						curnt = curnt->right;
				else
						return (++iterator(curnt));
			}
			return (end());
		}

		const_iterator lower_bound(const key_type& k) const
		{
			Node<value_type> *curnt = _tree->root;
			while (!curnt->NIL)
			{
				if (k == curnt->pair->first)
					return (const_iterator(curnt));
				else if (_cmp(k, curnt->pair->first) && !curnt->left->NIL)
						curnt = curnt->left;
				else if (_cmp(k, curnt->pair->first))
						return (const_iterator(curnt));
				else if (!curnt->right->NIL)
						curnt = curnt->right;
				else
						return (++const_iterator(curnt));
			}
			return (end());
		}

		iterator upper_bound(const key_type& k)
		{
			iterator tmp = lower_bound(k);
			if (tmp == end() || _cmp(k, tmp->first))
				return (tmp);
			else
				return (++tmp);
		}

		const_iterator upper_bound(const key_type& k) const
		{
			iterator tmp = lower_bound(k);
			if (tmp == end() || _cmp(k, tmp->first))
				return (tmp);
			else
				return (++tmp);
		}

		pair<const_iterator,const_iterator> equal_range( const key_type& k ) const
		{
			return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
		}

		pair<iterator,iterator> equal_range( const key_type& k )
		{
			return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}

		allocator_type 	get_allocator() const
		{
			return (_alloc);
		}

	private:
		void init_construct ()
		{
			_tree = _tree_allocator.allocate(sizeof(Tree<value_type>));
			_tree_allocator.construct(_tree);
		}

		void make_tree_empty(Node<value_type> *node)
		{
			if (node->NIL)
				return;
			if (!node->left->NIL)
				make_tree_empty(node->left);
			if  (!node->right->NIL)
				make_tree_empty(node->right);
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, sizeof(Node<value_type>));
		}

		void make_map_empty()
		{
			make_tree_empty(_tree->root);
			_tree_allocator.destroy(_tree);
			_tree_allocator.deallocate(_tree, sizeof(Tree<value_type>));
		}

		void fill_with_node(Node<value_type> *node)
		{
			if (!node->left->NIL)
				fill_with_node(node->left);
			if (!node->NIL)
				this->insert(*node->pair);
			if (!node->right->NIL)
				fill_with_node(node->right);
		}

		ft::pair<iterator, bool> node_insert(Node<value_type> *position, const value_type& val) // Кормен - Алгоритмы, стр. 327
		{
			Node<value_type> *parent;
			Node<value_type> *x;

			parent = 0;
			while (!position->NIL)
			{
				if (val.first == position->pair->first)
					return (ft::make_pair(position, 0));
				parent = position;
				if (_cmp(val.first, position->pair->first))
					position = position->left;
				else
					position = position->right;
			}
			x = _node_allocator.allocate(sizeof(Node<value_type>));
			_node_allocator.construct(x, val);
			x->parent = parent;
			x->left = &_tree->nil;
			x->right = &_tree->nil;
			x->is_black = 0;
			if (parent && _cmp(val.first, parent->pair->first))
				parent->left = x;
			else if (parent)
				parent->right = x;
			else 
				_tree->root = x;
			_tree->insert_fixup(x);
			if (x == _tree->last_node())
				_tree->nil.parent = x;
			if (x == _tree->first_node())
				_tree->nil.begin = x;
			_tree->size++;
			return (ft::make_pair(x, true));
		}
	};
	
	//NON-MEMBER FUNCTIONS
	template < class Key, class T, class Compare , class Allocator > 
	bool operator== (const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template < class Key, class T, class Compare , class Allocator > 
	bool operator!= (const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return !(lhs == rhs);
	};

	template < class Key, class T, class Compare , class Allocator > 
	bool operator< (const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template < class Key, class T, class Compare , class Allocator > 
	bool operator> (const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return rhs < lhs;
	};

	template < class Key, class T, class Compare , class Allocator > 
	bool operator>= (const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return !(lhs < rhs);
	};

	template < class Key, class T, class Compare , class Allocator > 
	bool operator<= (const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return !(rhs < lhs);
	};
}

#endif