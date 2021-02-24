/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:18:53 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/14 18:33:35 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int cnt;
	int cnt2;

	cnt = 0;
	cnt2 = size - 1;
	while (cnt < cnt2)
	{
		ft_swap(&tab[cnt], &tab[cnt2]);
		cnt++;
		cnt2--;
	}
}
