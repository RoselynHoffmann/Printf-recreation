/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:27:21 by marvin            #+#    #+#             */
/*   Updated: 2023/06/23 01:27:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

int	ft_print(int c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_printer(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
}

int	ft_string(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
	{
		ft_printer("(null)");
		return (6);
	}
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}

int	ft_number(int n)
{
	int		len;
	char	*string;

	len = 0;
	string = ft_itoa(n);
	len = ft_string(string);
	free (string);
	return (len);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
