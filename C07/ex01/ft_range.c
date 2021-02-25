/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:25:45 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/24 16:26:15 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int range;
	int i;

	range = max - min;
	if (range <= 0)
		return (NULL);
	arr = malloc(sizeof(arr) * range);
	i = min;
	while (i < max)
	{
		arr[i - min] = i;
		i++;
	}
	return (arr);
}
