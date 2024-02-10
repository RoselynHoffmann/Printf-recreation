/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:45:16 by marvin            #+#    #+#             */
/*   Updated: 2023/05/06 17:45:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(va_list arg, const char type)
{
	int	numprint;

	numprint = 0;
	if (type == 'c')
			numprint += ft_print(va_arg(arg, int));
	else if (type == 's')
			numprint += ft_string(va_arg(arg, char *));
	else if (type == 'i' || type == 'd')
			numprint += ft_number(va_arg(arg, int));
	else if (type == 'u')
		numprint += ft_unsigned(va_arg(arg, unsigned int));
	else if (type == 'x' || type == 'X')
		numprint += ft_hex(va_arg(arg, int), type);
	else if (type == 'p')
		numprint += ft_pointer(va_arg(arg, unsigned long long));
	else if (type == '%')
		numprint += ft_percent();
	return (numprint);
}

int	ft_printf(const char *s, ...)
{
	va_list		arg;
	int			numprint;
	int			i;

	numprint = 0;
	i = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			numprint += ft_specifier(arg, s[i]);
			i++;
		}
		else
		{
			numprint += ft_print(s[i]);
			i++;
		}
	}
	va_end(arg);
	return (numprint);
}

// int main()
// {
// 	ft_printf("%%");
// }