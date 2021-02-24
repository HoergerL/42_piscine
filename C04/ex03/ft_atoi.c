/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:53:17 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/23 19:16:55 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_minus(char *str)
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

int	print_numb(char *str)
{
	int cnt;
	int nb;

	nb = 0;
	cnt = 0;
	while (str[cnt] < '0')
	{
		cnt++;
	}
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		nb = nb * 10 + str[cnt] - 48;
		cnt++;
	}
	return (nb);
}

int	ft_atoi(char *str)
{
	int minus;
	int nb;

	minus = count_minus(str);
	nb = print_numb(str);
	return (minus * nb);
}

int main()
{
	printf("%i\n", ft_atoi("   \n\t+--+-214748361481" ));
	//printf("%i\n", atoi("\n !  --650"));
}