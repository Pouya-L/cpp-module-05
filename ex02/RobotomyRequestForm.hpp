/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:44:52 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/11 20:45:43 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
protected:
	void	beExecuted( void ) const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& otherForm);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& otherForm);
	virtual ~RobotomyRequestForm();

	std::string	getTarget( void ) const;
};

#endif
