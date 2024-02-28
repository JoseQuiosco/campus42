/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:09:30 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/28 16:48:05 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// STATIC FUNCTIONS

static std::string	trim( const std::string &s, char c)
{
	size_t first;
	if ((first = s.find_first_not_of(c)) == std::string::npos)
		return s;

    size_t last;
	if ((last = s.find_last_not_of(c)) == std::string::npos)
		return s;

    return s.substr(first, (last - first + 1));
}

static bool	iter_string( const std::string& str, int (*isDigit)(int) )
{
    for (size_t i = 0; i < str.length(); i++)
	{
        if (!isDigit(str[i]))
            return false;
    }
    return true;
}

static bool validDate( const std::string &date )
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

	// Iteramos isdigit para todos los caracteres

    if ((!iter_string(year, &isdigit)) ||
        (!iter_string(month, &isdigit)) ||
        (!iter_string(day, &isdigit)))
        return false;

	// Convertimos a enteros

    int yearInt, monthInt, dayInt;

    std::stringstream ssYear(year);
    std::stringstream ssMonth(month);
    std::stringstream ssDay(day);

    ssYear >> yearInt;
    ssMonth >> monthInt;
    ssDay >> dayInt;

    if ((yearInt < 2009 || yearInt > 2022) ||
        (monthInt < 1 || monthInt > 12) ||
        (dayInt < 1 || dayInt > 31))
        return false;

    // Meses con 30 dias
    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return false;

    
    // Febrero
    if (monthInt == 2)
	{
        // Check bisiesto
        bool isLeap = ((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0);
        if (dayInt > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

static void	validateNumber( const std::string &number )
{
	double value;
    try
	{
        // Buscamos si hay mas de un '.'
		size_t index;
		if ((index = number.find('.')) != std::string::npos)
		{
			if (number.find('.', index + 1) != std::string::npos)
				throw std::invalid_argument("too many decimal points");
		}

        // Si empieza por + o - checkeamos a partir de ahí
        index = (number[0] == '+' || number[0] == '-')? 1 : 0;
        while (index < number.length())
		{
            if (isdigit(number[index]) || number[index] == '.')
            {
                index++;
                continue;
            }
            throw std::invalid_argument("not a number => " + number);
        }
		std::stringstream ss(number);
    	ss >> value;
    }
	catch (std::exception &e)
	{
        throw std::invalid_argument("not a number => " + number);
    }

    if (value < 0)
        throw std::invalid_argument("not a positive number");

    if (value > 1000.0)
        throw std::invalid_argument("too large a number");
}

double ft_stod( const std::string &number )
{
    std::stringstream ss(number);
    double value;
    ss >> value;
    return value;
}

static std::string	ft_to_string( int n )
{
	std::stringstream ss;
    ss << n;
    return ss.str();
}

static std::string	previousDate( const std::string &date ) {
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Bisiesti
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[2] = 29;
    }


    day--;
    if (day == 0)
	{
        month--;
        if (month == 0)
		{
            month = 12;
            year--;
        }
        day = daysInMonth[month];
    }

    std::string newYear = ft_to_string(year);
    std::string newMonth = (month < 10) ? "0" + ft_to_string(month) : ft_to_string(month);
    std::string newDay = (day < 10) ? "0" + ft_to_string(day) : ft_to_string(day);

    return newYear + "-" + newMonth + "-" + newDay;
}

static bool	date1HightoDate2( const std::string &date1, const std::string &date2 )
{
	int year1 = atoi(date1.substr(0, 4).c_str());
    int month1 = atoi(date1.substr(5, 2).c_str());
    int day1 = atoi(date1.substr(8, 2).c_str());
	int year2 = atoi(date2.substr(0, 4).c_str());
    int month2 = atoi(date2.substr(5, 2).c_str());
    int day2 = atoi(date2.substr(8, 2).c_str());

	if (year1 > year2)
        return true;
    else if (year1 == year2 && month1 > month2)
        return true;
    else if (year1 == year2 && month1 == month2 && day1 > day2)
        return true;
    else
	    return false;

}

// CLASS MEMBERS

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file("data.csv");
    std::string		line;

    std::getline(file, line);
    while (std::getline(file, line) && line.length() > 0)
    {
		size_t delim;
        if ((delim = line.find(',')) == std::string::npos)
			throw ExceptionLoadData();

		std::string date = trim(line.substr(0, delim), ' ');
        std::string value = trim(line.substr(delim + 1, line.length()), ' ');

        this->btc[date] = value;
    }
	
    file.close();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &b ) : btc(b.btc) {}

const BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &b )
{
	if (this != &b)
		btc = b.btc;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::run( const std::string &fileName )
{
	std::ifstream file(fileName.c_str());

	if (!file.good())
		throw ExceptionLoadFile();
	if (file.peek() == std::ifstream::traits_type::eof())
	{
        std::cout << "Error: file is empty" << std::endl;
        throw ExceptionLoadFile();
    }

	std::string	line;

	std::getline(file, line);
    if (line != "date | value") {
        std::cout << "Error: invalid file format" << std::endl;
        throw ExceptionLoadFile();
    }

	while (std::getline(file, line))
    {
        size_t separator;
        if ((separator = line.find('|')) == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, separator), ' ');
        std::string value = trim(line.substr(separator + 1), ' ');

        try
		{
            if (!validDate(date))
                throw std::invalid_argument("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));

            if(value.empty())
                throw std::invalid_argument("invalid value: " + (value.empty() ? "\"\"" : "'" + value + "'"));

            validateNumber(value);

            std::map<std::string, std::string>::iterator it;
            std::string prevDate = date;
            it = this->btc.find(date);

            while (it == this->btc.end() && date1HightoDate2(prevDate, "2009-01-02"))
			{
                const std::string &currentDate = prevDate;
                prevDate = previousDate(currentDate);
                it = this->btc.find(prevDate);
            }

			if (!date1HightoDate2(prevDate, "2009-01-02"))
				throw std::invalid_argument("invalid date: " + (prevDate.empty() ? "\"\"" : "'" + prevDate + "'"));

            std::cout << date << " => " << value  << " = " << ft_stod(it->second) * ft_stod(value) << std::endl;

        }
		catch (std::exception &e)
		{
            std::cout << "Error: " << e.what() << std::endl;
        }

    }

	file.close();
}

void	BitcoinExchange::printData()
{
	for (std::map<std::string,std::string>::iterator it = this->btc.begin(); it != this->btc.end(); it++)
	{
		std::cout << it->first << ":" << it->second << std::endl;
	}
}

