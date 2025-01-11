/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:04:56 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/11 18:13:32 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_signedStatus;
	const int			_gradeReqToSign;
	const int			_gradeReqToExec;
public:
	Form();
	Form(std::string name, int gradeReqToSign, int gradeReqToExec);
	Form(const Form& otherForm);
	Form& operator=(const Form& otherForm);
	~Form();

	const std::string&	getName( void ) const;
	bool				getSignedStatus( void ) const;
	int					getGradeReqToSign( void ) const;
	int					getGradeReqToExec( void ) const;

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual char const* what( void ) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what( void ) const throw();
	};

	class AlreadySignedException : public std::exception
	{
		public:
			virtual char const* what( void ) const throw();
	}
};

//Overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
