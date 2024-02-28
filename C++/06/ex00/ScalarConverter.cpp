/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:19:07 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/25 17:44:02 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter( const ScalarConverter &n ){(void)n;}

ScalarConverter::~ScalarConverter(){}


const ScalarConverter &ScalarConverter::operator=( const ScalarConverter &n )
{
    
	(void)n;
	return *this;
}    


static void printChar( const std::string &s )
{
	char	c = s[0];

	if (static_cast<int>(c) < 32 || static_cast<int>(c) > 126)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << c  << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void printInt( const std::string &s )
{
	int x = atoi(s.c_str());
    if (x < 32 || x > 126)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(x) << "'" << std::endl;
    
    long long i = atol(s.c_str());
    if (i > INT_MAX || i < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << x << std::endl;
        
    if (i > std::numeric_limits<float>::max() || i < std::numeric_limits<float>::min())
        std::cout << "float : Impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
        
    if (i > std::numeric_limits<double>::max() || i < std::numeric_limits<double>::min())
        std::cout << "double : Impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(x) << ".0" << std::endl;
}

static void printFloat( const std::string &s )
{
	float x = atof(s.c_str());
    if (x < 32 || x > 126)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(x) << "'" << std::endl;
    
    long long f = atol(s.c_str());
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(x) << std::endl;
        
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "float : Impossible" << std::endl;
    else
	{
        std::cout << "float: " << x;
		if (x - static_cast<int>(x) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
    
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "double : Impossible" << std::endl;
    else
    {
        std::cout << "double: " << static_cast<double>(x);
        if (x - static_cast<int>(x) == 0)
			std::cout << ".0";
        std::cout << std::endl;
    }
}

static void printDouble( const std::string &s )
{
	double x = atof(s.c_str());
    if (x < 32 || x > 126)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(x) << "'" << std::endl;
    
    long long d = atol(s.c_str());
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(x) << std::endl;
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "float : Impossible" << std::endl;
    else
	{
        std::cout << "float: " << x;
		if (x - static_cast<int>(x) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "double : Impossible" << std::endl;
    else
	{
        std::cout << "double: " << x;
		if (x - static_cast<int>(x) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
}


static void	printInfNeg()
{
	std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : -inff" << std::endl;
    std::cout << "double : -inf" << std::endl;
}

static void	printInfPlus()
{
	std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : +inff" << std::endl;
    std::cout << "double : +inf" << std::endl;
}

static void	printNan()
{
	std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : nanf" << std::endl;
    std::cout << "double : nan" << std::endl;
}


static void printSpecial( const std::string &s )
{
	std::string specialValues[] = { "-inff", "-inf", "+inff", "+inf", "nanf", "nan" };
    void (*printSpecial[])(void)= { &printInfNeg, &printInfNeg, &printInfPlus, &printInfPlus, &printNan, &printNan };

    for (int i = 0; i < 6; i++)
    {
        if (s == specialValues[i])
        {
            printSpecial[i]();
            return ;
        }
    }
    std::cout << "CONVERSION FAILED" << std::endl;
}

static bool	typeChar( const std::string &s )
{
	if (s.length() != 1)
		return false;
	if (s[0] >= '0' && s[0] <= '9')
		return false;
	return true;
}

static bool typeInt( const std::string &s )
{
	if (s.length() == 1 && (s[0] < '0' || s[0] > '9'))
		return false;
	if (s[0] != '-' && (s[0] < '0' || s[0] > '9'))
		return false;
	for (unsigned i = 1; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

static bool typeFloat( const std::string &s )
{
	if (s.length() == 1 && (s[0] < '0' || s[0] > '9'))
		return false;
	if (s[0] != '-' && (s[0] < '0' || s[0] > '9'))
		return false;
	size_t index;
	if ((index = s.find(".")) == std::string::npos)
		return false;
	if (s.substr(s.find(".") + 1, std::string::npos).length() <= 1)
		return false;
	for (unsigned i = 1; i < index; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	for (unsigned i = index + 1; i < s.length() - 1; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	if (s[s.length() - 1] != 'f')
		return false;
	return true;
}

static bool typeDouble( const std::string &s )
{
	if (s.length() == 1 && (s[0] < '0' || s[0] > '9'))
		return false;
	if (s[0] != '-' && (s[0] < '0' || s[0] > '9'))
		return false;
	size_t index;
	if ((index = s.find(".")) == std::string::npos)
		return false;
	if (s.substr(s.find(".") + 1, std::string::npos).length() == 0)
		return false;
	for (unsigned i = 1; i < index; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	for (unsigned i = index + 1; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

void	ScalarConverter::convert( std::string s )
{
    bool (*isOneType[])( const std::string &s ) = { &typeChar, &typeInt, &typeFloat, &typeDouble };
    void (*printType[])( const std::string &s ) = { &printChar, &printInt, &printFloat, &printDouble };

    for (unsigned i = 0; i < 4; i++)
    {
        if (isOneType[i](s))
        {
			printType[i](s);
			return ;
		}
    }
	printSpecial(s);
}
