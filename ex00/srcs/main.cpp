/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/11 08:50:00 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> //for atoi
#include "Bureaucrat.hpp"

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

int main(int argc, char *argv[]){
    if(argc != 3){
        std::cout<<"enter 2 arguments (first would be the name of the bureaucrat) second the given grade"<<std::endl;
        return(1);
    }
    std::string bureaucrat_name = argv[1];
    int given_grade = atoi(argv[2]);
    //std::cout<<given_grade<<std::endl;
    Bureaucrat_test("bureaucrat_object Breen", given_grade);    
    return 0; 
}
