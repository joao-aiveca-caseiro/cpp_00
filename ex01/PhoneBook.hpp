/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:54:03 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/15 16:16:27 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>

class PhoneBook
{
	public:
		
		PhoneBook();

		void		add_contact(void);
		void		search_contact(void);
		void		display_contact(void);
		std::string	truncate(std::string str);
		
	private:
		
		int		_count;
		Contact	_contacts[8];
};

#endif
