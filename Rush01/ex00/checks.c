/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:05:01 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/21 10:56:08 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		generate_arrays_box_check(int map[4][4], int array_vert_hor[8][2]);

void	convert_user_input(char *argv[], int array_vert_hor[8][2])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (31 - 8))
	{
		if (i == 8)
			i += 8;
		*((int *)array_vert_hor + j) = (argv[1][i] - '0');
		j++;
		*((int *)array_vert_hor + j) = (argv[1][i + 8] - '0');
		i += 2;
		j++;
	}
}

int		check_same_numbers(int map[4][4])
{
	int cnt;
	int cnt2;
	int cnt3;

	cnt = 0;
	cnt2 = 0;
	cnt3 = 1;
	while (cnt < 4)
	{
		cnt2 = 0;
		while (cnt2 < 3)
		{
			cnt3 = cnt2 + 1;
			while (cnt3 < 4)
			{
				if (map[cnt2][cnt] == map[cnt3][cnt])
					return (0);
				cnt3++;
			}
			cnt2++;
		}
		cnt++;
	}
	return (1);
}

int		checks(int map[4][4], char *argv[])
{
	int array_vert_hor[8][2];

	convert_user_input(argv, array_vert_hor);
	if (check_same_numbers(map) == 0)
		return (0);
	if (generate_arrays_box_check(map, array_vert_hor) == 0)
		return (0);
	return (1);
}
