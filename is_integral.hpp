/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:40:09 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/05/02 16:40:11 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include <type_traits>

namespace ft
{
	template< class T > struct remove_const					{ typedef T type; };
	template< class T > struct remove_const<const T>		{ typedef T type; };

	struct true_type
	{
		static const bool value = true;
	};

	struct false_type
	{
		static const bool value = false;
	};

	template <typename> struct is_integral_base : public false_type {};

	template<> struct is_integral_base<bool>: public true_type {};
	template<> struct is_integral_base<char>: public true_type {};
	template<> struct is_integral_base<signed char>: public true_type {};
	template<> struct is_integral_base<unsigned char>: public true_type {};
	template<> struct is_integral_base<wchar_t>: public true_type {};
	template<> struct is_integral_base<char16_t>: public true_type {};
	template<> struct is_integral_base<char32_t>: public true_type {};
	template<> struct is_integral_base<short>: public true_type {};
	template<> struct is_integral_base<unsigned short>: public true_type {};
	template<> struct is_integral_base<int>: public true_type {};
	template<> struct is_integral_base<unsigned int>: public true_type {};
	template<> struct is_integral_base<long>: public true_type {};
	template<> struct is_integral_base<unsigned long>: public true_type {};
	template<> struct is_integral_base<long long>: public true_type {};
	template<> struct is_integral_base<unsigned long long>: public true_type {};
	template<> struct is_integral_base<__int128_t>: public true_type {};
	template<> struct is_integral_base<__uint128_t>: public true_type {};


	template < class T >
		struct is_integral : public is_integral_base<typename remove_const<T>::type> {};
}
#endif