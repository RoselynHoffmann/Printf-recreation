/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoffman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:04 by rhoffman          #+#    #+#             */
/*   Updated: 2023/04/21 17:11:05 by rhoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

static int	ft_negative(int num)
{
	int	numlen;

	numlen = 0;
	if (num <= 0)
		numlen += 1;
	while (num != 0)
	{
		num = num / 10;
		numlen++;
	}
	return (numlen);
}

char	*ft_itoa(int n)
{
	char	*string;
	long	number;
	int		numlen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	number = (long)n;
	numlen = ft_negative(n);
	string = malloc((numlen + 1) * sizeof(char));
	if (!string)
		return (NULL);
	if (number < 0)
	{
		string[0] = '-';
		number = -number;
	}
	string[numlen] = '\0';
	while (number && numlen--)
	{
		string[numlen] = (number % 10) + '0';
		number = number / 10;
	}
	return (string);
}

// int main()
// {
//     int n = 123;
//     printf("%s\n", ft_itoa(n));
// }
