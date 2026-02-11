/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/11 09:07:52 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void){
    srand(time(0));
    Bureaucrat* wallace = NULL;
    PresidentialPardonForm* subject = new PresidentialPardonForm("subject");
    ShrubberyCreationForm* trees = new ShrubberyCreationForm("prettitree");
    RobotomyRequestForm* robotomy = new RobotomyRequestForm("roboto");

    try
    {
        wallace = new Bureaucrat("Wallace Breen", 2);
        std::cout<<*wallace<<std::endl;
        wallace->signForm(*subject);
        wallace->executeForm(*subject);
        wallace->signForm(*trees);
        wallace->executeForm(*trees);
        wallace->signForm(*robotomy);
        wallace->executeForm(*robotomy);
        wallace->executeForm(*robotomy);
        std::cout<<"end of try scope"<<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout<< e.what() <<std::endl;
        delete wallace;
        delete subject;
        delete trees;
        std::cout<<"exception caught"<<std::endl;
        return(1);
    }
    std::cout<<"no exception caught"<<std::endl;
    delete wallace;
    delete subject;
    delete trees;
    delete robotomy;
    return 0; 
}

