/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:26:41 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/25 15:43:35 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

char				*ft_strcpy(char *dest, char *src)
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

char				*ft_strdup(char *src)
{
	char *cpy;

	cpy = malloc(ft_strlen(src));
	ft_strcpy(cpy, src);
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					length;
	struct s_stock_str	*pointer;
	int					i;
	int					j;

	i = 0;
	pointer = malloc(sizeof(struct s_stock_str) * (ac + 1));
	while (i < ac)
	{
		pointer[i].str = av[i];
		pointer[i].copy = ft_strdup(av[i]);
		j = 0;
		while (av[i][j] != '\0')
		{
			j++;
		}
		pointer[i].size = j;
		i++;
	}
	pointer[i].str = 0;
	return (pointer);
}
