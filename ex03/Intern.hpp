/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:20:30 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 18:02:43 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "string"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
class Intern
{
private:
	/* data */
public:
	Intern(/* args */);
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	
	class EmptyParameters : public std::exception
		{
			public:
				const char* what() const throw (){
					return("Empty parameters.");
				}
		};
	class InvalidTypeForm : public std::exception
		{
			public:
				const char* what() const throw (){
					return("Invalid type form.");
				}
		};
	
	AForm* makeForm(std::string type,std::string target);
};

#endif