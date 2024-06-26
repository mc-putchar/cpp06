/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:28:43 by mcutura           #+#    #+#             */
/*   Updated: 2023/09/29 00:11:41 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data * ptr)
{
	return (reinterpret_cast <uintptr_t> (ptr));
}

Data * Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data *> (raw));
}
