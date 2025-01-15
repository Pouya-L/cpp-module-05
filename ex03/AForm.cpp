/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:53:14 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/15 18:06:33 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//-------------------- Orthodox Canonical Form required functions --------------------

AForm::AForm(): _name("unknown Aform"), _signedStatus(false), _gradeReqToSign(150), _gradeReqToExec(150)
{
	std::cout << "AForm: " << _name << "  default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeReqToSign, int gradeReqToExec): _name(name), _signedStatus(false), \
_gradeReqToSign(gradeReqToSign), _gradeReqToExec(gradeReqToExec)
{
	if (gradeReqToExec < 1 || gradeReqToSign < 1)
		throw GradeTooHighException();
	if (gradeReqToExec > 150 || gradeReqToSign > 150)
		throw GradeTooLowException();
	std::cout << "AForm: parametherized constructor for " << _name << " called" << std::endl;
}

AForm::AForm(const AForm& otherAForm): _name(otherAForm._name), _signedStatus(otherAForm._signedStatus), \
_gradeReqToSign(otherAForm._gradeReqToSign), _gradeReqToExec(otherAForm._gradeReqToExec)
{
	std::cout << "AForm: copy constructor for "<< _name << " called" << std::endl;
}

AForm& AForm::operator=(const AForm& otherAForm)
{
	if (this != &otherAForm) {
		// _name, _gradeReqToSign and _gradeReqToExec are const, so we cannot assign them
		_signedStatus = otherAForm._signedStatus;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm: destructor for " << _name << " called" << std::endl;
}


//-------------------- Private attribute accessors --------------------

const std::string& AForm::getName( void ) const
{
	return (_name);
}

bool AForm::getSignedStatus( void ) const
{
	return (_signedStatus);
}

int AForm::getGradeReqToSign( void ) const
{
	return (_gradeReqToSign);
}

int AForm::getGradeReqToExec( void ) const
{
	return (_gradeReqToExec);
}

//-------------------- Public methods --------------------
void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signedStatus)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > _gradeReqToSign)
		throw AForm::GradeTooLowException();
	_signedStatus = true;
	std::cout << bureaucrat << " signed form " << _name << std::endl;
}

bool	AForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if (!this->_signedStatus)
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > _gradeReqToSign)
			throw AForm::GradeTooLowException();
		this->beExecuted();
	}
	catch (const AForm::AFormExceptions& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return false;
	}
	return true;
}

//-------------------- Exceptions --------------------
char const* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low");
}

const char* AForm::AlreadySignedException::what( void ) const throw()
{
	return ("Form is already signed");
}

const char* AForm::FormNotSignedException::what( void ) const throw()
{
	return ("Form not signed");
}

const char* AForm::ExecutorTooLowException::what( void ) const throw()
{
	return ("Executor's grade is too low");
}

//-------------------- Stream Operator Overload --------------------
std::ostream& operator<<(std::ostream &os, const AForm& Aform)
{
	os << Aform.getName() << " Aform, signed status: " << Aform.getSignedStatus()
		<< ", Grade required to sign: " << Aform.getGradeReqToSign()
		<< ", Grade required to execute: " << Aform.getGradeReqToExec();
	return os;
}


