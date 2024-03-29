/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:10:40 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/27 18:57:32 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span( unsigned int N ) : N(N)
{
}

Span::Span( const Span &s ) : N(s.N)
{
}

const Span &Span::operator=( const Span &s )
{
	if (this != &s)
	{
		this->N = s.N;
		this->list = s.list;
	}
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber( int number )
{
	if (this->list.size() + 1 > N)
		throw ExceptionAddNumber();
	this->list.push_back(number);
}

void	Span::addNumbers( std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->list.size() + (size_t)(end - begin) > N)
		throw ExceptionAddNumber();
	this->list.insert(this->list.end(), begin, end);
}

int		Span::shortestSpan() const
{
	if (this->list.size() <= 1)
        throw ExceptionFindRangeInSpan();
    std::vector<int> sort_list = this->list;
    std::sort(sort_list.begin(), sort_list.end());
    int span = abs(sort_list[1] - sort_list[0]);

    for (unsigned i = 0; (i + 1) != this->list.size(); i++)
    {
        if (abs(this->list[i + 1] - this->list[i]) < span)
            span = abs(this->list[i + 1] - this->list[i]);
    }
    return (span);
}

int		Span::longestSpan() const
{
	if (this->list.size() <= 1)
        throw ExceptionFindRangeInSpan();
    std::vector<int> sort_list = this->list;
    std::sort(sort_list.begin(), sort_list.end());
    return (abs(sort_list[this->list.size() - 1] - sort_list[0]));
}

void	Span::printSpanList() const
{
    std::cout << std::endl;
    for (size_t i = 0; i < this->list.size(); i++)
    {
        std::cout << this->list[i] << " ";
    }
    std::cout << std::endl;
}
