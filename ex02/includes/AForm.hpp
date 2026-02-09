/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:05:10 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/09 07:18:11 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    public:
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        AForm(std::string given_name, int given_req_grade_to_sign, int given_req_grade_to_exec);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        virtual std::string getName()const = 0;
        virtual bool        getIsSigned()const;
        virtual int         getReqGradeToSign()const;
        virtual int         getReqGradeToExec()const;
    
        void beSigned(const Bureaucrat &other);

    private:
        const std::string name_;
        const int         req_grade_to_sign_;
        const int         req_grade_to_exec_;
        bool              is_signed_;

};
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif