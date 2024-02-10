/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:00:39 by marvin            #+#    #+#             */
/*   Updated: 2023/06/23 21:00:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"
#include "libft/libft.h"

static int	ft_counter(unsigned int num)
{
	int	numlen;

	numlen = 0;
	while (num != 0)
	{
		num = num / 16;
		numlen++;
	}
	return (numlen);
}

char	*ft_htoa(unsigned int n, char type)
{
	char	*string;
	int		numlen;
	char	remainder;

	if (n == 0)
		return (ft_strdup("0"));
	numlen = ft_counter(n);
	string = malloc((numlen + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[numlen] = '\0';
	while (n && numlen--)
	{
		remainder = n % 16;
		if (remainder < 10)
			string[numlen] = remainder + '0';
		else if (type == 'x')
			string[numlen] = remainder - 10 + 'a';
		else if (type == 'X')
			string[numlen] = remainder - 10 + 'A';
		n = n / 16;
	}
	return (string);
}

int	ft_hex(unsigned int n, char type)
{
	int		len;
	char	*string;

	len = 0;
	string = ft_htoa(n, type);
	len = ft_string(string);
	free (string);
	return (len);
}
