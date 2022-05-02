/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:40:17 by kmeeseek          #+#    #+#             */
/*   Updated: 2022/05/02 16:40:19 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft
{
	template<bool B, class T = void>
	struct enable_if 
	{

	};
	
	template<class T>
	struct enable_if<true, T> 
	{ 
		typedef T type; 
	};
}

#endif