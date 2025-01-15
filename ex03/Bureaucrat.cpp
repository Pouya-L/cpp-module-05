/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:19 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/15 17:43:48 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unknown Bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat: constructor called for " << _name << " with a grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat: " << _name << " constructor called with a grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& otherBureaucrat): _name(otherBureaucrat._name), _grade(otherBureaucrat._grade)
{
	std::cout << "Bureaucrat: copy constructor for "<< _name << " called with a grade of " << _grade << std::endl;
	*this = otherBureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& otherBureaucrat) {
	if (this != &otherBureaucrat) {
		// _name is const, so we cannot assign it
		_grade = otherBureaucrat._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: destructor called for " << _name << " with a grade of " << _grade << std::endl;
}

const std::string& Bureaucrat::getName(void) const
{
	return (_name);
}

int			Bureaucrat::getGrade( void ) const
{
	return (_grade);
}

void Bureaucrat::gradeUp( void )
{
	if (this->_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;

}

void Bureaucrat::gradeDown( void )
{
	if (this->_grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

void	Bureaucrat::signForm(AForm &Aform)
{
	try
	{
		Aform.beSigned(*this);
		std::cout << this->_name << " signed " << Aform.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << Aform.getName() << " because: " << e.what() << std::endl;
	}
}

bool	Bureaucrat::executeForm(AForm const & form)
{
	if (form.execute(*this))
	{
		std::cout << *this << " executed " << form.getName() << std::endl;
		return (true);
	}
	return (false);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ",";
	return os;
}







