/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:10:17 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:10:18 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	input_mouse(t_game *cub)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub->win, &x, &y);
	if (x > cub->width / 2)
		player_rotate_right(cub);
	else if (x < cub->width / 2)
		player_rotate_left(cub);
	mlx_mouse_move(cub->win, cub->width / 2, cub->height / 2);
	return (0);
}

int	input_reg(t_game *cub)
{
	if (cub->input.key_w_down == true)
		player_move_up(cub);
	if (cub->input.key_s_down == true)
		player_move_down(cub);
	if (cub->input.key_a_down == true)
		player_move_lr(cub, true);
	if (cub->input.key_d_down == true)
		player_move_lr(cub, false);
	if (cub->input.key_q_down == true)
		player_rotate_left(cub);
	if (cub->input.key_e_down == true)
		player_rotate_right(cub);
	return (0);
}
