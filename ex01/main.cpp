/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:17:54 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/14 21:00:00 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	intro_msg(void)
{
	std::cout << std::endl;
	std::cout << "Welcome to your amazing PhoneBook software v.2.0.1!" << std::endl;
	std::cout << "Please input one of the following commands:" << std::endl << std::endl;
	std::cout << "ADD - adds a new contact to the phonebook" << std::endl;
	std::cout << "SEARCH - searches the phonebook for a specific contact" << std::endl;
	std::cout << "EXIT - exits the software" << std::endl;
	std::cout << ">";	
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string str;

	while (1)
	{
		intro_msg();
		std::cin >> str;
		if (!str.compare("ADD"))
			phonebook.add_contact();		
		else if (!str.compare("SEARCH"))
			phonebook.search_contact();
		else if (!str.compare("EXIT"))
			exit(0);
		else
			std::cout << "Invalid input. Please enter 'ADD', 'SEARCH' or 'EXIT'." << std::endl;		
	}

	
}