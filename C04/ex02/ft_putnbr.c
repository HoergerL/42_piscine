/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:00:13 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/17 11:00:14 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_reverse(char array[], int counter, int is_negative)
{
	char	reversed_array[counter + 1];
	int		cnt;

	cnt = 0;
	while (counter >= 0)
	{
		reversed_array[cnt] = array[counter];
		cnt++;
		counter--;
	}
	if (is_negative == 1)
	{
		write(1, "-", 1);
	}
	write(1, reversed_array, cnt);
}

void	ft_putnbr(int nb)
{
	int		is_negative;
	int		digit;
	char	number[11];
	int		counter;

	counter = -1;
	is_negative = 0;
	if (nb < 0)
		is_negative = 1;
	else if (nb == 0)
	{
		number[0] = '0';
		ft_reverse(number, 0, is_negative);
	}
	while (nb != 0)
	{
		counter++;
		digit = nb % 10;
		nb = nb / 10;
		if (digit < 0)
			digit = digit - digit - digit;
		number[counter] = digit + '0';
	}
	ft_reverse(number, counter, is_negative);
}
