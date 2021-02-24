/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:17:17 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/16 10:17:40 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (str[cnt] < 65 || (str[cnt] > 90 && str[cnt] < 97) || str[cnt] > 122)
		{
			return (0);
		}
		cnt++;
	}
	return (1);
}
