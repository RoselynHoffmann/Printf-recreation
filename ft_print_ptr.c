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

static int	ptr_len(unsigned long long num)
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

char	*ft_ptoa(unsigned long long n)
{
	char	*string;
	int		numlen;
	char	remainder;

	if (n == 0)
		return (ft_strdup("0"));
	numlen = ptr_len(n);
	string = malloc((numlen + 4) * sizeof(char));
	if (!string)
		return (NULL);
	string[numlen + 2] = '\0';
	ft_strlcpy(string, "0x", numlen + 4);
	while (n && numlen--)
	{
		remainder = n % 16;
		if (remainder < 10)
			string[numlen + 2] = remainder + '0';
		else
			string[numlen + 2] = remainder - 10 + 'a';
		n = n / 16;
	}
	return (string);
}

int	ft_pointer(unsigned long long n)
{
	int		len;
	char	*string;

	if (n == 0)
	{
		ft_string("0x0");
		return (3);
	}
	len = 0;
	string = ft_ptoa(n);
	len = ft_string(string);
	free (string);
	return (len);
}
