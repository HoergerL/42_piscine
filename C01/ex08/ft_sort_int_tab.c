/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:50:18 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/14 14:51:33 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int cnt;
	int cnt_swap;

	cnt = 0;
	cnt_swap = 1;
	while (cnt_swap != 0)
	{
		cnt_swap = 0;
		while (cnt <= size - 2)
		{
			if (tab[cnt] > tab[cnt + 1])
			{
				ft_swap(&tab[cnt], &tab[cnt + 1]);
				cnt_swap++;
			}
			cnt++;
		}
		cnt = 0;
	}
}
