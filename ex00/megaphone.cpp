/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:47:44 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/14 20:31:07 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>


int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = -1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[++i])
		{
			while (argv[i][++j])
				std::cout << (char)toupper(argv[i][j]);
			if (argv[i][j - 1] != 32 && (argv[i + 1] 
				&& argv[i + 1][0] && argv[i + 1][0] != 32))
				std::cout << " ";
			j = -1;
		}
		std::cout << std::endl;	
	}
}
