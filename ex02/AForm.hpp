/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:04:56 by plashkar          #+#    #+#             */
/*   Updated: 2025/03/05 16:42:08 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

class Bureaucrat;

/**
 * The pure virtual function beExecuted() in the AForm class is used to enforce
 * that any derived class must provide its own implementation of this function.
 * This design makes AForm an abstract class, meaning we cannot instantiate AForm directly;
 * we can only instantiate classes derived from AForm that implement the beExecuted() method.
 */
class AForm {
private:
	const std::string	_name;
	bool				_signedStatus;
	const int			_gradeReqToSign;
	const int			_gradeReqToExec;
protected:
	// Pure virtual function
	virtual void beExecuted( void ) const = 0;
public:
	AForm();
	AForm(std::string name, int gradeReqToSign, int gradeReqToExec);
	AForm(const AForm& otherAForm);
	AForm& operator=(const AForm& otherAForm);
	virtual	~AForm();

	const std::string&	getName( void ) const;
	bool				getSignedStatus( void ) const;
	int					getGradeReqToSign( void ) const;
	int					getGradeReqToExec( void ) const;

	void				beSigned(const Bureaucrat& bureaucrat);
	bool				execute(const Bureaucrat& executor) const;

	// Base class for all AForm exceptions
	class AFormExceptions : public std::exception {};

	class GradeTooHighException : public AForm::AFormExceptions
	{
		public:
			virtual char const* what( void ) const throw();
	};

	class GradeTooLowException : public AForm::AFormExceptions
	{
		public:
			virtual const char* what( void ) const throw();
	};

	class AlreadySignedException: public AForm::AFormExceptions
	{
		public:
			virtual const char *what( void ) const throw();
	};

	class FormNotSignedException: public AForm::AFormExceptions
	{
		public:
			virtual const char *what( void ) const throw();
	};

	class ExecutorTooLowException: public AForm::AFormExceptions
	{
		public:
			virtual const char *what( void ) const throw();
	};
};

//Overload the insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif
