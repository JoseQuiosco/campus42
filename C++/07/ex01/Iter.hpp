/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:54:13 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/26 13:21:29 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, size_t length, void (*f)(T &a))
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void	show_content(T &c)
{
	 try
    {
        std::cout << "El contenido de c es: " << c << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "No se puede mostrar el contenido de c" << std::endl;
    }
}

#endif
