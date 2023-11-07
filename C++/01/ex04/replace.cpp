/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:50 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/07 20:44:31 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	write_in_replaced (std::ifstream &fd_in, std::ofstream &fd_out, std::string &s1, std::string &s2){
	std::string	line;
	size_t		pos;
	size_t		len_s1 = s1.length();

	std::getline(fd_in, line, '\0');
	while ((pos = line.find(s1)) != std::string::npos){
		line.erase(pos, len_s1);
		line.insert(pos, s2);
	}
	fd_out << line;
}

void	replace(std::string filename, std::string s1, std::string s2){
	std::string 	filename_replaced(filename);
	std::ifstream	fd_in(filename);
	std::ofstream	fd_out;

	if (s1.empty() || s2.empty() || (s1 == s2)){
		std::cout << "Asegurate de que s1 y s2 tengan contenido y no sean iguales..." << std::endl;
		return ;
	}
	filename_replaced.append(".replace");
	if (fd_in.is_open()){
		fd_out.open(filename_replaced);
		if (fd_out.is_open()){
			write_in_replaced(fd_in, fd_out, s1, s2);
			fd_in.close();
			fd_out.close();
		}
		else{
			fd_in.close();
			std::cout << filename_replaced << " can't be opened or created." << std::endl;
		}
	}
	else{
		std::cout << filename << " can't be opened." << std::endl;
	}
}
