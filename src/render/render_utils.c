/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:18 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:12:19 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_line_put(t_game *cub, t_ivec start, t_ivec end)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = start.x;
	pixel_y = start.y;
	while (pixels)
	{
		render_pixel_put(&cub->data, pixel_x, pixel_y, rgb(0, 0, 255, 0));
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	render_cell_put(t_game *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = x * cub->cell_size;
	while (i < (x * cub->cell_size) + cub->cell_size - 1)
	{
		j = y * cub->cell_size;
		while (j < (y * cub->cell_size) + cub->cell_size - 1)
		{
			render_pixel_put(&cub->data, i, j, color);
			j++;
		}
		i++;
	}
}

static void	render_cell_clean(t_game *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = x * cub->cell_size;
	while (i < (x * cub->cell_size) + cub->cell_size)
	{
		j = y * cub->cell_size;
		while (j < (y * cub->cell_size) + cub->cell_size)
		{
			render_pixel_put(&cub->data, i, j, color);
			j++;
		}
		i++;
	}
}

void	render_reset_image(t_game *cub, int color)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map.map[++i])
	{
		j = -1;
		while (cub->map.map[i][++j])
			render_cell_clean(cub, j + 1, i + 1, color);
	}
}
