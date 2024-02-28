/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:41:18 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/26 12:48:14 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>


template <typename T>
T	min( T first, T second )
{
    if (first < second)
        return (first);
    else
        return (second);
}

template <typename T>
T	max( T first, T second )
{
	if (first > second)
        return (first);
    else
        return (second);
}

template <typename T>
void	swap( T &first, T &second)
{
	T	saved = first;
	first = second;
	second = saved;
}

#endif
