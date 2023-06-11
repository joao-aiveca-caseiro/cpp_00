/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:54:03 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/11 17:03:46 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp";

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	add_contact(void);
	void	search_contact(void);
	
private:
	int		_count;
	Contact	_contacts[8];
};

# endif
