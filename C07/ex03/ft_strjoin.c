/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:55:56 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/25 10:55:58 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int		ft_strarraylen(int size, char **strs, char *sep)
{
	int index;
	int counter;
	int sep_amount;

	counter = 0;
	sep_amount = ft_strlen(sep);
	size--;
	while (size >= 0)
	{
		index = 0;
		while (strs[size][index] != '\0')
		{
			index++;
			counter++;
		}
		if (size >= 1)
			counter += sep_amount;
		size--;
	}
	size++;
	return (counter);
}

char	*ft_concatenate(int size, char **strs, char *sep, char *combined_string)
{
	int		inner_index;
	int		outer_index;
	int		inner_index2;

	inner_index2 = 0;
	outer_index = 0;
	while (outer_index < size)
	{
		inner_index = 0;
		while (strs[outer_index][inner_index] != '\0')
		{
			combined_string[inner_index2] = strs[outer_index][inner_index];
			inner_index2++;
			inner_index++;
		}
		inner_index = 0;
		while (sep[inner_index] != '\0' && outer_index < size - 1)
		{
			combined_string[inner_index2] = sep[inner_index];
			inner_index2++;
			inner_index++;
		}
		outer_index++;
	}
	return (combined_string);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*combined_string;

	if (size == 0)
	{
		combined_string = malloc(1);
		return (combined_string);
	}
	combined_string = malloc(ft_strarraylen(size, strs, sep) * sizeof(char));
	return (ft_concatenate(size, strs, sep, combined_string));
}
