/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:49:21 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/21 10:53:35 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

typedef struct s_ray
{
	int		horiz_hit;
	double	horiz_wall_hit_x;
	double	horiz_wall_hit_y;
	double	horiz_distance;
	int		vert_hit;
	double	vert_wall_hit_x;
	double	vert_wall_hit_y;
	double	vert_distance;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
} t_ray;

typedef struct s_eng
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	t_parser		parser;
	double			player_x;
	double			player_y;
	double			rotation;
	double			angle;
	int				up;
	int				down;
	int				left;
	int				right;
	t_ray			ray;
} t_eng;

//engine
void	engine(t_eng *eng);
void	keyhook(void *param);

// drawing
uint32_t	ft_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int			check_player_on_wall(t_eng *eng, double player_x, double player_y);
void		draw_map(t_eng *eng);
void		draw_player(t_eng *eng);
void		clear_img(t_eng *eng);
void		DDA(t_eng *eng, int x1, int y1, int x2, int y2);

//x_y_pos
int	get_player_x(t_eng *eng);
int	get_player_y(t_eng *eng);

//ray_casting
void	vision(t_eng *eng);
void	ray_casting(t_eng *eng);

// ray_casting
double	normalize_angle(double old);

// render
void	render(t_eng *eng, int x);

#endif
