/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:16:07 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/15 17:13:26 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): Name("NoName") , Grade(150)
{
	std::cout << "default constructor called.\n";
}
Bureaucrat::Bureaucrat(const std::string name,int grade): Name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
	std::cout << "Parametered constructor called.\n";
	this->Grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : Name(other.Name), Grade(other.Grade)
{
	std::cout << "Copy constructor called.\n";
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "assigment opperator called.\n";
	if (this == &other)
	{
		return(*this);
	}
	this->Grade = other._getGrade();
	return(*this);
}
std::string Bureaucrat::_getName() const
{
	return(this->Name);
}
int Bureaucrat::_getGrade() const
{
	return(this->Grade);
}
void Bureaucrat::_incriseGrade()
{
	if (this->Grade == 1)
	{
		throw GradeTooHighException();
	}
	this->Grade -=1;
}
void Bureaucrat::_decrementGrade()
{
	if(this->Grade == 150)
	{
		throw GradeTooLowException();
	}
	this->Grade +=1;
}
std::ostream &operator<<( std::ostream &out, const Bureaucrat &to_print)
{
	out << to_print._getName() << ", bureaucrat grade " << to_print._getGrade() << std::endl;
	return(out);
}
Bureaucrat::~Bureaucrat()
{}