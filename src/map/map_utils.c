/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:11:01 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:11:02 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_fill_name(char *file, char map_file[96])
{
	int	i;
	int	file_name_size;

	i = 0;
	file_name_size = ft_strlen(file);
	while (i < 96)
	{
		if (i < file_name_size)
			map_file[i] = file[i];
		else
			map_file[i] = '\0';
		i++;
	}
	return (0);
}

//get floor color.
int	map_floor_color(t_map *map, char *buffer)
{
	int	i;
	int	j;
	int	rgb_color[3];

	i = 0;
	j = 0;
	while (buffer[i])
	{
		rgb_color[j++] = ft_atoi(&buffer[i]);
		while (buffer[i] != ',' && buffer[i])
			i++;
		if (!buffer[i])
			break ;
		i++;
	}
	map->f_color = rgb(0, rgb_color[0], rgb_color[1], rgb_color[2]);
	return (0);
}

//get ceiling color.
int	map_ceiling_color(t_map *map, char *buffer)
{
	int	i;
	int	j;
	int	rgb_color[3];

	i = 0;
	j = 0;
	while (buffer[i])
	{
		rgb_color[j++] = ft_atoi(&buffer[i]);
		while (buffer[i] != ',' && buffer[i])
			i++;
		if (!buffer[i])
			break ;
		i++;
	}
	map->c_color = rgb(0, rgb_color[0], rgb_color[1], rgb_color[2]);
	return (0);
}

int	buffer_check_for_multiple_nwse(char **buffer)
{
	int	i;
	int	a;
	int	j;

	i = -1;
	a = 0;
	while (buffer[++i])
	{
		j = -1;
		while (buffer[i][++j])
		{
			if (buffer[i][j] == 'N' || buffer[i][j] == 'S'
				|| buffer[i][j] == 'W' || buffer[i][j] == 'E')
				a++;
			else if (!(buffer[i][j] == ' ' || buffer[i][j] == '1'
				|| buffer[i][j] == '0'))
				return (CUBERR);
		}
	}
	if (a != 1)
		return (CUBERR);
	return (0);
}
