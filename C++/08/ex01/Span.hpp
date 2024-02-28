/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:08:56 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/27 18:52:22 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

class Span
{
	private:
	
		std::vector<int>	list;
		unsigned int		N;

		
	public:
	
		Span();
		Span( unsigned int N );
		Span( const Span &s );
		const Span &operator=( const Span &s );
		~Span();

		void	addNumber( int number );
		void	addNumbers( std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	printSpanList() const;


		class ExceptionAddNumber : public std::exception
		{
			public:
       			const char *what() const throw() { return "Error adding number"; }
		};

		class ExceptionFindRangeInSpan : public std::exception
		{
			public:
       			const char *what() const throw() { return "Error finding range"; }
		};
};

#endif
