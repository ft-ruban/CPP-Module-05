/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/04 13:02:48 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat* j = NULL;

    try
    {
        j = new Bureaucrat("test", 150);
        std::cout<<*j<<std::endl;
        j->increment();
        std::cout<<*j<<std::endl;
        j->decrement();
        std::cout<<*j<<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout<<"exception caught"<<std::endl;
        return(1);
    }
    std::cout<<"no exception caught"<<std::endl;
    std::cout<<j->getName()<<j->getGrade()<<std::endl;
    delete j;
    return 0; 
}

