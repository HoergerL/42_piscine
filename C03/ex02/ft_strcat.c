/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:54:10 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/17 08:35:14 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int cnt;
	int cnt2;

	cnt = 0;
	cnt2 = 0;
	while (dest[cnt] != '\0')
	{
		cnt++;
	}
	while (src[cnt2] != '\0')
	{
		dest[cnt] = src[cnt2];
		cnt++;
		cnt2++;
	}
	dest[cnt] = '\0';
	return (dest);
}
int main()
{
	char str[] = " Welt";
	char str2[] = "Hallo";
	printf("%s\n", ft_strcat(str2, str));
}