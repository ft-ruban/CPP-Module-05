/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 07:25:25 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/09 08:36:24 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) 
: AForm("ShrubberyCreationForm", 145, 137), target_(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm  &other) 
: AForm(other), target_(other.target_){      
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if(this != &other){
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}