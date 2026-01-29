/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/29 15:16:07 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat j("test", 5);
    std::cout<<j.getName()<<j.getGrade()<<std::endl;
    return 0; 
}

