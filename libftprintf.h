/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:39:52 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/11 17:53:28 by ccantale         ###   ########.fr       */
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
int	can_u_handle_dees(const char *str, va_list arg, char flag);
int	because_i_said_so(const char*str, va_list arg, char *base);

#endif
