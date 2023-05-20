/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:10:03 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:10:03 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	debug_output_pdata(t_game *cub)
{
	printf("________PLAYER_DATA________\n");
	printf("PLAYER_DIRECTION_x ( %lf )\n", cub->player.dir.x);
	printf("PLAYER_DIRECTION_y ( %lf )\n\n", cub->player.dir.y);
	printf("PLAYER_POSITION_x ( %lf )\n", cub->player.pos.x);
	printf("PLAYER_POSITION_y ( %lf )\n\n", cub->player.pos.y);
}

void	debug_output_cdata(t_game *cub)
{
	printf("________CAMERA_DATA________\n");
	printf("CAMERA_PLANE_x ( %lf )\n", cub->plane.x);
	printf("CAMERA_PLANE_y ( %lf )\n\n", cub->plane.y);
}

void	debug_outputs(t_game *cub)
{
	debug_output_pdata(cub);
	debug_output_cdata(cub);
}
