/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:35:45 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/04 12:34:14 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat{
    public:
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        Bureaucrat(std::string given_name, int given_grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName()const;
        int getGrade()const;
        
        void increment();
        void decrement();
    
    private:
        const std::string name;
        int grade;
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif