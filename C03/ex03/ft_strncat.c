/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:14:24 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/16 15:14:25 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int cnt;
	unsigned int cnt2;

	cnt = 0;
	cnt2 = 0;
	while (dest[cnt] != '\0')
	{
		cnt++;
	}
	while (src[cnt2] != '\0' && cnt2 < nb)
	{
		dest[cnt] = src[cnt2];
		cnt++;
		cnt2++;
	}
	dest[cnt] = '\0';
	return (dest);
}
