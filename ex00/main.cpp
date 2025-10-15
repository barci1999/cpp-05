/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:16:11 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/15 17:22:44 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Alfonso",56);
		std::cout << b;
		b._incriseGrade();
		std::cout << b;
		b._decrementGrade();
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat b("jose",150);
		b._decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat b("pepe",1);
		b._incriseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}