/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:54:37 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/29 15:59:51 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string given_name, std::size_t given_grade): name(given_name), grade(given_grade){
    return; //exception par rapport au grade?
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade){
    std::cout<<"copy constructor Bureaucrat called"<<std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout<<"copy assignement Bureaucrat called"<<std::endl;
    if(this != &other){
        this->grade = other.grade;
    }
    return(*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout<<"destructor of bureaucrat "<<name<<" called. (grade was : "<<grade<<")"<<std::endl;
    return;
}

std::string Bureaucrat::getName()const{
    return(name);
}

std::size_t Bureaucrat::getGrade()const{
    return(grade);
}