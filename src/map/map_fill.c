/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:10:30 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:10:45 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	map_extract(char *buffer, char *file_name)
{
	int	fd;
	int	active;
	int	i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (CUBERR);
	active = 1;
	i = 0;
	map_reset_buffer(buffer);
	while (active)
	{
		active = read(fd, &buffer[i], 1);
		if (active == -1)
		{
			close(fd);
			return (CUBERR);
		}
		i++;
	}
	close(fd);
	return (0);
}

static int	get_map_width(t_map *map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) > max)
			max = ft_strlen(map->map[i]);
		i++;
	}
	map->height = i;
	return (max);
}

static int	add_to_map_last_spaces(t_map *map, int max)
{
	int	i;

	i = -1;
	while (map->map[++i])
		map->map[i] = connect_map(map->map[i], max);
	return (1);
}

static int	fill_map_details(t_map *map, char **a, int *arr)
{
	int		i;
	int		j;
	char	**u;

	i = 0;
	while (i < 6)
	{
		u = ft_split(a[i], ' ');
		j = map_compare(u[0]);
		if (j == CUBERR)
			return (CUBERR);
		if (!arr[j])
		{
			arr[j]++;
			map_apply_function(map, u[1], j);
		}
		else
			return (CUBERR);
		free(u[0]);
		free(u[1]);
		free(u);
		i++;
	}
	return (1);
}

int	map_fill_map(t_map *map)
{
	char	buffer[10000];
	int		i;
	int		*checkarr;
	char	**a;

	checkarr = ft_calloc(6, 4);
	i = 0;
	if (map_extract(buffer, map->map_file) == CUBERR)
		return (CUBERR);
	a = ft_split(buffer, '\n');
	if (fill_map_details(map, a, checkarr) == CUBERR)
		return (CUBERR);
	free(checkarr);
	map->map = &a[6];
	map->a = a;
	if (buffer_check_for_multiple_nwse(map->map) == CUBERR)
		return (CUBERR);
	map->width = get_map_width(map);
	add_to_map_last_spaces(map, map->width);
	return (0);
}
