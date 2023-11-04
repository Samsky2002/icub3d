/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:44:59 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/20 10:28:19 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	engine(t_eng *eng)
{
	eng->mlx = mlx_init(WIDTH, HEIGHT, "42 balls", true);
	eng->img = mlx_new_image(eng->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(eng->mlx, eng->img, 0, 0);
	eng->player_x = get_player_x(eng) * SIZE + (SIZE / 2);
	eng->player_y = get_player_y(eng) * SIZE + (SIZE / 2);
	eng->rotation = M_PI / 2;
	mlx_loop_hook(eng->mlx, keyhook, eng);
	mlx_loop(eng->mlx);
	mlx_terminate(eng->mlx);
}

