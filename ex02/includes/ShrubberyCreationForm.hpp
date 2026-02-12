/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 07:14:04 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/11 09:04:08 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    public:
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        virtual void formAction()const;
    private:
        std::string target_;
        
};

#endif