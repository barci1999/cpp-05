/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:20:28 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 18:10:33 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Intern.hpp"
Intern::Intern()
{
	std::cout << "Default constructor called." << std::endl;
}
Intern::Intern(const Intern& other)
{
	std::cout << "Copy constructor calles." << std::endl;
	*this = other;
}
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return(*this);
}
Intern::~Intern(){}
static AForm* makeRobotomy(std::string target)
{
	static RobotomyRequestForm form(target);
	return(&form);
}
static AForm* makeShrubbery(std::string target)
{
	static ShrubberyCreationForm form(target);
	return(&form);
}
static AForm* makePresidential(std::string target)
{
	static PresidentialPardonForm form(target);
	return(&form);
}
AForm* Intern::makeForm(std::string type,std::string target)
{
	if(type.empty() || target.empty())
		throw EmptyParameters();
	std::string Form_type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*functions[3])(std::string) = {&makePresidential,&makeRobotomy,&makeShrubbery};
	for (int i = 0; i < 3; i++)
	{
		if(type == Form_type[i])
			return(functions[i](target));
	}
	throw InvalidTypeForm();	
}