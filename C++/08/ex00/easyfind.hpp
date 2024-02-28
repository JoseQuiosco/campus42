/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:46:34 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/26 22:54:24 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <exception>

class except: public std::exception
{
    public:
        const char *what() const throw() { return "Value doesn't found in the container"; }
};

template <typename T>
typename T::iterator	easyfind( T &container, int val )
{
    typename T::iterator	valfound;

    valfound = std::find(container.begin(), container.end(), val);
    if (valfound == container.end())
    	throw except();
    return valfound;
}

#endif
