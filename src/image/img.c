/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:09:26 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:09:26 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	img_load_texture(t_game *cub)
{
	cub->tex[0].data.img = mlx_xpm_file_to_image(cub->mlx,
			cub->map.so, &cub->tex[0].x, &cub->tex[0].y);
	cub->tex[1].data.img = mlx_xpm_file_to_image(cub->mlx,
			cub->map.no, &cub->tex[1].x, &cub->tex[1].y);
	cub->tex[2].data.img = mlx_xpm_file_to_image(cub->mlx,
			cub->map.we, &cub->tex[2].x, &cub->tex[2].y);
	cub->tex[3].data.img = mlx_xpm_file_to_image(cub->mlx,
			cub->map.ea, &cub->tex[3].x, &cub->tex[3].y);
	cub->tex[0].data.addr = mlx_get_data_addr(cub->tex[0].data.img,
			&cub->tex[0].data.bits_per_pixel,
			&cub->tex[0].data.line_length, &cub->tex[0].data.endian);
	cub->tex[1].data.addr = mlx_get_data_addr(cub->tex[1].data.img,
			&cub->tex[1].data.bits_per_pixel,
			&cub->tex[1].data.line_length, &cub->tex[1].data.endian);
	cub->tex[2].data.addr = mlx_get_data_addr(cub->tex[2].data.img,
			&cub->tex[2].data.bits_per_pixel,
			&cub->tex[2].data.line_length, &cub->tex[2].data.endian);
	cub->tex[3].data.addr = mlx_get_data_addr(cub->tex[3].data.img,
			&cub->tex[3].data.bits_per_pixel,
			&cub->tex[3].data.line_length, &cub->tex[3].data.endian);
	return (0);
}

int	img_init(t_game *cub)
{
	cub->data.img = mlx_new_image(cub->mlx, cub->width, cub->height);
	if (!cub->data.img)
		return (CUBERR);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
			&cub->data.line_length, &cub->data.endian);
	img_load_texture(cub);
	if (!cub->data.addr)
		return (CUBERR);
	return (0);
}
