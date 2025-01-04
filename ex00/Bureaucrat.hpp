/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:26 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/04 15:37:44 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string _name;
	int			_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& otherBureaucrat);
	Bureaucrat& operator=(const Bureaucrat& otherBureaucrat);
	~Bureaucrat();

	std::string	getName( void ) const;
	int			getGrade( void ) const;

	void	gradeUp( void );
	void	gradeDown( void );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual char const* what( void ) const throw() {
				return ("Grade is too high!");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {
				return ("Grade is too low!");
			}
	};
};

//Overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
