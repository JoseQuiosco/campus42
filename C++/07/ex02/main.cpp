/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:49 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/26 16:39:17 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// int main()
// {
//     try
//     {
// 		Array<int> data;
// 		Array<int> data_1(5);

// 		data_1[0] = 3;
// 		data_1[4] = 2;

// 		std::cout << "size: " << data_1.size() << std::endl;
// 		for (unsigned int i = 0; i < data_1.size(); i++)
// 		{
// 			std::cout << "array1 position " << i << ": " << data_1[i] << std::endl;
// 		}

// 		std::cout << std::endl;

// 		Array<int> data_2(data_1);
		
// 		std::cout << "size: " << data_2.size() << std::endl;
// 		for (unsigned int i = 0; i < data_2.size(); i++)
// 		{
// 			std::cout << "array2 position " << i << ": " << data_2[i] << std::endl;
// 		}

// 		std::cout << std::endl;

// 		data_2[1] = 42;
// 		data_2[2] = 42;
// 		data_2[3] = 42;
		
// 		Array<int> data_3;
// 		data_3 = data_2;

// 		std::cout << "size: " << data_3.size() << std::endl;
// 		for (unsigned int i = 0; i < data_3.size(); i++)
// 		{
// 			std::cout << "array3 position " << i << ": " << data_3[i] << std::endl;
// 		}

// 		std::cout << data[0] << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cout << e.what() << std::endl;
//     }
// }

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout << "Valores del array de enteros numbers: ";
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}