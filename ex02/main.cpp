/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:11:47 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/15 17:52:55 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	/* Create the 3 forms and some Bureaucrats */

	std::cout << "--- Create the 3 forms and some Bureaucrat ---\n\n";

	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("Morty");
	PresidentialPardonForm pardon("Rick Sanchez");
	Bureaucrat mike("Mike", 150);
	Bureaucrat jon("Jon", 120);
	Bureaucrat steve("Steve", 3);

	std::cout << "\n --------------------- \n\n";

	/* Try to execute forms without being signed */
	{
		std::cout << "--- Try to execute forms without being signed ---\n\n";
		try
		{
			std::cout << mike << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			mike.executeForm(shrubbery);
			mike.executeForm(robotomy);
			mike.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Sign form and try to execute without enough grade */
	{
		std::cout << "--- Sign form and try to execute without enough grade ---\n\n";
		try
		{
			std::cout << mike << std::endl;
			std::cout << jon << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			shrubbery.beSigned(jon);
			mike.executeForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Sign forms and execute them */
	{
		std::cout << "--- Sign forms and execute them ---\n\n";
		try
		{
			robotomy.beSigned(steve);
			pardon.beSigned(steve);
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;

			std::cout << "\n --------------------- \n\n";
			steve.executeForm(shrubbery);
			std::cout << "\n --------------------- \n\n";
			steve.executeForm(robotomy);
			std::cout << "\n --------------------- \n\n";
			steve.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";


	return (0);
}
