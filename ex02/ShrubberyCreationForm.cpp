/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:02:19 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/11 21:04:35 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Robotomy Request Form", 145, 137), _target("Unknown Target")
{
	std::cout << "ShrubberyCreationForm: default constructor called | Target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Robotomy Request Form", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm: default constructor called | Target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& otherForm)
	: AForm(otherForm), _target(otherForm.getTarget())
{
	std::cout << "ShrubberyCreationForm: copy constructor for foRm with target "<< _target << " called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& otherForm)
{
	if (this != &otherForm)
		_target = otherForm.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::beExecuted( void ) const
{
	
}



