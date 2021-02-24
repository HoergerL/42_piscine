/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:50:25 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/17 08:41:51 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int cnt;
	unsigned int cnt2;

	cnt = 0;
	cnt2 = 0;
	while (dest[cnt] != '\0')
	{
		cnt++;
	}
	while (src[cnt2] != '\0' && cnt < size)
	{
		dest[cnt] = src[cnt2];
		cnt++;
		cnt2++;
	}
	dest[cnt] = '\0';
	return (cnt);
}
