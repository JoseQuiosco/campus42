/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:32 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/12/01 00:13:22 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Intern.hpp"

# define BOLD  "\033[1m"
# define BLACK "\033[30;1m"
# define RED   "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE  "\033[34;1m"
# define MAGENTA   "\033[35;1m"
# define CYAN  "\033[36;1m"
# define WHITE "\033[37;1m"
# define DEFAULT   "\033[0m"

void ft_leaks(void)
{
	system("leaks -q intern");
}

int main()
{
	atexit(ft_leaks);
	
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");

    delete rrf;
    return 0;
}