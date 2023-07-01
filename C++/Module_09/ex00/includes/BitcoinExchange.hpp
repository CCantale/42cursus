/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:37:23 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/01 17:09:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# ifndef LOG
#  define LOG

#  include "Log.hpp"

# endif

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdbool>

# define DATABASE_FILEPATH	"database/data.csv"

typedef struct s_date
{
	short	year;
	short	month;
	short	day;

	int	toInt(void)
	{
		int	sum;

		sum = this->year;
		sum = sum * 100 + this->month;
		sum = sum * 100 + this->day;
		return (sum);
	};
} t_date;

class BitcoinExchange
{
	public:
		static void	init(void);
		static bool	performExchange(std::string &input);

	private:
		static std::map<int, float>	_data;
};

#endif
