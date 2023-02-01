/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:52:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/01 16:57:26 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
	std::string	item;
	int			quantity;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

int main(void)
{
	Data *data = new Data;

	data->item = "cacca";
    data->quantity = 50;

    std::cout << "Item: " << deserialize(serialize(data))->item << std::endl;
    std::cout << "Quantity: " << deserialize(serialize(data))->quantity << std::endl;

	delete data;

	return (0);
}
