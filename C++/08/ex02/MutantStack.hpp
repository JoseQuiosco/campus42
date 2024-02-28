/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:51:48 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/27 20:24:50 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template< typename T, class Container = std::deque< T > > 
class MutantStack : public std::stack<T,Container>
{
	public:
		MutantStack( void ) {};
		MutantStack( const MutantStack& other ) { *this = other; }
		MutantStack&    operator=( const MutantStack& other ) {
			std::stack< T, Container >::operator=( other );
			return *this;
		}
		~MutantStack( void ) {};

		typedef typename Container::iterator    iterator;

		iterator    begin() { return this->c.begin(); }
		iterator    end() { return this->c.end(); }
};

#endif
