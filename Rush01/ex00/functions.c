/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:51:05 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/21 10:56:29 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_perms(int perms[24][4])
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 24)
	{
		while (y < 4)
		{
			perms[x][y] = 0;
			y++;
		}
		y = 0;
		x++;
	}
}

void	swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	gen_permutations(int a[4], int fix, int end, int perms[24][4])
{
	int i;

	i = 0;
	if (fix == end)
	{
		while (perms[i][0] != 0)
			i++;
		perms[i][0] = a[0];
		perms[i][1] = a[1];
		perms[i][2] = a[2];
		perms[i][3] = a[3];
		i = 0;
	}
	else
	{
		i = fix;
		while (i <= end)
		{
			swap(&a[fix], &a[i]);
			gen_permutations(a, fix + 1, end, perms);
			swap(&a[fix], &a[i]);
			i++;
		}
	}
}

int		check_input(int argc, char *argv[])
{
	int		i;
	char	c;

	i = 0;
	if (argc != 2)
	{
		return (0);
	}
	while (i < 31)
	{
		c = argv[1][i];
		if (((i % 2) == 1 && c != ' '))
		{
			return (0);
		}
		if ((i % 2) == 0 && (c < '1' || c > '4'))
		{
			return (0);
		}
		i++;
	}
	if (argv[1][i] != '\0')
		return (0);
	return (1);
}
