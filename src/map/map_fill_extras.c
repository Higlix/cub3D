/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:08:41 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:11:34 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_reset_buffer(char *buffer)
{
	int	i;

	i = -1;
	while (++i < 10000)
		buffer[i] = '\0';
	return (0);
}

int	map_compare(char *u)
{
	if (!ft_strncmp(u, "NO", ft_strlen(u)))
		return (0);
	else if (!ft_strncmp(u, "SO", ft_strlen(u)))
		return (1);
	else if (!ft_strncmp(u, "WE", ft_strlen(u)))
		return (2);
	else if (!ft_strncmp(u, "EA", ft_strlen(u)))
		return (3);
	else if (!ft_strncmp(u, "F", ft_strlen(u)))
		return (4);
	else if (!ft_strncmp(u, "C", ft_strlen(u)))
		return (5);
	return (CUBERR);
}

int	open_map(char *u)
{
	int	fd;

	fd = open(u, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	close (fd);
	return (1);
}

int	map_apply_function(t_map *map, char *u, int funCode)
{
	int (a) = open_map(u);
	if (!u)
		return (CUBERR);
	if (funCode == 0 && a)
		map->no = ft_strdup(u);
	else if (funCode == 1 && a)
		map->so = ft_strdup(u);
	else if (funCode == 2 && a)
		map->we = ft_strdup(u);
	else if (funCode == 3 && a)
		map->ea = ft_strdup(u);
	else if (funCode == 4)
		map_floor_color(map, u);
	else if (funCode == 5)
		map_ceiling_color(map, u);
	else
		return (CUBERR);
	return (1);
}

char	*connect_map(char *map, int max)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * max + 1);
	while (map[i])
	{
		ret[i] = map[i];
		i++;
	}
	free(map);
	while (i < max)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
