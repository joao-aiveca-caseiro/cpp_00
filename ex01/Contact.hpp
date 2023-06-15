/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:53:54 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/14 21:15:07 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		
		// Contact();
		
		std::string	getFirstname(void) const;
		std::string	getLastname(void) const;
		std::string	getNickname(void) const;
		std::string	getPhone(void) const;
		std::string	getSecret(void) const;
		
		void	setFirstname(std::string str);
		void	setLastname(std::string str);
		void	setNickname(std::string str);
		void	setPhone(std::string str);
		void	setSecret(std::string str);
	
	private:
	
	std::string	_firstname;
	std::string	_lastname;
	std::string _nickname;
	std::string	_phone;
	std::string	_secret;

};

#endif