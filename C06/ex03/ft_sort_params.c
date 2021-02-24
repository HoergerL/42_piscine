/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:40:03 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/23 10:42:01 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int cnt;

	cnt = 0;
	while (s1[cnt] != '\0' || s2[cnt] != '\0')
	{
		if (s1[cnt] != s2[cnt])
		{
			return (s1[cnt] - s2[cnt]);
		}
		cnt++;
	}
	return (0);
}

void	ft_swap(char *argv[], int i)
{
	char *temp;

	temp = argv[i];
	argv[i] = argv[i + 1];
	argv[i + 1] = temp;
}

void	ft_print(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argc > i)
	{
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int i;
	int swap_cnt;

	i = 1;
	swap_cnt = 1;
	while (swap_cnt)
	{
		swap_cnt = 0;
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_swap(argv, i);
				swap_cnt = 1;
			}
			i++;
		}
	}
	ft_print(argc, argv);
	return (0);
}
