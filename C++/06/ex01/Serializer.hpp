/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:28:35 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/25 18:38:55 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef unsigned long int uintptr_t;

typedef struct t_Data
{
	std::string	nif;
	std::string	bornDate;
} Data;


class Serializer
{
	private:
		Serializer();
		Serializer( const Serializer &s );
		const Serializer &operator=( const Serializer &s );
        
	public:
		~Serializer();
        
		static uintptr_t	serialize( Data *ptrData );
		static Data*		deserialize( uintptr_t addresRaw );
};

#endif