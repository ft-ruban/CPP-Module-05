/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:01:46 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/12 09:48:27 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw(){
    return "Form: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Form: Grade too low";
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

const std::string& Form::getName()const{
    return(name_);
}

const bool& Form::getIsSigned()const{
    return(is_signed_);
}

const int& Form::getReqGradeToSign()const{
    return(req_grade_to_sign_);
}

const int& Form::getReqGradeToExec()const{
    return(req_grade_to_exec_);
}

void Form::beSigned(const Bureaucrat &other){
    if(other.getGrade() <= req_grade_to_sign_){
        is_signed_ = true;
    }
    else{
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const Form &form){
    out<<form.getName()<<", form is signed? "<<form.getIsSigned()<<
    " required grade to sign "<<form.getReqGradeToSign()<<" required grade to exec "<< form.getReqGradeToExec();
    return(out);
}