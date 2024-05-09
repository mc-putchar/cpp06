/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:10:38 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/09 20:11:33 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "Base.hpp"

int main()
{
	std::srand(time(NULL));
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
