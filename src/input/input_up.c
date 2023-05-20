/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:10:20 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:10:21 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	input_key_up(int key_id, t_game *cub)
{
	if (key_id == KEY_W)
		cub->input.key_w_down = false;
	else if (key_id == KEY_S)
		cub->input.key_s_down = false;
	else if (key_id == KEY_A)
		cub->input.key_a_down = false;
	else if (key_id == KEY_D)
		cub->input.key_d_down = false;
	else if (key_id == KEY_Q)
		cub->input.key_q_down = false;
	else if (key_id == KEY_E)
		cub->input.key_e_down = false;
	return (0);
}
