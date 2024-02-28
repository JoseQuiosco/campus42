/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:16:41 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/25 16:46:04 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter &n );
        
		const ScalarConverter &operator=( const ScalarConverter &n );
	
    public:
		~ScalarConverter();
		
        static void	convert( std::string s );
};

#endif