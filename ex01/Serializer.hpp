/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/31 10:56:45 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <exception>
# include <cstdlib>
# include <stdint.h>

struct Data
{
	int n;
};

class Serializer
{
private:
            Serializer();
            ~Serializer();
            Serializer(Serializer const & copy);
            Serializer &   operator=(Serializer const & rhs);

public:
            static uintptr_t   serialize(Data *ptr);
            static Data *      deserialize(uintptr_t raw);
};

#endif
