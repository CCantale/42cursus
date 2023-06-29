/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:37:23 by ccantale          #+#    #+#             */
/*   Updated: 2023/06/29 20:16:17 by ccantale         ###   ########.fr       */
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
# include <fstream>

# define DATABASE_FILEPATH	"database/data.csv"

typedef struct s_date
{
	short	year;
	short	month;
	short	day;
} t_date;

class BitcoinExchange
{
	public:
		static void	init(void);
		static void	performExchange(std::string &input);

	private:
		static std::map<float, t_date>	_data;
};

#endif
