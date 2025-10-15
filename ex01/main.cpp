/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:52:20 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/15 20:21:13 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Form.hpp"
#include"Bureaucrat.hpp"
int main(void)
{
	try
	{
		Bureaucrat b;
		b._incriseGrade();
		Form a("hola",0,149,149);
		b.signForm(a);
		a.beSigned(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}