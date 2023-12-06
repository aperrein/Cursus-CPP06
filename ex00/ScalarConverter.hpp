/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:09:38 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/30 09:09:40 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <exception>
# include <cstdlib>

class ScalarConverter
{
private:
            ScalarConverter();
            ~ScalarConverter();
            ScalarConverter(ScalarConverter const & copy);
            ScalarConverter &   operator=(ScalarConverter const & rhs);

public:
            static void        convert(std::string s);



    	class ImpossibleConvertion: public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
};

#endif
