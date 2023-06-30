/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:37:23 by ccantale          #+#    #+#             */
/*   Updated: 2023/06/30 18:28:16 by ccantale         ###   ########.fr       */
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
	/*int	sum(const struct s_date &date) const
	{
		int	sum;

		sum = date.year;
		sum = sum * 100 + date.month;
		sum = sum * 100 + date.day;
		return (sum);
	};

	bool	operator<(const struct s_date &rhs) const
	{
		int	lhs_sum = this->sum(*this);
		int	rhs_sum = this->sum(rhs);

		if (lhs_sum < rhs_sum)
			return (true);
		else
			return (false);

	};*/
} t_date;

class BitcoinExchange
{
	public:
		static void	init(void);
		static void	performExchange(std::string &input);

	private:
		static std::map<int, float>	_data;
};

#endif
