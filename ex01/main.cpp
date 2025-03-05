/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:11:47 by plashkar          #+#    #+#             */
/*   Updated: 2025/03/05 16:21:16 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "--------------------- \n\n";
	/* Create a form with grade too high */
	{
		std::cout << "Create a form with grade too high\n" << std::endl;
		try
		{
			Form form0("A99", 0, 5);
			std::cout << form0 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

	}

	std::cout << "\n--------------------- \n\n";

	/* Create form and sign it without exceptions */
	{
		std::cout << "Create form and sign it without exceptions\n" << std::endl;
		try
		{
			Bureaucrat mike("Mike", 15);
			Form form("B58", 20, 45);
			std::cout << mike << std::endl;
			std::cout << form << std::endl;
			mike.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n--------------------- \n\n";

	/* Create form and try to sign it but the grade is not enough */
	{
		std::cout << "Create form and try to sign it but the grade is not enough\n" << std::endl;
		try
		{
			Bureaucrat jon("Jon", 35);
			Form form2("C_303", 20, 45);
			std::cout << jon << std::endl;
			std::cout << form2 << std::endl;
			jon.signForm(form2);
			std::cout << form2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
