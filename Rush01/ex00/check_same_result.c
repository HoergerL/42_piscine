/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_same_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:52:33 by lhoerger          #+#    #+#             */
/*   Updated: 2021/02/21 12:53:23 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_row(int map[4][4], int offset, int horizontal_bool, int arr[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (horizontal_bool)
			arr[i] = map[offset][i];
		else
			arr[i] = map[i][offset];
		i++;
	}
}

void	calc_number_boxes(int array[4], int result[2])
{
	int cnt;
	int min;
	int max;

	max = 0;
	cnt = 0;
	min = 0;
	result[0] = 0;
	result[1] = 0;
	while (cnt < 4)
	{
		if (array[cnt] > min)
		{
			result[0]++;
			min = array[cnt];
		}
		if (array[3 - cnt] > max)
		{
			result[1]++;
			max = array[3 - cnt];
		}
		cnt++;
	}
}

int		calc_views(int map[4][4], int array_vert_hor[8][2])
{
	int check_boxes[4];
	int result[2];
	int i;
	int compare_index;

	i = 0;
	compare_index = 0;
	while (i < 8)
	{
		if (i < 4)
			set_row(map, i, 0, check_boxes);
		else
			set_row(map, i - 4, 1, check_boxes);
		calc_number_boxes(check_boxes, result);
		if (!(array_vert_hor[compare_index][0] == result[0]) || \
		!(array_vert_hor[compare_index][1] == result[1]))
			return (0);
		i++;
		compare_index++;
	}
	i = 0;
	return (1);
}

int		generate_arrays_box_check(int map[4][4], int array_vert_hor[8][2])
{
	if (calc_views(map, array_vert_hor) == 0)
	{
		return (0);
	}
	return (1);
}
