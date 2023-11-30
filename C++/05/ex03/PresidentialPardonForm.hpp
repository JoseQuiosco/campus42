/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:07:59 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/30 22:08:47 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
# define __PRESIDENTIAL_PARDON_FORM_HPP__

# include "AForm.hpp"


class PresidentialPardonForm : public AForm {

	private:
		std::string				target;
								PresidentialPardonForm();
	
	public:
								PresidentialPardonForm(std::string const &target);
								PresidentialPardonForm(const PresidentialPardonForm& f);
								~PresidentialPardonForm();

		void					execute(Bureaucrat const &executor) const;
		std::string	const		&getTarget(void) const;
		PresidentialPardonForm 	&operator=(const PresidentialPardonForm &f);

};

#endif