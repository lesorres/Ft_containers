#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> > 
	class stack
	{
		public:
			typedef				Container							container_type;
			typedef typename	container_type::value_type			value_type;
			typedef typename	container_type::size_type			size_type;
			typedef typename	container_type::reference			reference;
			typedef typename	container_type::const_reference		const_reference;

			explicit stack(const Container& cont = container_type()) : c(cont) {} // про explicit -> https://ravesli.com/urok-143-konstruktory-preobrazovaniya-klyuchevye-slova-explicit-i-delete/
			virtual ~stack() {}; //При работе с наследованием ваши деструкторы всегда должны быть виртуальными https://ravesli.com/urok-165-virtualnye-destruktory-i-prisvaivanie/

			stack& operator=( const stack& other )
			{
				if (this == &other)
					return(*this);
				c = other.c;
				return(*this);
			}
			//Element access
			reference top() { return(c.back()); };
			const_reference top() const { return(c.back()); };

			//Capacity
			bool empty() const { return(c.empty()); };
			size_type size() const { return(c.size()); };

			//Modifiers
			void push(const value_type& value) { c.push_back(value); };
			void pop() { c.pop_back(); };

			//My Utils
			bool Eq (const stack<T,container_type>& rhs) const { return(c == rhs.c); };
			bool Cm (const stack<T,container_type>& rhs) const { return(c < rhs.c); };

		protected:
			container_type c;
	};

	template< class T, class Container >
	bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return (lhs.Eq(rhs)); };

	template< class T, class Container >
	bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return (!(lhs == rhs)); };

	template< class T, class Container >
	bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return (lhs.Cm(rhs)); };

	template< class T, class Container >
	bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return !(rhs < lhs); };

	template< class T, class Container >
	bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return (rhs < lhs); };

	template< class T, class Container >
	bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return (!(lhs < rhs)); };
};

#endif
