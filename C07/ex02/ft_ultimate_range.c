/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:23:55 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/24 16:25:37 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int range_size;
	int *pointer;
	int i;

	range_size = max - min;
	if (!(range))
	{
		return (-1);
	}
	if (range_size <= 0)
	{
		range = NULL;
		return (0);
	}
	pointer = malloc(sizeof(pointer) * range_size);
	*range = pointer;
	i = 0;
	while (i < range_size)
	{
		pointer[i] = i + min;
		i++;
	}
	return (range_size);
}
