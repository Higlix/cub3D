/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:09:59 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:10:00 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	config_set_debug(t_game *cub)
{
	int	i;

	i = -1;
	while (cub->config[++i])
		if (!ft_strncmp("DEBUG", cub->config[i], 5))
			break ;
	if (cub->config[i]
		&& (cub->config[i][6] == 't' || cub->config[i][6] == 'T'))
		cub->debug.mode = true;
	else if (cub->config[i]
		&& (cub->config[i][6] == 'f' || cub->config[i][6] == 'F'))
		cub->debug.mode = false;
	else
		return (CUBERR);
	return (0);
}

char	*config_find_value(t_game *cub, char *name)
{
	int	i;
	int	j;
	int	name_size;

	i = -1;
	j = 0;
	name_size = ft_strlen(name);
	while (cub->config[++i])
		if (!ft_strncmp(name, cub->config[i], name_size))
			break ;
	if (cub->config[i])
	{
		while (cub->config[i][j])
		{
			if (cub->config[i][j] == '=')
				return (&cub->config[i][j + 1]);
			j++;
		}
	}
	return (NULL);
}

int	config_init(t_game *cub)
{
	char	buffer[1000];

	if (config_read_file(buffer) == CUBERR)
		return (CUBERR);
	cub->config = ft_split(buffer, '\n');
	if (config_set_debug(cub) == CUBERR)
		return (CUBERR);
	if (cub->debug.mode == true)
		ft_println("\n===DEBUG-MODE===\n");
	cub->render_minimap = false;
	cub->cell_size = 16;
	cub->height = ft_atoi(config_find_value(cub, "height"));
	cub->width = ft_atoi(config_find_value(cub, "width"));
	cub->title = config_find_value(cub, "title");
	return (0);
}
