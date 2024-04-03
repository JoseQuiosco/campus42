/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:41:43 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/29 20:43:34 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::list<int>		lst;
		unsigned			N;

	public:
		PmergeMe();
		PmergeMe( char **argv );
        PmergeMe( const PmergeMe &p );
        const PmergeMe &operator=( const PmergeMe &p );
        ~PmergeMe();

        int get_N();
        void print_data();
        void vector_algorithm();
        void list_algorithm();
};

#endif