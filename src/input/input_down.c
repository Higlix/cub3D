/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:10:14 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:10:15 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	input_movement(int key_id, t_game *cub)
{
	if (key_id == KEY_W)
		cub->input.key_w_down = true;
	else if (key_id == KEY_S)
		cub->input.key_s_down = true;
	else if (key_id == KEY_A)
		cub->input.key_a_down = true;
	else if (key_id == KEY_D)
		cub->input.key_d_down = true;
	else if (key_id == KEY_Q)
		cub->input.key_q_down = true;
	else if (key_id == KEY_E)
		cub->input.key_e_down = true;
	return (0);
}

static int	input_map_control(int key_id, t_game *cub)
{
	if (key_id == KEY_M)
	{
		if (cub->render_minimap)
			cub->render_minimap = false;
		else
			cub->render_minimap = true;
	}
	else if (key_id == KEY_X && cub->cell_size + 1 < 24)
		cub->cell_size++;
	else if (key_id == KEY_Z && cub->cell_size - 1 > 8)
		cub->cell_size--;
	return (0);
}

int	input_key_down(int key_id, t_game *cub)
{
	input_movement(key_id, cub);
	input_map_control(key_id, cub);
	if (key_id == 53)
		game_end(cub);
	return (0);
}

int	input_init(t_game *cub)
{
	cub->input.key_a_down = false;
	cub->input.key_s_down = false;
	cub->input.key_q_down = false;
	cub->input.key_e_down = false;
	cub->input.key_d_down = false;
	cub->input.key_w_down = false;
	mlx_hook(cub->win, 2, 1L << 0, input_key_down, cub);
	mlx_hook(cub->win, 3, 1L << 1, input_key_up, cub);
	mlx_hook(cub->win, 17, 0, game_end, cub);
	return (0);
}
