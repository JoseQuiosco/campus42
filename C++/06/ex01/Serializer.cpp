/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:28:39 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/25 18:39:26 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){

    
}

Serializer::Serializer( const Serializer &s ){
    
    (void)s;
}

const Serializer &Serializer::operator=( const Serializer &s ){

    (void)s;
	return *this;
}


Serializer::~Serializer(){

    
}

uintptr_t	Serializer::serialize( Data *ptrData ){

    return reinterpret_cast<uintptr_t>(ptrData);
}


Data*		Serializer::deserialize( uintptr_t addressRaw ){

    return reinterpret_cast<Data*>(addressRaw);
}

