/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findsolution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:57:52 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/21 10:56:23 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		checks(int map[4][4], char *argv[]);

void	set_map(int map[4][4], int iteration[4], int perms[24][4])
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < 4)
	{
		while (col < 4)
		{
			map[row][col] = perms[iteration[row]][col];
			col++;
		}
		col = 0;
		row++;
	}
}

void	print_map(int map[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			c = map[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}

void	increment(int iteration[4])
{
	int i;
	int carry;

	i = 0;
	carry = 1;
	while (i < carry)
	{
		if (iteration[i] == 23)
		{
			carry++;
		}
		iteration[i] = (iteration[i] + 1) % 24;
		i++;
	}
}

int		find_res(int map[4][4], int itr[4], int perms[24][4], char *argv[])
{
	int i;

	i = 0;
	while (i < 331776)
	{
		set_map(map, itr, perms);
		if (checks(map, argv))
		{
			print_map(map);
			return (0);
		}
		increment(itr);
		i++;
	}
	write(1, "Error\n", 6);
	return (1);
}
