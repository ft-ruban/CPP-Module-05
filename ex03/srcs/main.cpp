/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/12 09:14:52 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void){
    srand(time(0));
    
    Bureaucrat* wallace = new Bureaucrat("Wallace Breen", 2);
    Intern someRandomIntern;
    AForm* rrf;
    AForm* wrongform;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    wallace->executeForm(*rrf);
    wallace->signForm(*rrf);
    wallace->executeForm(*rrf);
    wrongform = someRandomIntern.makeForm("404", "bll");
    delete wallace;
    delete rrf;
    return 0; 
}

