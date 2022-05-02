/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:52:16 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/05/02 14:32:56 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

template <class value_type>
struct Node
{
	public:
		Node()
		{
			is_black = 1;
			begin = NULL;
			left = this;
			right = this;
			parent = 0,
			NIL = 1;
			pair = new value_type(); 
		}
	
		Node(const value_type& p)
		{
			is_black = 1;
			begin = NULL;
			left = this;
			right = this;
			parent = 0,
			NIL = 0;
			pair = new value_type(p); 
		}
	
		~Node()
		{
			delete pair;
		}
	
		bool is_black;
		struct Node *begin;
		struct Node *left;
		struct Node *right;
		struct Node *parent;
		bool NIL;
		value_type *pair;
};

template <class value_type>
class Tree
{
	public:
		Node<value_type> *root;
		Node<value_type> nil;
		size_t size;

		Tree() : size(0) {
			root = &nil;
			nil.left = &nil;
			nil.right = &nil;
			nil.begin = &nil;
			nil.parent = 0;
			nil.is_black = 1;
			nil.NIL = true;
		}

		Tree(Tree<value_type> &other) : size(0) {
			root = &nil;
			nil.left = &nil;
			nil.right = &nil;
			nil.begin = &nil;
			nil.parent = 0;
			nil.is_black = 1;
			nil.NIL = (&other == &other);
		}

		Tree& operator=(const Tree<value_type>& other)
		{
			if (this == &other)
				return (*this);
			root = other.root;
			nil = other.nil;
			size = other.size;
			return (*this);
		};

		void left_rotate(Node<value_type> *x)
		{
			Node<value_type> *y = x->right;
			x->right = y->left;
			if (!y->left->NIL)
				y->left->parent = x;
				y->parent = x->parent;
			if (!x->parent)
				root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
				x->parent = y;
		}

		void right_rotate(Node<value_type> *x) {
			Node<value_type> *y = x->left;
			x->left = y->right;
			if (!y->right->NIL)
				y->right->parent = x;
				y->parent = x->parent;
			if (!x->parent)
				root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
				x->parent = y;
		}

		void insert_fixup(Node<value_type> *z) // стр 349 - Кормен, Алгоритмы
		{
			while (z != root && z->parent->is_black == 0)
			{
				if (z->parent == z->parent->parent->left)
				{
					Node<value_type> *y = z->parent->parent->right;
					if (y->is_black == 0)
					{
						z->parent->is_black = 1;
						y->is_black = 1;
						z->parent->parent->is_black = 0;
						z = z->parent->parent;
					}
					else
					{
						if (z == z->parent->right)
						{
							z = z->parent;
							left_rotate(z);
						}
						z->parent->is_black = 1;
						z->parent->parent->is_black = 0;
						right_rotate(z->parent->parent);
					}
				}
				else
				{
					Node<value_type> *y = z->parent->parent->left;
					if (y->is_black == 0)
					{
						z->parent->is_black = 1;
						y->is_black = 1;
						z->parent->parent->is_black = 0;
						z = z->parent->parent;
					}
					else
					{
						if (z == z->parent->left)
						{
							z = z->parent;
							right_rotate(z);
						}
						z->parent->is_black = 1;
						z->parent->parent->is_black = 0;
						left_rotate(z->parent->parent);
					}
				}
			}
			root->is_black = 1;
		}

		void delete_fixup_for_left_child(Node<value_type> *x)
		{
			Node<value_type> *w = x->parent->right;
			if (w->is_black == 0)
			{
				w->is_black = 1;
				x->parent->is_black = 0;
				left_rotate (x->parent);
				w = x->parent->right;
			}
			if (w->left->is_black == 1 && w->right->is_black == 1)
			{
				w->is_black = 0;
				x = x->parent;
			} 
			else
			{
				if (w->right->is_black == 1)
				{
					w->left->is_black = 1;
					w->is_black = 0;
					right_rotate (w);
					w = x->parent->right;
				}
				w->is_black = x->parent->is_black;
				x->parent->is_black = 1;
				w->right->is_black = 1;
				left_rotate (x->parent);
				x = root;
			}
		}

		void delete_fixup_for_right_child(Node<value_type> *x)
		{
			Node<value_type> *w = x->parent->left;
			if (w->is_black == 0)
			{
				w->is_black = 1;
				x->parent->is_black = 0;
				right_rotate (x->parent);
				w = x->parent->left;
			}
			if (w->right->is_black == 1 && w->left->is_black == 1)
			{
				w->is_black = 0;
				x = x->parent;
			}
			else
			{
				if (w->left->is_black == 1)
				{
					w->right->is_black = 1;
					w->is_black = 0;
					left_rotate (w);
					w = x->parent->left;
				}
				w->is_black = x->parent->is_black;
				x->parent->is_black = 1;
				w->left->is_black = 1;
				right_rotate (x->parent);
				x = root;
			}
		}

		void delete_fixup(Node<value_type> *x)  // стр 359 - Кормен, Алгоритмы
		{
			while (x != root && x->is_black == 1)
			{
				if (x == x->parent->left)
					delete_fixup_for_left_child(x);
				else
					delete_fixup_for_right_child(x);
			}
			x->is_black = 1;
		}

		int delete_node(Node<value_type> *z) // стр 357 - Кормен, Алгоритмы
		{
			Node<value_type> *x, *y;
			/* 	y - узел следующий (по значению) за z, по сути встает на место z в дереве после удаления;
				x - узел, который перемещается в исходную позицию узла y в дереве. */

			if (!z || z->NIL) return (0);

			if (z->left->NIL || z->right->NIL)
				y = z;
			else
			{
				y = z->right;
				while (!y->left->NIL)
					y = y->left;
			}

			if (!y->left->NIL)
				x = y->left;
			else
				x = y->right;

			x->parent = y->parent;
			if (y->parent)
				if (y == y->parent->left)
					y->parent->left = x;
				else
					y->parent->right = x;
			else
				root = x;
			if (y != z) {
				delete z->pair;
				value_type *p = new value_type(*y->pair);
				z->pair = p;
			}

			if (y->is_black == 1)
				delete_fixup (x);
			size--;
			delete y;
			return (1);
		}

		Node<value_type>* first_node() 
		{
			Node<value_type>* tmp = root;
			while (!tmp->left->NIL)
				tmp = tmp->left;
			return (tmp);
		}

		Node<value_type>* last_node()
		{
			Node<value_type>* tmp = root;
			while (!tmp->right->NIL)
				tmp = tmp->right;
			return (tmp);
		}

		Node<value_type>* next_to_last_node()
		{
			Node<value_type>* tmp = root;
			while (!tmp->right->NIL)
				tmp = tmp->right;
			return (tmp->right);
		}
};

#endif