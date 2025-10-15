/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:16:09 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/15 17:09:42 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
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
				return ("Grade too high.\n");
			}
	};
	class GradeTooLowException: public std::exception {
		public:
			const char* what() const throw(){
				return ("Grade too low.\n");
			}
	};
	
	std::string _getName() const;
	int _getGrade() const;

	void _decrementGrade();
	void _incriseGrade();
};
std::ostream  &operator<<( std::ostream &, const Bureaucrat &);

