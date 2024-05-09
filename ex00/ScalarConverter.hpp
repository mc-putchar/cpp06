/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 07:04:48 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/09 13:22:32 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cctype>
# include <climits>
# include <cmath>
# include <cstdlib>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>

class ScalarConverter
{
	public:
		static void convert(std::string const & literal);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & copy);
		~ScalarConverter();
		ScalarConverter const & operator=(ScalarConverter const & assign);
};

#endif
