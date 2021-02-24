/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:04:19 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/17 12:54:27 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(char c)
{
	if (c < 32 || c >= 127)
		return (0);
	return (1);
}

void	print_hex(unsigned char c)
{
	char left_digit;
	char right_digit;

	right_digit = c % 16;
	left_digit = c / 16;
	write(1, "\\", 1);
	if (left_digit < 10)
	{
		left_digit = left_digit + 48;
	}
	else
	{
		left_digit = left_digit + 87;
	}
	if (right_digit < 10)
	{
		right_digit = right_digit + 48;
	}
	else
	{
		right_digit = right_digit + 87;
	}
	write(1, &left_digit, 1);
	write(1, &right_digit, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (ft_str_is_printable(str[cnt]))
		{
			write(1, &str[cnt], 1);
		}
		else
		{
			print_hex((unsigned char)str[cnt]);
		}
		cnt++;
	}
}
