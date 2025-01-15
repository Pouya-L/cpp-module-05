/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:37:57 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/15 19:26:58 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(): _name("Unknown Scribe")
{
	std::cout << "Intern: default constructor called" << std::endl;
}

Intern::Intern(const std::string name): _name(name)
{
	std::cout << "Intern: parametherized constructor for " << _name << " called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Intern: copy constructor called" << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern& src)
{
	if (this != &src) {
		_name = src._name;
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern: destructor for " << _name << " called" << std::endl;
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
	if (target.empty())
		throw Intern::TargetStringEmpty();

	const std::string formNames[] = FORM_NAMES;
	for (int i = 0; i < NUM_FORMS; i++)
	{
		if (formName == formNames[i])
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
				default:
					break;
			}
	}

	throw Intern::FormNameDoesNotExist();
}

char const* Intern::FormNameDoesNotExist::what( void ) const throw()
{
	return ("No Form with that name exists");
}

char const* Intern::TargetStringEmpty::what( void ) const throw()
{
	return("Target string is empty");
}
