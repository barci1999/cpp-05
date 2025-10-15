/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:53:34 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/15 20:17:21 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Form.hpp"

Form::Form() : Name("NoName"), is_sign(false), to_sign(150), to_exec(150)
{
	std::cout << "Default constructor called.\n";
}
Form::Form(std::string name,bool is_sign,const int to_sign,const int to_exec):
Name(name),is_sign(is_sign) ,to_sign(to_sign),to_exec(to_exec)
{
	std::cout << "Parametered constructor called.\n";
	{
    if (to_sign < 1 || to_exec < 1)
    throw Form::GradeTooHighException();
    if (to_sign > 150 || to_exec > 150)
    throw Form::GradeTooLowException();
}
}
Form::Form(const Form& other): Name(other.Name), is_sign(other.is_sign),to_sign(other.to_sign),to_exec(other.to_exec) 
{
	std::cout << "Copy consructor called.\n";
}
Form& Form::operator=(const Form& other)
{
	std::cout << "Assignment operator called.\n";
	if(this == &other)
	{
		return(*this);
	}
	this->is_sign = other.is_sign;
	return(*this);
}

Form::~Form()
{
	std::cout << "Destructor called\n";
}
std::string Form::_getName() {return this->Name;}
int Form::_getTo_sign() {return this->to_sign;}
int Form::_getTo_exec() {return this->to_exec;}

void Form::beSigned(Bureaucrat& check)
{
	if(check._getGrade() > this->to_sign)
		throw GradeTooLowException();
	else if (this->is_sign == true)
		throw FormAlreadySign();
	this->is_sign = true;
}
