/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:47:38 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/19 15:12:21 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include<cstdlib>
class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(/* args */);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
	void print(std::ostream& os) const;
};


#endif