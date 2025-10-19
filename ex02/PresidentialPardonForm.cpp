/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:47:30 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 16:58:23 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardon",false,25,5)
{
	this->target = "NoTarget";
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon",false,25,5)
{
	this->target = target;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	this->target = other.target;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
	{
		return(*this);
	}
	AForm::operator=(other);
	this->target = other.target;
	return(*this);
	
}
PresidentialPardonForm::~PresidentialPardonForm(){}
std::string PresidentialPardonForm::getTarget() const
{
	return  this->target;
}
void PresidentialPardonForm::print(std::ostream& os) const
{
	   os << "Type Form: " << _getName() << std::endl
       << "Status: " << _getStatus() << std::endl
       << "Signature level: " << _getTo_sign() << std::endl
       << "Execution level: " << _getTo_exec() << std::endl
       << "Target: " << getTarget() << std::endl;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(executor._getGrade() > 5)
		throw GradeTooLowException();
	else if (this->is_sign == false)
	{
		throw FormNotSign();
	}
	
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}