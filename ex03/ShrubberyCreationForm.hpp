/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:44:52 by plashkar          #+#    #+#             */
/*   Updated: 2025/01/15 18:00:10 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define TREE "    ccee88oo\n \
 C8O8O8Q8PoOb o8oo\n \
dOB69QO8PdUOpugoO9bD\n \
CgggbU8OU qOp qOdoUOdcb\n \
    6OuU  /p u gcoUodpP\n \
      \\\\//  /douUP\n \
        \\\\\\////\n \
         |||/\\\n \
         |||\\/\n \
         |||||\n \
   .....//||||\\...."

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
protected:
	void	beExecuted( void ) const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& otherForm);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& otherForm);
	virtual ~ShrubberyCreationForm();

	std::string	getTarget( void ) const;
};

#endif
