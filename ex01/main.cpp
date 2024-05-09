/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:31:44 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/09 20:08:42 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

static void	compareData(Data *d1, Data *d2);

int	main(int ac, char **av)
{
	Data		*data;
	Data		*check;

	if (ac < 2)
	{
		std::cout << "Please provide some test data..." << std::endl;
		return (1);
	}
	data = new Data;
	data->n = ac - 1;
	data->s1 = av[1];
	if (ac > 2)
		data->s2 = av[ac - 1];
	else
		data->s2 = "(null)";
	check = Serializer::deserialize(Serializer::serialize(data));
	compareData(data, check);
	delete data;
	return (0);
}

void	compareData(Data *d1, Data *d2)
{
	std::cout << "Data 1:" << std::endl;
	std::cout << "\taddress: " << d1 << std::endl;
	std::cout << "\tn: " << d1->n << std::endl;
	std::cout << "\tstart: " << d1->s1 << std::endl;
	std::cout << "\tend: " << d1->s2 << std::endl;
	std::cout << "Data 2:" << std::endl;
	std::cout << "\taddress: " << d2 << std::endl;
	std::cout << "\tn: " << d2->n << std::endl;
	std::cout << "\tstart: " << d2->s1 << std::endl;
	std::cout << "\tend: " << d2->s2 << std::endl;
	std::cout << "Data 1 and 2 are "
		<< (d1 == d2 ? "equal" : "not equal") << std::endl;
}
