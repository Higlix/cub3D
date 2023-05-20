/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:23 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:12:23 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	render_set_texture(bool side, t_dvec ray_dir)
{
	if (side && ray_dir.y > 0)
		return (1);
	else if (side)
		return (0);
	else if (ray_dir.x > 0)
		return (2);
	return (3);
}

static int	render_texture_xcor(t_game *cub, double perp_wall, int tex_width)
{
	double	wall_x;
	int		texture_x;

	if (cub->dda.side)
		wall_x = cub->player.pos.x + perp_wall * cub->dda.ray_dir.x;
	else
		wall_x = cub->player.pos.y + perp_wall * cub->dda.ray_dir.y;
	wall_x -= floor((wall_x));
	texture_x = (int )(wall_x * (double) tex_width);
	if (cub->dda.side == false && cub->dda.ray_dir.x > 0)
		texture_x = tex_width - texture_x - 1;
	if (cub->dda.side == true && cub->dda.ray_dir.y < 0)
		texture_x = tex_width - texture_x - 1;
	return (texture_x);
}

static int	render_get_pixel(t_tex *tex, int tex_x, int tex_y)
{
	char	*dst;
	int		color;

	dst = tex->data.addr + (tex_y * tex->data.line_length + tex_x
			* (tex->data.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	render_dda_wall_draw(t_game *cub, int rc, int wall_d[3], double p_wall)
{
	int		wall_start;
	int		color;
	int		tex_id;
	int		tex[2];
	double	tex_ps[2];

	tex_id = render_set_texture(cub->dda.side, cub->dda.ray_dir);
	tex[0] = render_texture_xcor(cub, p_wall, cub->tex[tex_id].x);
	tex_ps[1] = 1.0 * cub->tex[tex_id].y / wall_d[2];
	tex_ps[0] = (wall_d[0] - cub->height / 2 + wall_d[2] / 2) * tex_ps[1];
	wall_start = wall_d[0];
	while (wall_start < wall_d[1])
	{
		tex[1] = (int ) tex_ps[0];
		color = render_get_pixel(&cub->tex[tex_id], tex[0], tex[1]);
		if (cub->dda.side == true)
			color = (color >> 1) & 8355711;
		render_pixel_put(&cub->data, cub->width - rc, wall_start, color);
		tex_ps[0] += tex_ps[1];
		wall_start++;
	}
}
