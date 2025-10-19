/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:08:42 by pablo             #+#    #+#             */
/*   Updated: 2025/10/19 17:14:19 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"
#include"Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"

int main(void)
{
    AForm* form_tipe_1 = new PresidentialPardonForm("text");
    Bureaucrat B_1("adolfo",5);
    try
    {
        std::cout << *form_tipe_1;
        B_1.signForm(*form_tipe_1);
        std::cout << *form_tipe_1;
        B_1.executeForm(*form_tipe_1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete form_tipe_1;
    return(0);
    
}