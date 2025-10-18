/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:08:42 by pablo             #+#    #+#             */
/*   Updated: 2025/10/18 14:31:20 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"
#include"Bureaucrat.hpp"

int main(void)
{
    try
    {
        AForm* form_tipe_1 = new ShrubberyCreationForm("text");
        Bureaucrat manolo("pepe",137);
        manolo.signForm(*form_tipe_1);
        form_tipe_1->execute(manolo);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(0);
    
}