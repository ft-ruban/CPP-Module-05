/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:05:10 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/10 15:09:57 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    public:
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        Form(std::string given_name, int given_req_grade_to_sign, int given_req_grade_to_exec);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        std::string getName()const;
        bool        getIsSigned()const;
        int         getReqGradeToSign()const;
        int         getReqGradeToExec()const;
    
        void beSigned(const Bureaucrat &other);

    private:
        const std::string name_;
        const int         req_grade_to_sign_;
        const int         req_grade_to_exec_;
        bool              is_signed_;
};
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif