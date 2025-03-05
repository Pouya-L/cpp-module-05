/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:53:14 by plashkar          #+#    #+#             */
/*   Updated: 2025/03/05 16:15:43 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("unknown form"), _signedStatus(false), _gradeReqToSign(150), _gradeReqToExec(150)
{
	std::cout << "Form: " << _name << "  default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeReqToSign, int gradeReqToExec): _name(name), _signedStatus(false), _gradeReqToSign(gradeReqToSign), _gradeReqToExec(gradeReqToExec)
{
	if (gradeReqToExec < 1 || gradeReqToSign < 1)
		throw GradeTooHighException();
	if (gradeReqToExec > 150 || gradeReqToSign > 150)
		throw GradeTooLowException();
	std::cout << "Form: parametherized constructor for " << _name << " called" << std::endl;
	std::cout << "Form: gradeReqToSign: " << _gradeReqToSign << " gradeReqToExec: " << _gradeReqToExec << std::endl;
}

Form::Form(const Form& otherForm): _name(otherForm._name), _signedStatus(otherForm._signedStatus), _gradeReqToSign(otherForm._gradeReqToSign), _gradeReqToExec(otherForm._gradeReqToExec)
{
	std::cout << "Form: copy constructor for "<< _name << " called" << std::endl;
	std::cout << "Form: gradeReqToSign: " << _gradeReqToSign << " gradeReqToExec: " << _gradeReqToExec << std::endl;
}

Form& Form::operator=(const Form& otherForm)
{
	if (this != &otherForm) {
		// _name, _gradeReqToSign and _gradeReqToExec are const, so we cannot assign them
		_signedStatus = otherForm._signedStatus;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form: destructor for " << _name << " called" << std::endl;
}

const std::string& Form::getName( void ) const
{
	return (_name);
}

bool Form::getSignedStatus( void ) const
{
	return (_signedStatus);
}

int Form::getGradeReqToSign( void ) const
{
	return (_gradeReqToSign);
}

int Form::getGradeReqToExec( void ) const
{
	return (_gradeReqToExec);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signedStatus)
		throw Form::AlreadySignedException();
	if (bureaucrat.getGrade() > _gradeReqToSign)
		throw Form::GradeTooLowException();
	_signedStatus = true;
	std::cout << bureaucrat << " signed form " << _name << std::endl;
}

char const* Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low");
}

const char* Form::AlreadySignedException::what( void ) const throw()
{
	return ("Form is already signed.");
}

std::ostream& operator<<(std::ostream &os, const Form& form)
{
	os << form.getName() << " form, signed status: " << form.getSignedStatus()
		<< ", Grade required to sign: " << form.getGradeReqToSign()
		<< ", Grade required to execute: " << form.getGradeReqToExec();
	return os;
}


