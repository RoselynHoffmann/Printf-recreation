/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:45:23 by marvin            #+#    #+#             */
/*   Updated: 2023/05/06 17:45:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include "stdarg.h"

int	ft_specifier(va_list arg, const char type);
int	ft_printf(const char *s, ...);
int	ft_print(int c);
int	ft_string(char *string);
int	ft_number(int n);
int	ft_unsigned(unsigned int n);
int	ft_hex(unsigned int n, char type);
int	ft_percent(void);
int	ft_pointer(unsigned long long n);

#endif
