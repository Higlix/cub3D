/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:11:59 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:12:00 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	player_ori_set(double *fov, double *dir, char ori)
{
	if (ori == 'S' || ori == 'E')
	{
		*dir = 1;
		*fov = 0.66;
	}
	else if (ori == 'N' || ori == 'W')
	{
		*dir = -1;
		*fov = -0.66;
	}
	return (0);
}

static int	player_ori(t_game *cub, int x, int y, char ori)
{
	double	dir;
	double	fov;

	cub->player.pos.x = x;
	cub->player.pos.y = y;
	cub->map.map[y][x] = '0';
	player_ori_set(&fov, &dir, ori);
	if (ori == 'N' || ori == 'S')
	{
		cub->player.dir.y = dir;
		cub->plane.x = fov;
	}
	else if (ori == 'W' || ori == 'E')
	{
		cub->player.dir.x = dir;
		cub->plane.y = -fov;
	}
	return (0);
}

static int	player_find_position(t_game *cub)
{
	char	**map;
	int		cor[2];

	cor[X] = 0;
	cor[Y] = 0;
	map = cub->map.map;
	cub->player.pos.x = -1;
	while (map[cor[Y]])
	{
		cor[X] = 0;
		while (map[cor[Y]][cor[X]])
		{
			if (map[cor[Y]][cor[X]] == 'N' || map[cor[Y]][cor[X]] == 'S'
			|| map[cor[Y]][cor[X]] == 'W' || map[cor[Y]][cor[X]] == 'E')
			{
				player_ori(cub, cor[X], cor[Y], map[cor[Y]][cor[X]]);
				break ;
			}
			cor[X]++;
		}
		cor[Y]++;
	}
	if (cub->player.pos.x == -1)
		return (CUBERR);
	return (0);
}

int	player_init(t_game *cub)
{
	cub->player.dir.x = 0;
	cub->player.dir.y = 0;
	cub->plane.x = 0;
	cub->plane.y = 0;
	if (player_find_position(cub) == CUBERR)
		return (CUBERR);
	return (0);
}
