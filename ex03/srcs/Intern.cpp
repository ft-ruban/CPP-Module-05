/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:24:59 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/12 08:59:18 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
}

Intern::Intern(const Intern &other){
    (void)other;
}

Intern &Intern::operator=(const Intern &other){
    (void)other;
    return *this;
}

Intern::~Intern(){
}

AForm* Intern::makeForm(const std::string& form_name,
                        const std::string target_form){
    std::string available_forms[3]= {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };
    
    AForm* (Intern::*functions[3])(std::string) = {
        &Intern::makeRobotomy,
        &Intern::makeShrubbery,
        &Intern::makePresidentialPardon
    };
    for(int i = 0; i < 3; i++){
        if(available_forms[i] == form_name){
            std::cout<<"Intern creates "<<form_name<<std::endl;
            return((this->*functions[i])(target_form));
        }
    }
    std::cout<<"ERROR: "
             <<form_name
             <<" does not exist (yet?) intern was unable to create the form"
             <<std::endl;
    return(NULL);
}

//todo protect?
AForm* Intern::makeRobotomy(std::string target_form){
    RobotomyRequestForm* robotomy = NULL;
    try{
        robotomy = new RobotomyRequestForm(target_form);
    }
    catch (std::bad_alloc & ba){
        std::cout<<"bad_alloc caught: "<<ba.what()<<std::endl;
        return(NULL);
    }
    return(robotomy);
}

AForm* Intern::makeShrubbery(std::string target_form){
    ShrubberyCreationForm* shrubbery = NULL;
    try{
        shrubbery = new ShrubberyCreationForm(target_form);
    }
    catch(std::bad_alloc & ba){
        std::cout<<"bad_alloc caught: "<<ba.what()<<std::endl;
        return(NULL);
    }
    return(shrubbery);
}

AForm* Intern::makePresidentialPardon(std::string target_form){
    PresidentialPardonForm* pardon = NULL;
    try{
        pardon = new PresidentialPardonForm(target_form);
    }
    catch (std::bad_alloc & ba){
        std::cout<<"bad_alloc caught: "<<ba.what()<<std::endl;
        return(NULL);
    }
    return(pardon);
}