/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:18:40 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/15 19:05:12 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define FORM_NAMES {"shrubbery creation", "robotomy request", "presidential pardon"}
# define NUM_FORMS 3

class AForm;

class Intern {
	private:
		std::string _name;
	public:
		Intern();
		Intern(const std::string name);
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();

		AForm* makeForm(const std::string formName, const std::string target);

		class InternExceptions : public std::exception {};

		class FormNameDoesNotExist : public Intern::InternExceptions
		{
			public:
				virtual char const* what( void ) const throw();
		};

		class TargetStringEmpty : public InternExceptions
		{
			public:
				virtual char const* what( void ) const throw();
		};
};

#endif
