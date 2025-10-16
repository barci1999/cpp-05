/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:53:34 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/16 12:21:13 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AForm.hpp"

AForm::AForm() : Name("NoName"), is_sign(false), to_sign(150), to_exec(150)
{
	std::cout << "Default constructor called.\n";
}
AForm::AForm(std::string name,bool is_sign,const int to_sign,const int to_exec):
Name(name),is_sign(is_sign) ,to_sign(to_sign),to_exec(to_exec)
{
	std::cout << "Parametered constructor called.\n";
	{
    if (to_sign < 1 || to_exec < 1)
    throw AForm::GradeTooHighException();
    if (to_sign > 150 || to_exec > 150)
    throw AForm::GradeTooLowException();
}
}
AForm::AForm(const AForm& other): Name(other.Name), is_sign(other.is_sign),to_sign(other.to_sign),to_exec(other.to_exec) 
{
	std::cout << "Copy consructor called.\n";
}
AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Assignment operator called.\n";
	if(this == &other)
	{
		return(*this);
	}
	this->is_sign = other.is_sign;
	return(*this);
}

AForm::~AForm()
{
	std::cout << "Destructor called\n";
}
std::string AForm::_getName() const {return this->Name;}
int AForm::_getTo_sign() const {return this->to_sign;}
int AForm::_getTo_exec() const {return this->to_exec;}
bool AForm::_getStatus() const {return this->is_sign;}

std::ostream &operator<<(std::ostream &out, const AForm &to_print)
{
    out << "AForm name: " << to_print._getName()
        << " Status: " << to_print._getStatus()
        << " Signature level: " << to_print._getTo_sign()
        << " Execution level: " << to_print._getTo_exec() << std::endl;
    return out;
}
void AForm::beSigned(Bureaucrat& check)
{
	if(check._getGrade() > this->to_sign)
		throw GradeTooLowException();
	else if (this->is_sign == true)
		throw FormAlreadySign();
	this->is_sign = true;
}
