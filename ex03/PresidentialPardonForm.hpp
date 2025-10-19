/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:47:33 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 15:38:16 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(/* args */);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
	void print(std::ostream& os) const;
	std::string getTarget() const;
};
std::ostream operator<<(std::ostream &out,const PresidentialPardonForm &to_print);
#endif