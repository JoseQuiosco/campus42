/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:16:55 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/28 15:37:53 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:05:32 by atalaver          #+#    #+#             */
/*   Updated: 2023/12/02 18:51:54 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> btc;
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &b );
		const BitcoinExchange &operator=( const BitcoinExchange &b );
		~BitcoinExchange();

		void	run( const std::string &fileName );
		void	printData();
	
	class ExceptionLoadData : public std::exception
	{
		public:
        	const char *what() const throw() { return "Format error loading data"; }
	};

	class ExceptionLoadFile : public std::exception
	{
		public:
        	const char *what() const throw() { return "Error load file input!"; }
	};
};

#endif
