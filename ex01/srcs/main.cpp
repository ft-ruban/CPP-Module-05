/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/12 09:49:47 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

bool Bureaucrat_test(std::string name_bureaucrat, int grade_to_give){
    Bureaucrat* bureaucrat_object = NULL;
    try
    {
        bureaucrat_object = new Bureaucrat(name_bureaucrat, grade_to_give);
        std::cout<<*bureaucrat_object<<std::endl;
        bureaucrat_object->increment();
        std::cout<<*bureaucrat_object<<std::endl;
        bureaucrat_object->decrement();
        bureaucrat_object->decrement();
        std::cout<<*bureaucrat_object<<std::endl;
        std::cout<<"end of try scope"<<std::endl;
    }
    catch (std::exception & e)
    {
        delete bureaucrat_object;
        std::cout<<"exception caught "<<e.what()<<std::endl;
        return(1);
    }
    std::cout<<"no exception caught"<<std::endl;
    delete bureaucrat_object;
    return(0);
}

int main(void){
    Bureaucrat* wallace = NULL;
    Form*       form_one = NULL;

    try
    {
        form_one = new Form("form_one", 15, 45);
        wallace = new Bureaucrat("Wallace Breen", 80);
        std::cout<<*wallace<<std::endl;
        std::cout<<*form_one<<std::endl;
        wallace->signForm(*form_one);
        std::cout<<*form_one<<std::endl;
        std::cout<<"end of try scope"<<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout<< e.what() <<std::endl;
        delete wallace;
        delete form_one;
        std::cout<<"exception caught"<<std::endl;
        return(1);
    }
    std::cout<<"no exception caught"<<std::endl;
    delete form_one;
    delete wallace;
    return 0; 
}

