/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:54:37 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/04 12:29:47 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

Bureaucrat::Bureaucrat(std::string given_name, int given_grade): name(given_name){
    grade = given_grade;
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    return;
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

int Bureaucrat::getGrade()const{
    return(grade);
}

void Bureaucrat::increment(){
    grade--;
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    return;
}

void Bureaucrat::decrement(){
    grade++;
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    return;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
    out << bureaucrat.getName()<<", bureaucrat grade "<< bureaucrat.getGrade();
    return out;
}