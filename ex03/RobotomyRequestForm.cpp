/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:48:02 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/11 20:59:34 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45), _target("Unknown Target")
{
	std::cout << "RobotomyRequestForm: default constructor called | Target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm: default constructor called | Target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& otherForm)
	: AForm(otherForm), _target(otherForm.getTarget())
{
	std::cout << "RobotomyRequestForm: copy constructor for foRm with target "<< _target << " called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& otherForm)
{
	if (this != &otherForm)
		_target = otherForm.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void	RobotomyRequestForm::beExecuted( void ) const
{
	std::cout << "🤖 drilling noises 🤖" << std::endl;
	srand(std::time(0));
	if (rand() % 2 == 0)
		std::cout << "FATAL: Robotomy failed" << std::endl;
	else
		std::cout << _target << "has been robotomized" << std::endl;
}



