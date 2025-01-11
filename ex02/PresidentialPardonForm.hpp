/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:48:01 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/11 20:29:45 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#ifndef PRESIDENTIALPARDONFORM_CLASS_H
#define PRESIDENTIALPARDONFORM_CLASS_H

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
