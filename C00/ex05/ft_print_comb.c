/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:52:48 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/13 16:43:47 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_creating_numbers(int *i, int *j, int *k, char numbers[3])
{
	if (*i >= *j || *i >= *k || *j >= *k)
	{
		*k = *k + 1;
		return (1);
	}
	numbers[0] = *i + '0';
	numbers[1] = *j + '0';
	numbers[2] = *k + '0';
	write(1, numbers, 3);
	if (!(*i == 7 && *j == 8 && *k == 9))
	{
		write(1, ", ", 2);
	}
	*k = *k + 1;
	return (0);
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;
	char	numbers[3];

	i = 0;
	j = 1;
	k = 2;
	while (i <= 7)
	{
		while (j <= 8)
		{
			while (k <= 9)
			{
				ft_creating_numbers(&i, &j, &k, numbers);
			}
			k = 2;
			j++;
		}
		j = 1;
		i++;
	}
}
