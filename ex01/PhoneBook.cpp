/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:54:00 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/20 15:02:22 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_count = 0;
}

std::string	PhoneBook::truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void	PhoneBook::add_contact(void)
{
	Contact		new_contact;
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phone;
	std::string	secret;

	std::cout << "You are adding a new contact. Please fill its details:\n" << std::endl;
	
	std::cout << "First name: ";
	std::cin >> firstname;
	new_contact.setFirstname(firstname);

	std::cout << "Last name: ";
	std::cin >> lastname;
	new_contact.setLastname(lastname);

	std::cout << "Nickname: ";
	std::cin >> nickname;
	new_contact.setNickname(nickname);

	std::cout << "Phone number: ";
	std::cin >> phone;
	while (phone.find_first_not_of("0123456789") != -1)
	{
		std::cout << "❌ Invalid input. Please insert digits only. ❌" << std::endl;
		std::cout << "Phone number: ";
		std::cin >> phone;		
	}
	new_contact.setPhone(phone);

	std::cout << "Darkest secret: ";
	while (secret.empty())
	{
		std::getline(std::cin, secret);
		new_contact.setSecret(secret);
	}
	
	this->_contacts[this->_count % 8] = new_contact;
	this->_count++;

	std::cout << "✅ Contact successfully added with index "<< (this->_count - 1) % 8 << " ✅" << std::endl;
}

void	PhoneBook::search_contact(void)
{
	int	i = -1;
	int	max = 0;
	std::string separator = "|__________|__________|__________|__________|";
	
	std::cout << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX"
			<< "|" << std::setw(10) << "FIRST NAME"
			<< "|" << std::setw(10) << "LAST NAME"
			<< "|" << std::setw(10) << " NICKNAME" 
			<< "|" << std::endl;
	std::cout << separator << std::endl;

	if (this->_count > 7)
		max = 7;
	else
		max = this->_count - 1;
	
	if (max == -1)
	{
		std::cout << "\n📒 The phonebook is empty! Please try adding a contact first. 📒" << std::endl;
		return ;
	}
	while (++i <= max)
	{
		std::cout << "|" << std::setw(10) << i
				<< "|" << std::setw(10) << this->truncate(this->_contacts[i].getFirstname())
				<< "|" << std::setw(10) << this->truncate(this->_contacts[i].getLastname())
				<< "|" << std::setw(10) << this->truncate(this->_contacts[i].getNickname())
				<< "|" << std::endl;		
	}
	std::cout << std::endl;
	this->display_contact();
}

void	PhoneBook::display_contact(void)
{
	int	valid = 0;
	std::string	index;
	
	while (valid == 0)
	{
		std::cout << "Please enter the index of the contact you wish to display." << std::endl;
		std::cout << ">";
		std::cin >> index;
		if (index.find_first_not_of("0123456789") != -1 || (atoi(index.c_str()) < 0 || atoi(index.c_str()) > 7))
			std::cout << "❌ Invalid input. Please enter a number between 0 and 7. ❌" << std::endl;		
		else if (atoi(index.c_str()) > this->_count - 1)
			std::cout << "❌ There's no contact with index " << index << ". Please try again. ❌" << std::endl;			
		else
			valid = 1;				
	}
	
	std::cout << "You are now viewing the contact with index " << index << std::endl << std::endl;
	std::cout << "FIRST NAME: " << this->_contacts[atoi(index.c_str())].getFirstname() << std::endl;
	std::cout << "LAST NAME: " << this->_contacts[atoi(index.c_str())].getLastname() << std::endl;
	std::cout << "NICKNAME: " << this->_contacts[atoi(index.c_str())].getNickname() << std::endl;
	std::cout << "PHONE NUMBER: " << this->_contacts[atoi(index.c_str())].getPhone() << std::endl;
	std::cout << "DARKEST SECRET: " << this->_contacts[atoi(index.c_str())].getSecret() << std::endl;	
}