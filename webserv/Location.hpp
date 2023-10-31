/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:04:19 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/31 19:13:12 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>

#ifndef LOCATION_HPP
#define LOCATION_HPP

typedef enum {GET, POST, DELETE} Tmethods;

class Location
{
	private:
		std::vector<Tmethods>	methods;
		std::string				root;
		std::string				index;
		int						max_body;
		
	public:

};
#endif