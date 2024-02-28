/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:46:19 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/26 16:25:03 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>

template <typename T>

class Array
{
	private:
		T*				content;
		unsigned int	lenght;

	public:

        class OutOfBoundsException : public std::exception
        {
            public:
                const char *what() const throw() { return "Error index array"; };
        };

        
		Array() : content(new T()), lenght(0) {}
		Array( unsigned int n ) : content(new T[n]()), lenght(n) {}
		Array( const Array &a ) : content(new T[a.size()]()), lenght(a.size())
		{
			for (unsigned int i = 0; i < a.size(); i++)
			{
				this->content[i] = a.content[i];
			}
		}

		const Array &operator=( const Array &a )
		{
			if (this != &a)
			{
				delete[] this->content;
				this->lenght = a.size();
				this->content = new T[this->lenght]();
				for (unsigned int i = 0; i < a.size(); i++)
				{
					this->content[i] = a.content[i];
				}
			}
			return *this;
		}

		T	&operator[]( unsigned int index )
		{
			if (index >= this->lenght)
				throw OutOfBoundsException();
			return this->content[index];
		}

		~Array() { delete[] this->content; }

		unsigned int	size() const { return this->lenght; }
	
};

#endif
