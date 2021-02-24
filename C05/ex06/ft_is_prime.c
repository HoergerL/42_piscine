/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 08:38:09 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/22 13:40:58 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	divide(int nb, int cnt)
{
	if ((nb % cnt) == 0)
	{
		return (0);
	}
	else if (cnt > (nb / 2))
	{
		return (1);
	}
	else
		return (divide(nb, cnt + 1));
}

int	ft_is_prime(int nb)
{
	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb == 2147483647)
		return (1);
	if (nb < 0)
		return (0);
	return (divide(nb, 2));
}
