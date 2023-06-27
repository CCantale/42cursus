/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:07:20 by ccantale          #+#    #+#             */
/*   Updated: 2023/06/27 18:18:30 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Log.hpp"
# include <sstream>
# include <sys/time.h>

void	Log::init(void)
{
	mkdir(FOLDERPATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	logbook.open(LOGPATH, std::ifstream::trunc);
}

static std::string	toString(long val)
{
	std::ostringstream	os;

	os << val;
	return (os.str());
}

std::string Log::getTimeAndDate(void)
{
	struct timeval	tv;
	std::time_t	currentTime = std::time(NULL);
	std::string	timeString = std::ctime(&currentTime);
	std::string	milliString(":");
	std::string	end("]\t");
	std::string	beg("[");

	timeString.erase(timeString.length() - 6, timeString.length() - 1);
	timeString.erase(0, 11);
	gettimeofday(&tv, NULL);
	milliString += toString(tv.tv_usec / 1000)
			+ std::string("_") + toString(tv.tv_usec % 1000);
	
	return (beg + timeString + milliString + end);
}

std::ofstream	&Log::print(std::string color)
{
	logbook << color;
	return (logbook);
}

void	Log::close(void)
{
	logbook << RESET;
	logbook.close();
}

