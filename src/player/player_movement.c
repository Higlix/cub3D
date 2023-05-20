/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:11:54 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:11:54 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	player_move_up(t_game *cub)
{
	double (px) = cub->player.pos.x;
	double (py) = cub->player.pos.y;
	double (dx) = cub->player.dir.x;
	double (dy) = cub->player.dir.y;
	if (cub->map.map[(int )py][(int )(px + dx * MV_SPEED)] == '0')
		cub->player.pos.x += cub->player.dir.x * MV_SPEED;
	if (cub->map.map[(int )(py + dy * MV_SPEED)][(int )px] == '0')
		cub->player.pos.y += cub->player.dir.y * MV_SPEED;
	return (0);
}

int	player_move_down(t_game *cub)
{
	double (px) = cub->player.pos.x;
	double (py) = cub->player.pos.y;
	double (dx) = cub->player.dir.x;
	double (dy) = cub->player.dir.y;
	if (cub->map.map[(int )py][(int )(px - dx * MV_SPEED)] == '0')
		cub->player.pos.x -= cub->player.dir.x * MV_SPEED;
	if (cub->map.map[(int )(py - dy * MV_SPEED)][(int )px] == '0')
		cub->player.pos.y -= cub->player.dir.y * MV_SPEED;
	return (0);
}

int	player_move_lr(t_game *cub, bool left)
{
	double (px) = cub->player.pos.x;
	double (py) = cub->player.pos.y;
	double (dx) = cub->player.dir.x;
	double (dy) = cub->player.dir.y;
	if (left)
	{
		if (cub->map.map[(int )(py - dx * MV_SPEED)][(int )px] == '0')
			cub->player.pos.y -= cub->player.dir.x * MV_SPEED;
		py = cub->player.pos.y;
		if (cub->map.map[(int )py][(int )(px + dy * MV_SPEED)] == '0')
			cub->player.pos.x += cub->player.dir.y * MV_SPEED;
	}
	else
	{
		if (cub->map.map[(int )py][(int )(px - dy * MV_SPEED)] == '0')
		cub->player.pos.x -= cub->player.dir.y * MV_SPEED;
		if (cub->map.map[(int )(py + dx * MV_SPEED)][(int )px] == '0')
		cub->player.pos.y += cub->player.dir.x * MV_SPEED;
	}
	return (0);
}

int	player_rotate_right(t_game *cub)
{
	double (old_x) = cub->player.dir.x;
	double (old) = cub->plane.x;
	cub->player.dir.x = cub->player.dir.x * cos(RO_SPEED)
		- cub->player.dir.y * sin(RO_SPEED);
	cub->player.dir.y = old_x * sin(RO_SPEED)
		+ cub->player.dir.y * cos(RO_SPEED);
	cub->plane.x = cub->plane.x * cos(RO_SPEED) - cub->plane.y * sin(RO_SPEED);
	cub->plane.y = old * sin(RO_SPEED) + cub->plane.y * cos(RO_SPEED);
	return (0);
}

int	player_rotate_left(t_game *cub)
{
	double (old_x) = cub->player.dir.x;
	double (old) = cub->plane.x;
	cub->player.dir.x = cub->player.dir.x * cos(-RO_SPEED)
		- cub->player.dir.y * sin(-RO_SPEED);
	cub->player.dir.y = old_x * sin(-RO_SPEED)
		+ cub->player.dir.y * cos(-RO_SPEED);
	cub->plane.x = cub->plane.x * cos(-RO_SPEED)
		- cub->plane.y * sin(-RO_SPEED);
	cub->plane.y = old * sin(-RO_SPEED) + cub->plane.y * cos(-RO_SPEED);
	return (0);
}
