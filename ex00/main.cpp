/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:11:26 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/30 09:11:27 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int     main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "[Error]: " << " Wrong number arguments!\n";
		return (1);
	}
	try
	{
		ScalarConverter::convert(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}