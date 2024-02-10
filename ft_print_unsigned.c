/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:27:15 by marvin            #+#    #+#             */
/*   Updated: 2023/06/23 01:27:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"
#include "stdio.h"
#include "libft/libft.h"

static int	ft_counter(unsigned int num)
{
	int	numlen;

	numlen = 0;
	while (num != 0)
	{
		num = num / 10;
		numlen++;
	}
	return (numlen);
}

char	*ft_utoa(unsigned int n)
{
	char			*string;
	unsigned int	number;
	int				numlen;

	if (n == 0)
		return (ft_strdup("0"));
	number = n;
	numlen = ft_counter(n);
	string = malloc((numlen + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[numlen] = '\0';
	while (number && numlen--)
	{
		string[numlen] = (number % 10) + '0';
		number = number / 10;
	}
	return (string);
}

int	ft_unsigned(unsigned int n)
{
	int		len;
	char	*string;

	len = 0;
	string = ft_utoa(n);
	len = ft_string(string);
	free (string);
	return (len);
}
