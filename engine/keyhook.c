/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:57:22 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/21 11:10:28 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyhook(void *param)
{
	t_eng	*eng;
	int		speed;

	speed = 2;
	eng = param;
	clear_img(eng);
	draw_map(eng);
	ray_casting(eng);
	draw_player(eng);
	if (mlx_is_key_down(eng->mlx, MLX_KEY_W))
	{
		if (!check_player_on_wall(eng, eng->player_x + cos(eng->rotation) * speed, eng->player_y + sin(eng->rotation) * speed))
		{
			eng->player_x += cos(eng->rotation) * speed;
			eng->player_y += sin(eng->rotation) * speed;
		}
		printf("UP\n");
	}
	else if (mlx_is_key_down(eng->mlx, MLX_KEY_S))
	{
		if (!check_player_on_wall(eng, eng->player_x - cos(eng->rotation) * speed, eng->player_y - sin(eng->rotation) * speed))
		{
			eng->player_x -= cos(eng->rotation) * speed;
			eng->player_y -= sin(eng->rotation) * speed;
		}
		printf("DOWN\n");
	}
	else if (mlx_is_key_down(eng->mlx, MLX_KEY_A))
	{
		if (!check_player_on_wall(eng, eng->player_x - cos(eng->rotation + M_PI / 2) * speed, eng->player_y - sin(eng->rotation + M_PI / 2) * speed))
		{
			eng->player_x -= cos(eng->rotation + M_PI / 2) * speed;
			eng->player_y -= sin(eng->rotation + M_PI / 2) * speed;
		}
		printf("GO_LEFT\n");
	}
	else if (mlx_is_key_down(eng->mlx, MLX_KEY_D))
	{
		if (!check_player_on_wall(eng, eng->player_x + cos(eng->rotation + M_PI / 2) * speed, eng->player_y + sin(eng->rotation + M_PI / 2) * speed))
		{
			eng->player_x += cos(eng->rotation + M_PI / 2) * speed;
			eng->player_y += sin(eng->rotation + M_PI / 2) * speed;
		}
		printf("GO_RIGHT\n");
	}
	else if (mlx_is_key_down(eng->mlx, MLX_KEY_LEFT))
	{
		eng->rotation -= 0.05;
		printf("TURN_LEFT\n");
	}
	else if (mlx_is_key_down(eng->mlx, MLX_KEY_RIGHT))
	{
		eng->rotation += 0.05;
		printf("TURN_RIGHT\n");
	}
	else if (mlx_is_key_down(eng->mlx, MLX_KEY_ESCAPE))
		exit(0);
	eng->rotation = normalize_angle(eng->rotation);
	//DDA(eng, eng->player_x, eng->player_y, eng->player_x + cos(eng->rotation) * 20, eng->player_y + sin(eng->rotation) * 20);
}
