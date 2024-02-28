/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:40:10 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/25 18:48:06 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *data_prime = new(Data);
    Data *data_deserialized;
    uintptr_t data_serialized;

    std::cout << "DATA PRIME: " << std::endl;
    data_prime->nif = "11111111A";
    data_prime->bornDate = "01/01/1900";
    std::cout << "NIF: " <<  data_prime->nif << std::endl;
    std::cout << "Born Date: " <<  data_prime->bornDate << std::endl;

	std::cout << std::endl;

    std::cout << "prime data address: " << data_prime << std::endl;
    data_serialized = Serializer::serialize(data_prime);
    std::cout << "address serialized to uint: " << data_serialized << std::endl;
    data_deserialized = Serializer::deserialize(data_serialized);
    std::cout << "uint deserialized to data address: " << data_deserialized << std::endl;

	std::cout << std::endl;

    std::cout << "DATA DESERIALIZED: " << std::endl;
	std::cout << "NIF: " <<  data_deserialized->nif << std::endl;
    std::cout << "Born Date: " <<  data_deserialized->bornDate << std::endl;
	return 0;
}