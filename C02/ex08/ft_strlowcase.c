/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:11:05 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/17 12:52:30 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (str[cnt] > 64 && str[cnt] <= 90)
		{
			str[cnt] = str[cnt] + 32;
		}
		cnt++;
	}
	return (str);
}
