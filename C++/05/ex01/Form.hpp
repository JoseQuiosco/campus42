/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:50:38 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/21 19:00:53 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef	__FORM_HPP__
#define __FORM_HPP__

class Form
{
	private:
		std::string	const		name;
		bool					sign;
		const unsigned int		grade_to_sign;
		const unsigned int		grade_to_exec;
		
		
	public:
		
		// class GradeTooLowException : public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw()
		// 		{
		// 			return (message.c_str());
		// 		}
		// 		GradeTooLowException(const std::string& message) : std::exception() {
		// 			this->message = message;
		// 		}
		// 		~GradeTooLowException() throw() {}
			
		// 	private:
		// 		std::string message;
				
		// };

		// class GradeTooHighException : public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw()
		// 		{
		// 			return (message.c_str());
		// 		}
		// 		GradeTooHighException(const std::string& message) : std::exception() {
		// 			this->message = message;
		// 		}
		// 		~GradeTooHighException() throw() {}
				
		// 	private:
		// 		std::string message;
				
		// };
						Form();
						Form(unsigned int grade_to_sign, unsigned int grade_to_exec);
						Form(Form &b);
						Form(std::string name);
						Form(std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec);
						~Form();
						
		std::string		getName(void) const;
		bool			getSign(void) const;
		unsigned int	getGrade_to_sign(void) const;
		unsigned int	getGrade_to_exec(void) const;
		void			upGrade(void);
		void			downGrade(void);
		Form			&operator=(const Form &b);
		
};

std::ostream 			&operator<<(std::ostream &out, const Form &f);

#endif