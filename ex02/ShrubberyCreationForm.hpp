/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:47:42 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 14:22:11 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
class ShrubberyCreationForm : public  AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm(/* args */);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	
	std::string getTarget() const;
	void print_tree(std::ofstream& file) const;
	void execute(Bureaucrat const & executor) const;
	void print(std::ostream& os) const;
};
std::ostream &operator<<(std::ostream &out,const ShrubberyCreationForm &to_print);
				
#endif