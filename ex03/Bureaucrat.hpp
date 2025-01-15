/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:26 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/15 17:17:36 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string _name;
	int			_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& otherBureaucrat);
	Bureaucrat& operator=(const Bureaucrat& otherBureaucrat);
	~Bureaucrat();

	const std::string&	getName( void ) const;
	int					getGrade( void ) const;

	void	gradeUp( void );
	void	gradeDown( void );
	void	signForm(AForm& form);
	bool	executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual char const* what( void ) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what( void ) const throw();
	};
};

//Overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
