/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:35:45 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/29 15:21:37 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
    public:
        Bureaucrat(std::string given_name, std::size_t given_grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName()const;
        std::size_t getGrade()const;
        Bureaucrat& operator++();
        Bureaucrat& operator--();
        //overload of <<
    
    private:
        const std::string name;
        std::size_t grade; //unsure about the type here
};

#endif