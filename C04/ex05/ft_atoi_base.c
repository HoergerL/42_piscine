/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:57:52 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/24 14:02:38 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		count_minus(char *str)
{
	int cnt;
	int cnt2;
	int count_minus;

	cnt = 0;
	cnt2 = 0;
	count_minus = 0;
	while ((str[cnt] >= 9 && str[cnt] <= 13) || str[cnt] == 32)
		cnt++;
	while (str[cnt] == '-' || str[cnt] == '+')
	{
		if (str[cnt] == 45)
			count_minus++;
		cnt++;
	}
	if (str[cnt] >= '0' && str[cnt] <= '9')
		cnt2++;
	if (cnt2 == 0)
		return (0);
	else if (count_minus % 2 == 1)
		return (-1);
	else
		return (1);
}

int		ft_pow(char *base, int cnt, int begin, char *str)
{
	int vars[6];

	vars[0] = 0;
	vars[1] = 0;
	cnt = cnt - 1;
	vars[2] = 0;
	while (base[vars[2]] != '\0')
		vars[2]++;
	vars[3] = vars[2];
	while (cnt-- >= begin)
	{
		vars[2] = 0;
		while (base[vars[2]] != '\0')
		{
			if (base[vars[2]] == str[cnt + 1])
				break ;
			vars[2]++;
		}
		vars[4] = 1;
		vars[5] = vars[0]++;
		while (vars[5]-- > 0)
			vars[4] = vars[4] * vars[3];
		vars[1] = vars[1] + (vars[2] * vars[4]);
	}
	return (vars[1]);
}

int		parse_int(char *str, char *base)
{
	int cnt;
	int begin;
	int cnt2;
	int in_base;

	cnt = 0;
	cnt2 = 0;
	in_base = 0;
	while (str[cnt] == ' ' || str[cnt] == '+' || str[cnt] == '-')
		cnt++;
	begin = cnt;
	while (str[cnt] != '\0')
	{
		while (base[cnt2] != '\0')
		{
			if (str[cnt] == base[cnt2++])
				in_base = 1;
		}
		if (in_base == 0)
			break ;
		cnt2 = 0;
		cnt++;
		in_base = 0;
	}
	return (ft_pow(base, cnt, begin, str));
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

int		ft_atoi_base(char *str, char *base)
{
	int minus;
	int nb;

	if (check_break_conditions(base) == 0)
		return (0);
	minus = count_minus(str);
	nb = parse_int(str, base);
	return (nb * minus);
}

#include <stdio.h>
int        main(void)
{
    printf("%i\n", ft_atoi_base("+--+-1234db45", "0123456789"));
    printf("%i\n", ft_atoi_base("+-+-4247\v4 836483958fslndk!", "0123456789ABCDEF"));
    printf("%i\n", ft_atoi_base("+-+-01010110101fslndk!", "01"));
    printf("%i\n", ft_atoi_base("+-+2147483648", "0123456789"));
    printf("%i\n", ft_atoi_base("+--+-214748361481", "0123456789ABCDEF"));
    printf("%i\n", ft_atoi_base("+--+-000.23d45", "0123456789."));
    printf("%i\n", ft_atoi_base("+-+-000.23d45", "0123456789.1"));
    printf("%i\n", ft_atoi_base("+--+-000.23d45", "0123456789ABCDEF"));
    printf("%i\n", ft_atoi_base("+--+-000.23d45", "0123456789ABCDEF"));
    return (0);
}