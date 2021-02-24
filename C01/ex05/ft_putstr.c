/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:08:13 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/16 15:33:54 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	write(1, str, cnt);
}

int		main(void)
{
	char str[] = "Hello\n";
	char *str2;
	
	str2 = "Bye\n";
	ft_putstr(str);
	ft_putstr(str2);
	return (0);
}
