/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 07:25:25 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/10 11:21:29 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>//tomove.hpp
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) 
: AForm("ShrubberyCreationForm", 145, 137), target_(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm  &other) 
: AForm(other), target_(other.target_){      
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if(this != &other){
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::formAction()const{
    std::ofstream outfile(target_.c_str());
    outfile << "       _-_                    _-_"<<std::endl;
    outfile << "    /~~   ~~\\              /~~   ~~\\"<<std::endl;
    outfile << " /~~         ~~\\        /~~         ~~\\"<<std::endl;
    outfile << "{               }      {               }"<<std::endl;
    outfile << " \\  _-     -_  /        \\  _-     -_  /"<<std::endl;
    outfile << "   ~  \\\\ //  ~            ~  \\\\ //  ~"<<std::endl;
    outfile << "_- -   | | _- _        _- -   | | _- _"<<std::endl;
    outfile << "  _ -  | |   -_          _ -  | |   -_"<<std::endl;
    outfile << "      // \\\\                  // \\\\"<<std::endl;
    outfile<<"I'd like to be a tree..."<<std::endl;
    outfile.close();
}