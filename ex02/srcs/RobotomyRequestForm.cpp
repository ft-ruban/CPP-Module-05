/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:43:57 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/10 08:50:10 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) 
: AForm("RobotomyRequestForm", 72, 45), target_(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), target_(other.target_){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if(this != &other){
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){

}