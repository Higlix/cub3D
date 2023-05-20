/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:02 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:12:03 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_dda_calc_ray_data(t_game *cub, double cam_x)
{
	cub->dda.pos_map.x = (int )cub->player.pos.x;
	cub->dda.pos_map.y = (int )cub->player.pos.y;
	cub->dda.ray_dir.x = cub->player.dir.x + cub->plane.x * cam_x;
	cub->dda.ray_dir.y = cub->player.dir.y + cub->plane.y * cam_x;
	cub->dda.dis_delta.x = fabs(1 / cub->dda.ray_dir.x);
	cub->dda.dis_delta.y = fabs(1 / cub->dda.ray_dir.y);
}

void	render_dda_calc_first_step(t_game *cub)
{
	if (cub->dda.ray_dir.x < 0)
	{
		cub->dda.step_dir.x = -1;
		cub->dda.ray_len.x = (cub->player.pos.x - cub->dda.pos_map.x)
			* cub->dda.dis_delta.x;
	}
	else
	{
		cub->dda.step_dir.x = 1;
		cub->dda.ray_len.x = ((cub->dda.pos_map.x + 1) - cub->player.pos.x)
			* cub->dda.dis_delta.x;
	}
	if (cub->dda.ray_dir.y < 0)
	{
		cub->dda.step_dir.y = -1;
		cub->dda.ray_len.y = (cub->player.pos.y - cub->dda.pos_map.y)
			* cub->dda.dis_delta.y;
	}
	else
	{
		cub->dda.step_dir.y = 1;
		cub->dda.ray_len.y = ((cub->dda.pos_map.y + 1) - cub->player.pos.y)
			* cub->dda.dis_delta.y;
	}
}

void	render_dda_calc_ray_len(t_game *cub, int ray_count)
{
	bool	wall;

	wall = false;
	while (wall == false)
	{
		if (cub->dda.ray_len.x < cub->dda.ray_len.y)
		{
			cub->dda.pos_map.x += cub->dda.step_dir.x;
			cub->dda.current_ray_len = cub->dda.ray_len.x;
			cub->dda.ray_len.x += cub->dda.dis_delta.x;
			cub->dda.side = false;
		}
		else
		{
			cub->dda.pos_map.y += cub->dda.step_dir.y;
			cub->dda.current_ray_len = cub->dda.ray_len.y;
			cub->dda.ray_len.y += cub->dda.dis_delta.y;
			cub->dda.side = true;
		}
		if ((int )cub->dda.pos_map.x < cub->map.width
			&& (int )cub->dda.pos_map.y < cub->map.height)
			if (cub->map.map[cub->dda.pos_map.y][cub->dda.pos_map.x] == '1')
				wall = true;
	}
}

void	render_dda_calc_wall_height(t_game *cub, int ray_count)
{
	int		wall_data[3];
	double	perp_wall;

	if (cub->dda.side)
		perp_wall = cub->dda.ray_len.y - cub->dda.dis_delta.y;
	else
		perp_wall = cub->dda.ray_len.x - cub->dda.dis_delta.x;
	wall_data[2] = cub->height / perp_wall;
	wall_data[0] = -wall_data[2] / 2 + cub->height / 2;
	wall_data[1] = wall_data[2] / 2 + cub->height / 2;
	if (wall_data[0] < 0)
		wall_data[0] = 0;
	if (wall_data[1] >= cub->height)
		wall_data[1] = cub->height - 1;
	render_dda_wall_draw(cub, ray_count, wall_data, perp_wall);
}
