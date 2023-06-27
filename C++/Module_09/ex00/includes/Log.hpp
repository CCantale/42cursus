/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:09:31 by ccantale          #+#    #+#             */
/*   Updated: 2023/06/27 16:09:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_HPP
# define LOG_HPP

# define LOGPATH	"Logbook/log"
# define FOLDERPATH	"./Logbook"

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"

# include <fstream>
# include <sys/stat.h>
# include <ctime>
# include <cstdio>
# include <string>

namespace Log
{
	static std::ofstream	logbook;

	void			init(void);
	std::string		getTimeAndDate(void);
	std::ofstream		&print(std::string color);
	void			close(void);
}

# define lout		print(GREEN)
# define lerr		print(RED)
# define lwar		print(YELLOW)
# define timestamp	Log::getTimeAndDate()

#endif

