/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/10 11:26:26 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){
    Bureaucrat* wallace = NULL;
    PresidentialPardonForm* test = new PresidentialPardonForm("test");
    ShrubberyCreationForm* trees = new ShrubberyCreationForm("joliarb");

    try
    {
        wallace = new Bureaucrat("Wallace Breen", 1);
        std::cout<<*wallace<<std::endl;
        wallace->signForm(*test);
        wallace->executeForm(*test);
        wallace->signForm(*trees);
        wallace->executeForm(*trees);
        std::cout<<"end of try scope"<<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout<< e.what() <<std::endl;
        delete wallace;
        delete test;
        delete trees;
        std::cout<<"exception caught"<<std::endl;
        return(1);
    }
    std::cout<<"no exception caught"<<std::endl;
    //std::cout<<wallace->getName()<<wallace->getGrade()<<std::endl;
    delete wallace;
    delete test;
    delete trees;
    return 0; 
}

