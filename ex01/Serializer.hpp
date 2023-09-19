/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:18:22 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/25 17:18:22 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

class Serializer
{
	typedef struct Data
	{
		unsigned int	ui;
	}	Data;

	public:
		static uintptr_t serialize(Data * ptr);
		static Data * deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const & copy);
		~Serializer();
		Serializer & operator=(Serializer const & assign);
};

#endif