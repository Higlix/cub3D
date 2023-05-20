/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:10:23 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:10:23 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_file_format(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (file[size - 1] == 'b' && file[size - 2] == 'u'
		&& file[size - 3] == 'c' && file[size - 4] == '.')
		return (0);
	return (CUBERR);
}
