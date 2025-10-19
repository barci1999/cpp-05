/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:59:39 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 18:42:10 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"Intern.hpp"
#include"RobotomyRequestForm.hpp"
#include"Bureaucrat.hpp"

int main(void)
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return(0);
}