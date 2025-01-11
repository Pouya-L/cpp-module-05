/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:58:31 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/11 20:49:41 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", 25, 5), _target("Unknown Target")
{
	std::cout << "PresidentialPardonForm: default constructor called | Target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm: default constructor called | Target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& otherForm)
	: AForm(otherForm), _target(otherForm.getTarget())
{
	std::cout << "PresidentialPardonForm: copy constructor for form with target "<< _target << " called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& otherForm)
{
	if (this != &otherForm)
		_target = otherForm.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void	PresidentialPardonForm::beExecuted( void ) const
{
	std::cout << "PresidentialPardonForm: " << _target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}



