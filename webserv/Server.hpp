/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:56:13 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/31 19:12:51 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Location.hpp"
#include <vector>

#ifndef __SERVER__
#define __SERVER__

class Server
{
	private:
		int			port;
		std::string error;
		std::string	server_name;
		std::vector<Location> location;	
	public:

};
#endif
