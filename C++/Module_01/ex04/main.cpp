/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:14:10 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/07 19:10:26 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replace(std::string file_path, std::string to_be_replaced, std::string replacement);
void	actual_replacement(std::string file_path, std::string content,
					std::string to_be_replaced, std::string replacement);

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr<< "Need 3 arguments: "
			<< "<file_path> <str_to_be_replaced> <replacement_string>" << std::endl;
		return (0);
	}
	replace(argv[1], argv[2], argv[3]);
	return (0);
}

void	replace(std::string file_path, std::string to_be_replaced, std::string replacement)
{
	std::ifstream	input_file(file_path);
	std::string		content;

	if (!input_file.is_open())
	{
		std::cerr << "Unable to open " << file_path << std::endl;
		input_file.close();
		return ;
	}
	if (!std::getline(input_file, content, '\0'))
	{
		std::cerr << file_path << " is empty" << std::endl;
		input_file.close();
		return ;
	}
	actual_replacement(file_path, content, to_be_replaced, replacement);
	input_file.close();
}

void	actual_replacement(std::string file_path, std::string content,
					std::string to_be_replaced, std::string replacement)
{
	std::ofstream	output_file(file_path + ".replace");
	size_t			pos;

	pos = content.find(to_be_replaced);
	while (pos != content.npos)
	{
		content.erase(pos, to_be_replaced.size());
		content.insert(pos, replacement);
		pos = content.find(to_be_replaced);
	}
	output_file << content;
	output_file.close();
}
