/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 08:10:41 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/25 08:10:41 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const & literal)
{
	int		in;
	double	db;

	db = std::atof(literal.c_str());

	if (std::isfinite(db) && db >= INT_MIN && db <= INT_MAX)
	{
		in = std::atoi(literal.c_str());

		std::cout << "char: ";
		if (in < 0 || in > 255)
			std::cout << "impossible" << std::endl;
		else if (in < 33 || in == 255)
			std::cout << "Non displayable" << std::endl;
		else 
			std::cout << (char) in << std::endl;
		std::cout << "int: " << in << std::endl;
	}
	else
	{
		std::cout	<< "char: impossible" << std::endl 
					<< "int: impossible" << std::endl;
	}

	std::cout	<< "float: ";
	std::cout	<< std::setprecision(5) << (float)db;
	if (floorf(db) == db)
		std::cout	<< ".0";
	std::cout	<< "f" << std::endl;
	std::cout	<< "double: " << std::setprecision(10) << db;
	if (floorf(db) == db)
		std::cout	<< ".0";
	std::cout	<< std::endl;

}
