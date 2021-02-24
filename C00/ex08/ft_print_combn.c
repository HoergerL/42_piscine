/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:51:06 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/16 08:50:54 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_biggest_nbr(int n)
{
	int i;
	int highest_possible_number;
	int j;
	int cnt;
	int diff;

	i = 0;
	j = 0;
	highest_possible_number = 0;
	cnt = n - 1;
	diff = 0;
	while (i < n)
	{
		highest_possible_number = 10 * highest_possible_number + 9;
		i++;
	}
	while (j < n)
	{
		diff = 10 * diff + cnt;
		j++;
		cnt--;
	}
	return (highest_possible_number - diff);
}

void	ft_reverse(char array[], int counter, int n, int flag_highest_nb)
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
	if (n > cnt)
	{
		write(1, "0", 1);
	}
	write(1, reversed_array, cnt);
	if (flag_highest_nb == 0)
	{
		write(1, ", ", 2);
	}
}

void	ft_putnbr(int nb, int n)
{
	int		digit;
	char	number[11];
	int		counter;
	int		flag_highest_nb;

	counter = -1;
	flag_highest_nb = 0;
	if (get_biggest_nbr(n) == nb)
	{
		flag_highest_nb = 1;
	}
	while (nb != 0)
	{
		counter++;
		digit = nb % 10;
		nb = nb / 10;
		if (digit < 0)
		{
			digit = digit - digit - digit;
		}
		number[counter] = digit + '0';
	}
	ft_reverse(number, counter, n, flag_highest_nb);
}

int		check_same_nbrs(int length, int nb)
{
	int digits[length];
	int digit;
	int counter;
	int counter2;

	counter = 0;
	counter2 = 0;
	while (counter++ <= length + 1)
		digits[counter - 1] = 10;
	counter = -1;
	while (nb > 0)
	{
		counter++;
		digit = nb % 10;
		nb = nb / 10;
		while (counter2 < length)
		{
			if (digit >= digits[counter2])
				return (0);
			counter2++;
		}
		counter2 = 0;
		digits[counter] = digit;
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int counter_create_current_number;
	int current_number;
	int check;
	int cnt;
	int biggest_nbr;

	counter_create_current_number = 0;
	current_number = 0;
	cnt = 0;
	biggest_nbr = get_biggest_nbr(n);
	while (counter_create_current_number < n)
	{
		current_number = 10 * current_number + counter_create_current_number;
		counter_create_current_number++;
	}
	while (current_number <= biggest_nbr)
	{
		check = 	(n, current_number);
		if (check == 1)
		{
			ft_putnbr(current_number, n);
		}
		current_number++;
	}
}
