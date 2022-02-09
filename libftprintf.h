/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:39:52 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/09 14:21:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	call_char_department(const char *str, va_list arg);
int	text_mr_string(const char *str, va_list arg);
int	set_appointment(const char *str, va_list arg);
int	be_there_in_ten(const char *str, va_list arg);
int	because_i_said_so(const char*str, va_list arg, char *base);

#endif
