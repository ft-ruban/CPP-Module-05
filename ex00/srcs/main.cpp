/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/04 16:06:41 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat* wallace = NULL;

    try
    {
        wallace = new Bureaucrat("Wallace Breen", 15);
        std::cout<<*wallace<<std::endl;
        wallace->increment();
        std::cout<<*wallace<<std::endl;
        wallace->decrement();
        //bureaucrat->decrement();
        std::cout<<*wallace<<std::endl;
    }
    catch (std::exception & e)
    {
        delete wallace;
        std::cout<<"exception caught"<<std::endl;
        return(1);
    }
    std::cout<<"no exception caught"<<std::endl;
    //std::cout<<wallace->getName()<<wallace->getGrade()<<std::endl;
    delete wallace;
    return 0; 
}

