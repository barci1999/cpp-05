/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:16:09 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/16 16:32:35 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "iostream"
# include "string"
# include "AForm.hpp"
class AForm;
class Bureaucrat
{
private:
	const std::string Name;
	int Grade;
	
public:
	Bureaucrat(/* args */);
	Bureaucrat(const std::string name,int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	class GradeTooHighException: public std::exception {
		public:
			const char* what() const throw(){
				return ("Grade too high.");
			}
	};
	class GradeTooLowException: public std::exception {
		public:
			const char* what() const throw(){
				return ("Grade too low.");
			}
	};
	
	std::string _getName() const;
	int _getGrade() const;

	void _decrementGrade();
	void _incriseGrade();
	void signForm(AForm& to_sign);
	void executeForm(AForm const & form) const;
};
std::ostream  &operator<<( std::ostream &out, const Bureaucrat &to_print);
#endif
