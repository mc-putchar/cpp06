/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 08:10:41 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/09 19:37:37 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

void ScalarConverter::convert(std::string const & literal)
{
	char				character;
	int					integer(0);
	float				floating;
	double				double_prec;
	bool				is_impossible;
	bool				is_finite;
	bool				is_int;
	bool				is_displayable;
	std::stringstream	stream(literal);

	is_finite = (literal != "nan" && literal != "NaN" 
		&& literal != "inf" && literal != "-inf"
		&& literal != "inff" && literal != "-inff");
	if (!is_finite)
	{
		if (literal == "inf" || literal == "inff")
		{
			double_prec = std::numeric_limits<double>::infinity();
			floating = std::numeric_limits<float>::infinity();
		}
		else if (literal == "-inf" || literal == "-inff")
		{
			double_prec = -std::numeric_limits<double>::infinity();
			floating = -std::numeric_limits<float>::infinity();
		}
		else
		{
			double_prec = std::numeric_limits<double>::quiet_NaN();
			floating = std::numeric_limits<float>::quiet_NaN();
		}
		is_impossible = false;
	}
	else if (literal.find('.') != literal.npos
	|| literal.find('f') != literal.npos)
	{
		stream.clear();
		stream >> double_prec;
		is_impossible = stream.fail();
		is_int = !is_impossible && is_finite && double_prec >= INT_MIN
			&& double_prec <= INT_MAX;
		is_displayable = is_int && double_prec > 32 && double_prec < 255;
		if (!is_impossible)
		{
			floating = static_cast<float>(double_prec);
			if (is_int)
			{
				integer = static_cast<int>(double_prec);
				if (is_displayable)
					character = static_cast<char>(integer);
			}
		}
	}
	else
	{
		if (std::isdigit(literal[0])
		|| ((literal[0] == '-' || literal[0] == '+')
			&& std::isdigit(literal[1])))
		{
			stream.clear();
			stream >> integer;
			is_impossible = stream.fail();
			is_displayable = !is_impossible && integer > 32 && integer < 255;
			if (is_displayable)
				character = static_cast<char>(integer);
		}
		else if (literal.length() == 1)
		{
			stream.clear();
			stream >> character;
			is_impossible = stream.fail();
			if (!is_impossible)
				integer = static_cast<int>(character);
		}
		else
			is_impossible = true;
		if (!is_impossible)
		{
			double_prec = static_cast<double>(integer);
			floating = static_cast<float>(integer);
		}
	}
	std::cout << "char: ";
	if (is_impossible || !is_finite)
		std::cout << "impossible";
	else if (!is_displayable)
		std::cout << "Non displayable";
	else
		std::cout << character;
	std::cout << std::endl << "int: ";
	if (is_impossible || !is_finite)
		std::cout << "impossible";
	else
		std::cout << integer;
	std::cout << std::endl << "float: "
		<< std::fixed << std::setprecision(2);
	if (is_impossible)
		std::cout << "impossible";
	else
		std::cout << floating << 'f';
	std::cout << std::endl << "double: ";
	if (is_impossible)
		std::cout << "impossible";
	else
		std::cout << double_prec;
	std::cout << std::endl;
}
