/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:58:28 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/20 11:08:37 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_img(t_eng *eng)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(eng->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_player(t_eng *eng)
{
	mlx_put_pixel(eng->img, eng->player_x, eng->player_y, ft_pixel(0, 0, 0, 255));
}

void	draw_map(t_eng *eng)
{
	char	**map;
	int		i;
	int		j;
	int		x;
	int		y;
	int		k;

	map = eng->parser.map;
	i = 0;
	x = 0;
	y = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		y = 0;
		while (map[i][j])
		{
			y = i * SIZE;
			while (y < (SIZE * i) + SIZE)
			{
				x = j * SIZE;
				while (x < (SIZE * j) + SIZE)
				{
					if (map[i][j] == '1') 
						mlx_put_pixel(eng->img, x, y, ft_pixel(20, 50, 70, 255));
					else if (map[i][j] == '0' || map[i][j] == eng->parser.player)
						mlx_put_pixel(eng->img, x, y, ft_pixel(200, 100, 70, 255));
					x++;
				}
				y++;
			}
			j++;
		}
		i++;
	}
}

uint32_t	ft_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	twod_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	check_player_on_wall(t_eng *eng, double player_x, double player_y)
{
	int	x;
	int	y;
	char	**map;

	map = eng->parser.map;
	x = player_x / SIZE; 
	y = player_y / SIZE;
	if (y < 0 || y >= twod_size(map))
		return (1);
	if (x < 0 || x > (int)ft_strlen(map[y]))
		return (1);
	if (map[y][x] == '1')
		return (1);
	return (0);
}

int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

 void DDA(t_eng *eng, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
		mlx_put_pixel(eng->img, x, y, ft_pixel(187, 230, 228, 255));
        x += xIncrement;
        y += yIncrement;
    }
}
