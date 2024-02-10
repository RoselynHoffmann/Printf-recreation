/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoffman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:33:51 by rhoffman          #+#    #+#             */
/*   Updated: 2023/04/21 17:13:40 by rhoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '\0')
	{
		return (0);
	}
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	p = (char *) malloc ((size + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*int main()
{
	char src[] = "hello";
	printf("%s", ft_strdup(src));
} */
