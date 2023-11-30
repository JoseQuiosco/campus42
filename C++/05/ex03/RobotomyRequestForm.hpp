/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:42:55 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/30 21:48:42 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {

	private:
		std::string				target;
								RobotomyRequestForm();
	
	public:
								RobotomyRequestForm(std::string const &target);
								RobotomyRequestForm(const RobotomyRequestForm& f);
								~RobotomyRequestForm();

		void					execute(Bureaucrat const &executor) const;
		std::string	const		&getTarget(void) const;
		RobotomyRequestForm 	&operator=(const RobotomyRequestForm &f);

};

#endif