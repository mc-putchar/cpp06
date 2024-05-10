/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:10:38 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/10 10:41:54 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <sstream>

#include "Base.hpp"

int main(int ac, char **av)
{
	int	i(1);

	if (ac == 2)
	{
		std::stringstream	ss(av[1]);
		ss >> i;
	}
	i = i < 1 ? 1 : i;
	std::srand(time(NULL));
	while (i--)
	{
		Base *base = generate(rand() % 3);
		identify(base);
		identify(*base);
		delete base;
	}
	return (0);
}
