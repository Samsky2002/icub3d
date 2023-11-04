/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:27:12 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/21 11:20:14 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_eng *eng, int x)
{
	double	player_to_wall_stripe;
	double	projected_ray_distance;
	double	wall_stripe_height;
	double	wall_top_pixel;
	double	wall_bottom_pixel;
	int		y;

	y = 0;
	projected_ray_distance = eng->ray.distance * cos(eng->rotation - eng->angle);
	player_to_wall_stripe = (WIDTH / 2) / tan(FOV / 2);
	wall_stripe_height = player_to_wall_stripe * (SIZE / projected_ray_distance);
	wall_top_pixel = (HEIGHT / 2) - ((int)wall_stripe_height / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	wall_bottom_pixel = (HEIGHT / 2) + ((int)wall_stripe_height / 2);
	if (wall_bottom_pixel > HEIGHT)
		wall_bottom_pixel = HEIGHT;
	y = wall_top_pixel;
	while (y < wall_bottom_pixel)
	{
		mlx_put_pixel(eng->img, x, y, ft_pixel(187, 230, 228, 255));
		y++;
	}
}

// wall_stripe_height needs to be typecasted to int
