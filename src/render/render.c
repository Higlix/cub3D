/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:33 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:12:34 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render_loop(t_game *cub)
{
	render_floor(cub);
	render_ceiling(cub);
	render_ray(cub);
	if (cub->render_minimap)
		render_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data.img, 0, cub->space);
	if (cub->debug.mode)
		debug_outputs(cub);
	input_mouse(cub);
	input_reg(cub);
	return (0);
}

int	render_init(t_game *cub)
{
	mlx_loop_hook(cub->mlx, render_loop, cub);
	return (0);
}
