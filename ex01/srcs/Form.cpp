/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:01:46 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/05 15:02:32 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

Form::Form(std::string given_name, int given_req_grade_to_sign,
    int given_req_grade_to_exec)
    : name_(given_name), req_grade_to_sign_(given_req_grade_to_sign),
    req_grade_to_exec_(given_req_grade_to_exec), is_signed_(false){
        if(req_grade_to_sign_ > 150 || req_grade_to_exec_ > 150)
            throw Form::GradeTooLowException();
        else if(req_grade_to_sign_ < 1 || req_grade_to_exec_ < 1)
            throw Form::GradeTooHighException();
        return;
}

Form::Form(const Form &other) : name_(other.name_),
    req_grade_to_sign_(other.req_grade_to_sign_),
    req_grade_to_exec_(other.req_grade_to_exec_),
    is_signed_ (other.is_signed_){
        if(req_grade_to_sign_ > 150 || req_grade_to_exec_ > 150)
            throw Form::GradeTooLowException();
        else if(req_grade_to_sign_ < 1 || req_grade_to_exec_ < 1)
            throw Form::GradeTooHighException();
        return;
}

Form &Form::operator=(const Form &other){
    if(this != &other)
        this->is_signed_ = other.is_signed_;
    return(*this);
}

Form::~Form(){
    return;
}

std::string Form::getName()const{
    return(name_);
}

bool Form::getIsSigned()const{
    return(is_signed_);
}

int Form::getReqGradeToSign()const{
    return(req_grade_to_sign_);
}

int Form::getReqGradeToExec()const{
    return(req_grade_to_exec_);
}

void Form::beSigned(const Bureaucrat &bureaucrat){
    if(bureaucrat.getGrade() <= req_grade_to_sign_)
        is_signed_ = true;
    else
        throw Form::GradeTooLowException();
    return;
}