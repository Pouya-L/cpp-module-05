/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:11:47 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/15 19:45:21 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern Plato("Plato");

	/* Create the 3 existing forms */
	{
		AForm* shrubbery;
		AForm* robotomy;
		AForm* pardon;


	shrubbery = Plato.makeForm("shrubbery creation", "home");
	robotomy = Plato.makeForm("robotomy request", "bender");
	pardon = Plato.makeForm("presidential pardon", "the brazilian twins");

	std::cout 	<< "\n --- The created forms are as follows: ---\n"
				<< "\n-----------------\n"
				<< *shrubbery << "\n-----------------\n"
				<< *robotomy << "\n-----------------\n"
				<< *pardon << "\n-----------------\n"
				<< "\n -----------------------------------------\n"
				<< std::endl;

	delete shrubbery;
	delete robotomy;
	delete pardon;
	}
	
	/* Tries to create a non existant form*/
	{
		AForm* non_existant;
		std::cout 	<< "\n --- trying to create a non existant form ---" << std::endl;
		try
		{
			non_existant = Plato.makeForm("God", "Target");
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		(void)non_existant;
	}

	/* Tries to create a form without a target*/
	{
		AForm* no_target;
		std::cout 	<< "\n --- trying to create a form with an empty target ---" << std::endl;
		try
		{
			no_target = Plato.makeForm("robotomy request", "");
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		(void)no_target;
	}


	return (0);
}
