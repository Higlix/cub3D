/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:08:34 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:16:59 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	game_end(t_game *cub)
{
	int	i;

	i = 0;
	while (cub->map.a[i])
		free(cub->map.a[i++]);
	free(cub->map.a);
	i = 0;
	while (cub->config[i])
		free(cub->config[i++]);
	free(cub->config);
	free(cub->map.no);
	free(cub->map.ea);
	free(cub->map.so);
	free(cub->map.we);
	mlx_destroy_image(cub->mlx, cub->tex[0].data.img);
	mlx_destroy_image(cub->mlx, cub->tex[1].data.img);
	mlx_destroy_image(cub->mlx, cub->tex[2].data.img);
	mlx_destroy_image(cub->mlx, cub->tex[3].data.img);
	mlx_destroy_image(cub->mlx, cub->data.img);
	free(cub);
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}

int	game_start(char *map_file)
{
	t_game	*cub;

	cub = (t_game *) malloc(sizeof(t_game));
	if (config_init(cub) == CUBERR)
		return (CUBERR);
	if (map_init(map_file, &cub->map) == CUBERR)
		return (CUBERR);
	if (win_init(cub) == CUBERR)
		return (CUBERR);
	if (img_init(cub) == CUBERR)
		return (CUBERR);
	if (input_init(cub) == CUBERR)
		return (CUBERR);
	if (render_init(cub) == CUBERR)
		return (CUBERR);
	if (player_init(cub) == CUBERR)
		return (CUBERR);
	mlx_mouse_hide();
	mlx_loop(cub->mlx);
	return (0);
}
