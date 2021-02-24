/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:08:23 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/17 12:53:45 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int cnt;

	cnt = 0;
	if (str[cnt] > 96 && str[cnt] < 123)
		str[cnt] = str[cnt] - 32;
	cnt++;
	while (str[cnt] != '\0')
	{
		if (str[cnt] > 64 && str[cnt] < 91)
			str[cnt] = str[cnt] + 32;
		cnt++;
	}
	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (str[cnt] > 96 && str[cnt] < 123)
			if (!(str[cnt - 1] > 96 && str[cnt - 1] < 123))
				if (!(str[cnt - 1] >= 48 && str[cnt - 1] < 58))
					if (!(str[cnt - 1] > 64 && str[cnt - 1] < 91))
						str[cnt] = str[cnt] - 32;
		cnt++;
	}
	return (str);
}
