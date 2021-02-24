/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:28:51 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/24 10:41:39 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		check_break_conditions(char *base)
{
	int cnt;
	int cnt2;

	cnt = 0;
	cnt2 = 1;
	while (base[cnt] != '\0')
	{
		if (base[cnt] == '+' || base[cnt] == '-')
			return (0);
		while (base[cnt2] != '\0')
		{
			if (base[cnt] == base[cnt2])
			{
				return (0);
			}
			cnt2++;
		}
		cnt++;
		cnt2 = cnt + 1;
	}
	if (cnt < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		nbr_base;
	int		digit;
	int		cnt;
	char	translate[11];
	int		is_negative;

	cnt = -1;
	is_negative = 0;
	if (check_break_conditions(base) == 1)
	{
		if (nbr < 0)
			is_negative = 1;
		else if (nbr == 0)
			write(1, "0", 1);
		nbr_base = ft_strlen(base);
		while (nbr != 0)
		{
			digit = nbr % nbr_base;
			if (is_negative == 1)
				digit = digit * -1;
			nbr = nbr / nbr_base;
			translate[++cnt] = base[digit];
		}
		ft_reverse(translate, cnt, is_negative);
	}
}

int main()
{
	ft_putnbr_base(-2147483648, "01");
}