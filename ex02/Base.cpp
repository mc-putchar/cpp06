/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:53:35 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/10 10:44:27 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <exception>

#include "Base.hpp"

Base	* generate(int i)
{
	if (!i)
	{
		std::cout << "Generated A" << std::endl;
		return (new A);
	}
	if (i == 1)
	{
		std::cout << "Generated B" << std::endl;
		return (new B);
	}
	std::cout << "Generated C" << std::endl;
	return (new C);
}

void	identify(Base* p)
{
	A	*a;
	B	*b;
	C	*c;

	if ((a = dynamic_cast<A*>(p)) != NULL)
		std::cout << "Indentified pointer to A" << std::endl;
	else if ((b = dynamic_cast<B*>(p)) != NULL)
		std::cout << "Indentified pointer to B" << std::endl;
	else if ((c = dynamic_cast<C*>(p)) != NULL)
		std::cout << "Indentified pointer to C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p)
{
	try {
		A & a = dynamic_cast<A&>(p);
		(void)a;
	} catch (std::exception &e) {
		try {
			B & a = dynamic_cast<B&>(p);
			(void)a;
		} catch (std::exception &e) {
			try {
				C & a = dynamic_cast<C&>(p);
				(void)a;
			} catch (std::exception &e) {
				std::cout << "Unknown" << std::endl;
				return ;
			}
			std::cout << "Indentified pointer to C" << std::endl;
			return ;
		}
		std::cout << "Indentified pointer to B" << std::endl;
		return ;
	}
	std::cout << "Indentified pointer to A" << std::endl;
}
