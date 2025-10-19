/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:47:35 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 15:10:45 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequest",false,72,45)
{
	//std::cout << "Default contructor called." << std::endl;
	this->target = "NoTarget";
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest",false,72,45)
{
	//std::cout << "parametered construtor called." << std::endl;
	this->target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	//std::cout << "Copy constructor called." <<std::endl;
	this->target = other.target;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	//std::cout << "assigment operator called." <<std::endl;
	if (this == &other)
	{
		return *this;
	}
	AForm::operator=(other);
	this->target = other.target;
	return *this;
	
}
RobotomyRequestForm::~RobotomyRequestForm(){}
std::string RobotomyRequestForm::getTarget() const
{
	return(this->target);
}
void RobotomyRequestForm::print(std::ostream& os) const {
    os << "Type Form: " << _getName() << std::endl
       << "Status: " << _getStatus() << std::endl
       << "Signature level: " << _getTo_sign() << std::endl
       << "Execution level: " << _getTo_exec() << std::endl
       << "Target: " << getTarget() << std::endl;
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(executor._getGrade() < 45)
		throw GradeTooHighException();
	else if (executor._getGrade() > 45)
	{
		throw GradeTooHighException();
	}
	std::cout << "Incredible drilling noises." <<  std::endl;
	std::srand(time(0));
	if(std::rand() % 2)
		std::cout << this->target << " has been robotomized succesfully." << std::endl;
	else
	{
		std::cout << "Failed to robotomized " << this->target << std::endl;
	}
}
