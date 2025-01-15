/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:48:01 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/11 20:45:36 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_H
#define PRESIDENTIALPARDONFORM_CLASS_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
protected:
	void	beExecuted( void ) const;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& otherForm);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& otherForm);
	virtual ~PresidentialPardonForm();

	std::string	getTarget( void ) const;
};

#endif
