/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:01:46 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/11 09:05:35 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

const char* AForm::FormNotSignedDuringExec::what() const throw(){
    return "Form was not signed during the execution attempt";
}

const char* AForm::GradeTooLowToExec::what() const throw(){
    return "Bureaucrat's grade was too low to execute the form";
}

AForm::AForm(std::string given_name, int given_req_grade_to_sign,
    int given_req_grade_to_exec)
    : name_(given_name), req_grade_to_sign_(given_req_grade_to_sign),
    req_grade_to_exec_(given_req_grade_to_exec), is_signed_(false){
        if(req_grade_to_sign_ > 150 || req_grade_to_exec_ > 150)
            throw AForm::GradeTooLowException();
        else if(req_grade_to_sign_ < 1 || req_grade_to_exec_ < 1)
            throw AForm::GradeTooHighException();
        return;
}

AForm::AForm(const AForm &other) : name_(other.name_),
    req_grade_to_sign_(other.req_grade_to_sign_),
    req_grade_to_exec_(other.req_grade_to_exec_),
    is_signed_ (other.is_signed_){
        if(req_grade_to_sign_ > 150 || req_grade_to_exec_ > 150)
            throw AForm::GradeTooLowException();
        else if(req_grade_to_sign_ < 1 || req_grade_to_exec_ < 1)
            throw AForm::GradeTooHighException();
        return;
}

AForm &AForm::operator=(const AForm &other){
    if(this != &other)
        this->is_signed_ = other.is_signed_;
    return(*this);
}

AForm::~AForm(){
    return;
}

std::string AForm::getName()const{
    return(name_);
}

bool AForm::getIsSigned()const{
    return(is_signed_);
}

int AForm::getReqGradeToSign()const{
    return(req_grade_to_sign_);
}

int AForm::getReqGradeToExec()const{
    return(req_grade_to_exec_);
}

void AForm::beSigned(const Bureaucrat &other){
    if(other.getGrade() <= req_grade_to_sign_){
        is_signed_ = true;
    }
    else{
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor)const{
    if(!this->is_signed_){
        throw(FormNotSignedDuringExec());
    }
    else if (this->req_grade_to_exec_ < executor.getGrade())
        throw(GradeTooLowToExec());
    this->formAction();
    return;
}

std::ostream &operator<<(std::ostream &out, const AForm &form){
    out<<form.getName()<<", form is signed? "
                       <<form.getIsSigned()
                       <<" required grade to sign "
                       <<form.getReqGradeToSign()
                       <<"required grade to exec "
                       << form.getReqGradeToExec();
    return(out);
}
