/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:28:01 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/21 20:15:10 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_perms(int perms[24][4]);
void	gen_permutations(int a[4], int fix, int end, int perms[24][4]);
int		find_res(int map[4][4], int itr[4], int perms[24][4], char *argv[]);
int		check_input(int argc, char *argv[]);

int		main(int argc, char *argv[])
{
	int row[4];
	int perms[24][4];
	int iteration[4];
	int map[4][4];

	row[0] = 1;
	row[1] = 2;
	row[2] = 3;
	row[3] = 4;
	if (check_input(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_perms(perms);
	gen_permutations(row, 0, 3, perms);
	iteration[0] = 0;
	iteration[1] = 0;
	iteration[2] = 0;
	iteration[3] = 0;
	find_res(map, iteration, perms, argv);
	return (0);
}
