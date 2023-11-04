/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:37:17 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/16 13:06:42 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_eng	eng;

	(void)argv;
	if (argc != 2)
		exit(1);
	parser(&eng.parser, argv[1]);
	engine(&eng);
}
