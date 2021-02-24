/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:42:59 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/16 14:43:00 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int cnt;

	cnt = 0;
	while ((s1[cnt] != '\0' || s2[cnt] != '\0') && cnt < n)
	{
		if (s1[cnt] != s2[cnt])
		{
			return (s1[cnt] - s2[cnt]);
		}
		cnt++;
	}
	return (0);
}
