/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:00:49 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/18 11:05:39 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_player_x(t_eng *eng)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = eng->parser.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == eng->parser.player)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_player_y(t_eng *eng)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = eng->parser.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == eng->parser.player)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}
