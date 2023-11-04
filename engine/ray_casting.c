/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:10:34 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/21 10:53:21 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = 2 * M_PI + angle;
	return (angle);
}

void	vision(t_eng *eng)
{
	eng->up = 0;
	eng->down = 0;
	eng->left = 0;
	eng->right = 0;
	if (eng->angle > 0 && eng->angle < M_PI)
	{
		eng->down = 1;
	}
	else
	{
		eng->up = 1;
	}
	if (eng->angle > 1.5 * M_PI || eng->angle < 0.5 * M_PI)
	{
		eng->right = 1;
	}
	else
	{
		eng->left = 1;
	}
}


void	vertical_raycast(t_eng *eng)
{
	double	x_intersec;
	double	y_intersec;
	double	x_step;
	double	y_step;
	double	new_x;
	double	new_y;
	
	eng->ray.vert_hit = 0;
	eng->ray.vert_wall_hit_x = 0;
	eng->ray.vert_wall_hit_y = 0;
	eng->ray.vert_distance = 0;
	x_intersec = floor(eng->player_x / SIZE) * SIZE;
	if (eng->right)
		x_intersec += SIZE;
	y_intersec = eng->player_y + (x_intersec - eng->player_x) * tan(eng->angle);
	x_step = SIZE;
	if (eng->left)
		x_step *= -1;
	y_step = SIZE * tan(eng->angle);
	if (eng->up && y_step > 0)
		y_step *= -1;
	else if (eng->down && y_step < 0)
		y_step *= -1;
	new_x = x_intersec;
	new_y = y_intersec;
	if (eng->left)
		new_x--;
	while (new_x < WIDTH && new_x >= 0 && new_y < HEIGHT && new_y > 0)
	{
		if (check_player_on_wall(eng, new_x, new_y))
		{
			eng->ray.vert_wall_hit_x = new_x;
			eng->ray.vert_wall_hit_y = new_y;
			eng->ray.vert_hit = 1;
			break ;
		}
		new_x += x_step;
		new_y += y_step;
	}
	if (eng->ray.vert_hit)
		eng->ray.vert_distance = distance_between_points(eng->player_x, eng->player_y, new_x, new_y);
	else
		eng->ray.vert_distance = 100000;
}

void	horizontal_raycast(t_eng *eng)
{
	double	x_intersec;
	double	y_intersec;
	double	x_step;
	double	y_step;
	double	new_x;
	double	new_y;

	eng->ray.horiz_hit = 0;
	eng->ray.horiz_wall_hit_x = 0;
	eng->ray.horiz_wall_hit_y = 0;
	eng->ray.horiz_distance = 0;
	y_intersec = floor(eng->player_y / SIZE) * SIZE;
	if (eng->down)
		y_intersec += SIZE;
	x_intersec = eng->player_x + (y_intersec - eng->player_y) / tan(eng->angle);
	y_step = SIZE;
	if (eng->up)
		y_step *= -1;
	x_step = SIZE / tan(eng->angle);
	if (eng->left && x_step > 0)
		x_step *= -1;
	else if (eng->right && x_step < 0)
		x_step *= -1;
	new_x = x_intersec;
	new_y = y_intersec;
	if (eng->up)
		new_y--;
	while (new_x < WIDTH && new_x >= 0 && new_y < HEIGHT && new_y > 0)
	{
		if (check_player_on_wall(eng, new_x, new_y))
		{
			eng->ray.horiz_wall_hit_x = new_x;
			eng->ray.horiz_wall_hit_y = new_y;
			eng->ray.horiz_hit = 1;
			break ;
		}
		new_x += x_step;
		new_y += y_step;
	}
	if (eng->ray.horiz_hit)
		eng->ray.horiz_distance = distance_between_points(eng->player_x, eng->player_y, new_x, new_y);
	else
		eng->ray.horiz_distance = 1000000;
}

void	cast_rays(t_eng *eng)
{
	vision(eng);
	horizontal_raycast(eng);
	vertical_raycast(eng);
	if (eng->ray.horiz_distance >= eng->ray.vert_distance)
	{
		eng->ray.wall_hit_x = eng->ray.vert_wall_hit_x;
		eng->ray.wall_hit_y = eng->ray.vert_wall_hit_y;
		eng->ray.distance = eng->ray.vert_distance;
	}
	else
	{
		eng->ray.wall_hit_x = eng->ray.horiz_wall_hit_x;
		eng->ray.wall_hit_y = eng->ray.horiz_wall_hit_y;
		eng->ray.distance = eng->ray.horiz_distance;
	}
	if (eng->ray.wall_hit_x < WIDTH && eng->ray.wall_hit_x >= 0 && \
			eng->ray.wall_hit_y < HEIGHT && eng->ray.wall_hit_y > 0)
		DDA(eng, eng->player_x, eng->player_y, eng->ray.wall_hit_x, eng->ray.wall_hit_y);
}

void	vision_printer(t_eng *eng)
{
	if (eng->right)
		printf("right\n");
	if (eng->left)
		printf("left\n");
	if (eng->up)
		printf("up\n");
	if (eng->down)
		printf("down\n");
}

void	ray_casting(t_eng *eng)
{
	int		x;

	x = 0;
	//init_ray_vars(eng);
	eng->angle = eng->rotation - (FOV / 2);
	while (x < WIDTH)
	{
		eng->angle = normalize_angle(eng->angle);
		cast_rays(eng);
		render(eng, x);
		eng->angle += FOV / WIDTH;
		x++;
	}
}
