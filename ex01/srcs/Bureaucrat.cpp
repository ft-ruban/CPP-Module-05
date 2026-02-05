/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:54:37 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/05 15:59:07 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//TODO RM "x Bureaucrat called"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

Bureaucrat::Bureaucrat(std::string given_name, int given_grade): name_(given_name){
    grade_ = given_grade;
    if(grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
    else if(grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
    return;
}
//TOCOMPLETE
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_){
    if(grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
    else if(grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
    return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    if(this != &other){
        this->grade_ = other.grade_;
    }
    return(*this);
}

Bureaucrat::~Bureaucrat(){
    return;
}

std::string Bureaucrat::getName()const{
    return(name_);
}

int Bureaucrat::getGrade()const{
    return(grade_);
}

void Bureaucrat::increment(){
    grade_--;
    if(grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
    return;
}

void Bureaucrat::decrement(){
    grade_++;
    if(grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
    return;
}

void Bureaucrat::signForm(Form &form){
    form.beSigned(*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
    out << bureaucrat.getName()<<", bureaucrat grade "<< bureaucrat.getGrade();
    return out;
}
