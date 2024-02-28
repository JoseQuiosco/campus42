/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:00:08 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/26 12:20:01 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime> 

Base*	generator()
{
    int n = std::rand() % 3;

    if (n == 0)
        return (new A());
    if (n == 1)
        return (new B());
    return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Is a pointer to A class" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Is a pointer to B class" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Is a pointer to C class" << std::endl;
    else
        std::cout << "This pointer doesn't fit in any derivated Base class pointer" << std::endl;
}

void	identify(Base& p)
{
	try
    {
        A& xAx = dynamic_cast<A&>(p);
        std::cout << "Is a reference to A class" << std::endl;
        (void)xAx;
		return ;
    }
    catch( std::exception& ex) 
    {
        std::cout << "This reference not fit in class A" << std::endl;
    }
    try
    {
        B& xBx = dynamic_cast<B&>(p);
        std::cout << "Is a reference to B class" << std::endl;
        (void)xBx;
		return ;
    }
    catch( std::exception& ex)
    {
        std::cout << "This reference not fit in class B" << std::endl;
    }
    try
    {
        C& xCx = dynamic_cast<C&>(p);
        std::cout << "Is a reference to C class" << std::endl;
        (void)xCx;
		return ;
    }
    catch( std::exception& ex)
    {
        std::cout << "This reference not fit in class C" << std::endl;
    }
	std::cout << "This reference doesn't fit in any derivated Base class" << std::endl;
}

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL) + 13));
	
    Base* a = NULL;
	Base* x = generator();
	Base* y = generator();

    identify(a);
	identify(*a);
    identify(x);
    identify(*y);
	delete x;
	delete y;

	return (0);
}
