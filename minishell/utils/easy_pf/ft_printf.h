/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:39:09 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:26:13 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//* system libraries //
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//* external modules
//# include "../../global.h"

# define PF_STDOUT_SET 0
# define PF_STDOUT_RESTORE 1

//* includes end //

//* user defined exposed functions
int					ft_printf(const char *format_string, ...);

void				pf_write(const char *c, int *count);
unsigned long long	pf_abs(long long nbr);
void				pf_put_nbr_base(long long num, const char *base,
						int base_num, int *count);

//* printf cases
// void	pf_case_str(char *str, int *count);
// void	pf_case_int(int n, int *count);
// void	pf_case_hexa(long long n, int *count);

#endif
