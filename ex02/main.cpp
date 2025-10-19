/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:08:42 by pablo             #+#    #+#             */
/*   Updated: 2025/10/19 15:15:32 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"
#include"Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    try
    {
        AForm* form_tipe_1 = new RobotomyRequestForm("text");
        Bureaucrat manolo("pepe",45);
        std::cout << *form_tipe_1;
        manolo.signForm(*form_tipe_1);
        form_tipe_1->execute(manolo);
        delete form_tipe_1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(0);
    
}