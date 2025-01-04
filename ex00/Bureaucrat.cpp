/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:19 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/04 15:55:38 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unknown Bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat: " << _name << " constructor called with a grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat: " << _name << " constructor called with a grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& otherBureaucrat): _name(otherBureaucrat.getName() + "_copy"), _grade(otherBureaucrat.getGrade())
{
	std::cout << "Bureaucrat: "<< _name << " copy constructor called with a grade of " << _grade << std::endl;
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
	std::cout << "Bureaucrat: " << _name << " destructor called with a grade of " << _grade << std::endl;
}

std::string	Bureaucrat::getName( void ) const
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

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}








