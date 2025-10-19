/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:53:38 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/16 12:07:55 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include"iostream"
# include"string"
# include"Bureaucrat.hpp"
# include"fstream"

class Bureaucrat;
class AForm
{
protected:
	const std::string Name;
	bool is_sign;
	const int to_sign;
	const int to_exec;
	class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw (){
					return("Grade to low");
				}
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw (){
					return("Grade to high");
				}
		};
		class FormAlreadySign : public std::exception
		{
			public:
				const char* what() const throw (){
					return("the form already signed");
				}
		};
		class FormNotSign : public std::exception
		{
			public:
				const char* what() const throw (){
					return("the form is not sign");
				}
		};
public:
	AForm();
	AForm(std::string Name,bool is_sign,const int to_sign,const int to_exec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	std::string _getName() const;
	int _getTo_sign() const;
	int _getTo_exec() const;
	bool _getStatus() const;
	void beSigned(Bureaucrat& check);
	virtual void execute(Bureaucrat const & executor) const =  0;
	virtual void print(std::ostream& os) const = 0;
};
std::ostream &operator<<(std::ostream &out,const AForm &to_print);
#endif
