/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:47:40 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/16 19:01:43 by pablalva         ###   ########.fr       */
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
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(target)
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
	this->target = other.target;
	AForm::operator=(other);
	return(*this);
	
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(executor._getGrade() > 137)
		throw GradeTooLowException();
	else if (executor._getGrade() < 137)
		throw GradeTooHighException();
	std::ofstream file(this->target + "_shrubbery");
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