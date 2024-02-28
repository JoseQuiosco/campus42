/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:13:04 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/27 18:56:13 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\nOTROS TEST\n" << std::endl;

	try
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(-9);
		v.push_back(3);
		v.push_back(-4);
		v.push_back(15);
		v.push_back(8);
		Span n1(3);
		n1.addNumbers(v.begin(), v.end());
		std::cout << n1.shortestSpan() << std::endl;
		std::cout << n1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::vector<int> w;
		for (int i = 0; i < 10000; i++)
		{
			w.push_back(rand());
		}
		Span n2(15000);
		n2.addNumbers(w.begin(), w.end());
		n2.printSpanList();
		std::cout << n2.shortestSpan() << std::endl;
		std::cout << n2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
