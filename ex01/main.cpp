/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:03:28 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/31 11:03:29 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *data;
	uintptr_t rawData;
	Data *retData;

	data = new Data;

    data->n = 2;
	std::cout << "Data               : " << data << " data->n value " << data->n << std::endl;
	rawData = Serializer::serialize(data);
	std::cout << "Raw Data           : " << rawData << std::endl;
	retData = Serializer::deserialize(rawData);
	std::cout << "Ret Data           : " << retData << " retData->n value " << retData->n << std::endl;

    delete data;
	return 0;
}
