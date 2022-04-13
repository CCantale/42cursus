/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:39:52 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/23 17:38:10 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

int		ft_printf(const char *str, ...);
int		call_char_department(const char *str, va_list arg);
int		text_mr_string(const char *str, va_list arg);
int		set_appointment(const char *str, va_list arg);
int		can_u_handle_dees(const char *str, va_list arg, char flag);
int		even_less_than_that(unsigned int num);
int		because_i_said_so(const char *str, va_list arg, char *base);
void	you_re_holding_it_upside_down(char *str, int num);
char	*i_dont_like_it_change_it(const char *str, char before, char after);
int		what_do_you_mean_ex_assistant(const char *str, va_list arg, char *base);
int		miss_me(va_list arg);

#endif
