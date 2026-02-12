/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:50:25 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/11 09:08:45 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
:AForm("PresidentialPardonForm", 25, 5), target_(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), target_(other.target_){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    if (this != &other){
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::formAction()const {
    std::cout<<this->target_
             <<" has been pardoned by Zaphod Beeblebrox."
             <<std::endl;
}