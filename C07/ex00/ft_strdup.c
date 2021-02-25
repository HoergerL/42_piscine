/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:26:41 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/24 16:27:26 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_strcpy(char *dest, char *src)
{
	int size;
	int cnt;

	size = ft_strlen(src) + 1;
	cnt = 0;
	while (cnt < size)
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *cpy;

	cpy = malloc(ft_strlen(src));
	ft_strcpy(cpy, src);
	return (cpy);
}
