/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:11:47 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:11:48 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	horizontalcheckextra(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ' && j > 0)
			j--;
		if (map[i][j] != '1')
			return (0);
	}
	return (1);
}

static int	horizontalcheck(char **map, int i, int j, int flag)
{
	while (map[++i])
	{
		flag = 0;
		j = -1;
		while (map[i][++j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1;
			if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
				flag ^= 1;
		}
	}
	return (horizontalcheckextra(map));
}

static int	verticalcheckextra(char **map)
{
	int	i;
	int	max;
	int	j;

	j = -1;
	i = 0;
	while (map[i])
		i++;
	max = i - 1;
	while (map[max][++j])
	{
		i = max;
		while (i > 0 && map[i][j] == ' ')
			i--;
		if (map[i][j] != '1')
			return (0);
	}
	return (1);
}

static int	verticalcheck(char **map, int i, int j, int flag)
{
	while (map[0][++j])
	{
		flag = 0;
		i = 0;
		while (map[i] && map[i][j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1;
			if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (!map[i + 1] && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
				flag ^= 1;
			i++;
		}
	}
	return (verticalcheckextra(map));
}

int	map_init(char *map_file, t_map *map)
{
	if (!map_file || map_file_format(map_file))
		return (CUBERR);
	map_fill_name(map_file, map->map_file);
	if (map_fill_map(map) == CUBERR)
		return (CUBERR);
	if (!verticalcheck(map->map, 0, -1, 0)
		|| !horizontalcheck(map->map, -1, 0, 0))
		return (CUBERR);
	return (0);
}
