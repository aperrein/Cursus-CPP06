/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:19:04 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/31 11:19:05 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int num = rand() % 100;

	if (num < 33)
		return (new A);
	else if (num < 66)
		return (new B);
	return (new C);
}

void identify(Base * p)
{
    
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
    std::cout << " pointer fct";
}

void identify(Base & p)
{
	if (dynamic_cast<A*>(&p) != NULL)
		std::cout << "A";
	if (dynamic_cast<B*>(&p) != NULL)
		std::cout << "B";
	if (dynamic_cast<C*>(&p) != NULL)
		std::cout << "C";
    std::cout << " reference fct";
}

int         main()
{
    srand(time(NULL));
    int i = 0;
    while (i < 100)
    {
    	std::cout << "Test :" << i << std::endl;
		Base *ptr = generate();
		std::cout << "identify_from_pointer: ";
		identify(ptr);
		std::cout << std::endl << "identify_from_reference: ";
		identify(*ptr);
		std::cout << std::endl;
		std::cout << std::endl;
        i++;
    }
	
    return (0);
}
