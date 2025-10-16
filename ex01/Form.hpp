/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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
class Bureaucrat;
class Form
{
private:
	const std::string Name;
	bool is_sign;
	const int to_sign;
	const int to_exec;
public:
	Form();
	Form(std::string Name,bool is_sign,const int to_sign,const int to_exec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

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
				return("Form already signed");
			}
	};
	std::string _getName() const;
	int _getTo_sign() const;
	int _getTo_exec() const;
	bool _getStatus() const;
	void beSigned(Bureaucrat& check);
};
std::ostream &operator<<(std::ostream &out,const Form &to_print);
#endif
