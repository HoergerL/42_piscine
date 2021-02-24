/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:23:58 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/16 20:51:07 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strstr(char *str, char *to_find)
{
	int		cnt;
	int		cnt2;
	int		cnt3;
	char	*begin;

	cnt = 0;
	cnt2 = 0;
	while (str[cnt] != '\0')
	{
		cnt3 = cnt;
		while (str[cnt3] == to_find[cnt2])
		{
			begin = &str[cnt];
			if (to_find[cnt2 + 1] == '\0')
			{
				return (begin);
			}
			cnt2++;
			cnt3++;
		}
		cnt2 = 0;
		begin = 0;
		cnt++;
	}
	return (0);
}
