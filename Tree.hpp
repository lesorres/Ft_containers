/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:52:16 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/04/17 22:13:08 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#define NIL &nil

template <class value_type>
struct Node
{
	public:
	Node () : is_black(false), left(this), {};

	value_type *pair;
	struct Node *parent;
	struct Node *left;
	struct Node *right;

	bool is_black;
	// bool nil;
};

template <class value_type>
class Tree
{
	Node<value_type> *root;
	Node<value_type> nil;
	size_t size;

	Tree() 
	{
		root = NIL;
		size = 0;							//???
		
		nil->parent = NIL;
		nil->left = NIL;
		nil->right = NIL;
		nil->is_black = 1;
	}
	
	Tree(Tree<value_type> &other)
	{
		root = NIL;

		nil.left = NIL;
		nil.right = NIL;
		// nil.begin = NIL;
		nil.parent = 0;
		nil.color = 0;						//???
		// nil.nil = (&other == &other);
		
		size = 0;							//???
	}

	Tree& operator=(const Tree<value_type>& other)
	{
		if (this == &other)
			return *this;
		root = other.root;
		nil = other.nil;
		size = other.size;
		return *this;
	};

	void left_rotate(Node_<value_type> *x) // стр 346 - Кормен, Алгоритмы
	{
		Node<value_type> *y = x->right;
		x->right = y->left;
		if (!y->left != nil)
			y->left->parent = x;
		if (y != nil) // нужна ли эта проверка, и тогда зачем? можно ли убрать? - в книге ее нет
			y->parent = x->parent;
		if (x->parent == nil)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		if (!x->NIL) // нужна ли эта проверка, и тогда зачем? можно ли убрать? - в книге ее нет
			x->parent = y;
	}
	
	void right_rotate(Node_<value_type> *x) // стр 346 - Кормен, Алгоритмы
	{
		Node<value_type> *y = x->left;
		x->left = y->right;
		if (!y->right != nil)
			y->right->parent = x;
		if (y != nil) // нужна ли эта проверка, и тогда зачем? можно ли убрать? - в книге ее нет
			y->parent = x->parent;
		if (x->parent == nil)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		if (!x->NIL) // нужна ли эта проверка, и тогда зачем? можно ли убрать? - в книге ее нет
			x->parent = y;
	}

	void insert_fixup(Node_<value_type> *z)
	{ // стр 349 - Кормен, Алгоритмы
		while (z != root && z->parent->is_black == 0)			//зачем условие z != root ?
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


};

#endif