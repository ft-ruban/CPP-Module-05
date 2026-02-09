/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/06 15:01:58 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_class_form_getters(Form* form_to_test){
    std::cout<<form_to_test->getName()<<" status is : "<<form_to_test->getIsSigned()
             <<" it require the following grade to sign it: "<<form_to_test->getReqGradeToSign()
             <<" and require the following grade to execute it: "<<form_to_test->getReqGradeToExec()
             <<std::endl;
}

int main(void){
    Bureaucrat* wallace = NULL;
    Form*       form_one = NULL;

    try
    {
        form_one = new Form("form_one", 50, 50);
        wallace = new Bureaucrat("Wallace Breen", 50);
        std::cout<<*wallace<<std::endl;
        test_class_form_getters(form_one);
        //wallace->decrement();
        wallace->signForm(*form_one);
        test_class_form_getters(form_one);
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
    //std::cout<<wallace->getName()<<wallace->getGrade()<<std::endl;
    delete form_one;
    delete wallace;
    return 0; 
}

