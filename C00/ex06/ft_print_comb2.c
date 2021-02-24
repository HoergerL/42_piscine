/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:36:29 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/13 19:53:17 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_char(int num)
{
	char digits[2];

	digits[1] = (num % 10) + '0';
	num = num / 10;
	digits[0] = num + '0';
	write(1, digits, 2);
}

void	ft_print_nbr(int num1, int num2)
{
	to_char(num1);
	write(1, " ", 1);
	to_char(num2);
	if (!(num1 == 98 && num2 == 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int num1;
	int num2;

	num1 = 0;
	num2 = 1;
	while (num1 <= 98)
	{
		while (num2 <= 99)
		{
			if (num1 >= num2)
			{
				num2++;
				continue;
			}
			ft_print_nbr(num1, num2);
			num2++;
		}
		num2 = 1;
		num1++;
	}
}

int main (){
	ft_print_comb2();
}