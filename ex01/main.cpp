/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:52:20 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/16 14:08:45 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Form.hpp"
#include"Bureaucrat.hpp"
int main(void)
{
	try
	{
		Bureaucrat b;
		std::cout << b;
		b._incriseGrade();
		std::cout << b;
		Form a("hola",0,149,149);
		std::cout << a;
		b.signForm(a);
		std::cout << a;
		a.beSigned(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}