/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:09 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:12:09 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render_ray(t_game *cub)
{
	int		ray_count;
	double	cam_x;

	ray_count = -1;
	while (++ray_count < cub->width)
	{
		cam_x = 2 * ray_count / (double ) cub->width - 1;
		render_dda_calc_ray_data(cub, cam_x);
		render_dda_calc_first_step(cub);
		render_dda_calc_ray_len(cub, ray_count);
		cub->debug.ray_coll[ray_count].x = cub->player.pos.x
			+ cub->dda.ray_dir.x
			* cub->dda.current_ray_len;
		cub->debug.ray_coll[ray_count].y = cub->player.pos.y
			+ cub->dda.ray_dir.y
			* cub->dda.current_ray_len;
		render_dda_calc_wall_height(cub, ray_count);
	}
	return (0);
}
