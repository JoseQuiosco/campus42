/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:38:54 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/28 20:40:00 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
#include <string>

typedef struct oper
{
	std::string	op;
	int (*func)(int, int);
} t_oper;

class RPN
{
	private:
		std::stack<int>	nums;
		t_oper _oper[4];
	public:
		RPN();
		RPN( const RPN &r );
		const RPN &operator=( const RPN &r );
		~RPN();

		void	run( const std::string &numbers );
};

#endif
