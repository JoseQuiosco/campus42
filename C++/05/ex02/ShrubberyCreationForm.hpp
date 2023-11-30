/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:18:27 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/30 20:49:09 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {

	private:
		std::string				target;
								ShrubberyCreationForm();
	
	public:
								ShrubberyCreationForm(std::string const &target);
								ShrubberyCreationForm(const ShrubberyCreationForm& f);
								~ShrubberyCreationForm();

		void					execute(Bureaucrat const &executor) const;
		std::string	const		&getTarget(void) const;
		ShrubberyCreationForm 	&operator=(const ShrubberyCreationForm &f);

};

#endif