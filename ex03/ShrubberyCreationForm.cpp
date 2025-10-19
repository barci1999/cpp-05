/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:47:40 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 16:58:58 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation",false,145,137)
{
	//std::cout << "Default constructor called." << std::endl;
	this->target = "NoTarget";	
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation",false,145,137)
{
	//std::cout << "Parametered constructor called." << std::endl;
	this->target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
	//std::cout << "Copied constructor called." << std::endl;
	this->target = other.target;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	//std::cout << "assignment operator called." << std::endl;
	if (this == &other)
	{
		return(*this);
	}
	AForm::operator=(other);
	this->target = other.target;
	return(*this);
	
}
void ShrubberyCreationForm::print(std::ostream& os) const {
    os << "Type Form: " << _getName() << std::endl
       << "Status: " << _getStatus() << std::endl
       << "Signature level: " << _getTo_sign() << std::endl
       << "Execution level: " << _getTo_exec() << std::endl
       << "Target: " << getTarget() << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
std::string ShrubberyCreationForm::getTarget() const
{
	return(this->target);
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(executor._getGrade() > 137)
		throw GradeTooLowException();
	else if (this->is_sign == false)
	{
		throw FormNotSign();
	}
	
	std::ofstream file((this->target + "_shrubbery").c_str());
	if(!file)
		throw std::runtime_error("Error creating file");
	this->print_tree(file);
}
void ShrubberyCreationForm::print_tree(std::ofstream& file) const
{
	file << "        *\n";
    file << "       ***\n";
    file << "      *****\n";
    file << "     *******\n";
    file << "    *********\n";
    file << "   ***********\n";
    file << "  *************\n";
    file << " ***************\n";
    file << "*****************\n";
    file << "       |||||\n";
    file << "       |||||\n";
    file << "     ___|||___\n";
    file << "    /   |||   \\\n";
    file << "   /____|||____\\\n";
	
}