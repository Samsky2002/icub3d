/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:17:25 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/16 13:06:26 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file_name(char *file)
{
	(void)file;	
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (fd);
}

void	get_map_content(t_parser *parser, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&parser->list, ft_lstnew(line));
		line = get_next_line(fd);
	}
}

void	check_file(t_parser *parser, char *file)
{
	int	fd;

	check_file_name(file);
	fd = open_file(file);
	get_map_content(parser, fd);
}

// TODO:check_file
// check filename if it ends with .cub
// check if file exists
// fill the file content in a linked list
