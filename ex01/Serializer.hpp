/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:18:22 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/09 20:05:40 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>

struct Data
{
	int			n;
	std::string	s1;
	std::string	s2;
};

class Serializer
{

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
