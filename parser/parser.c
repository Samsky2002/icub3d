/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:45:45 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/18 10:50:30 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parse_vars(t_parser *parser)
{
	parser->list = NULL;
	parser->map = NULL;
	parser->player = 'N';
}

void	parser(t_parser *parser, char *file)
{
	init_parse_vars(parser);
	check_file(parser, file);
	parse_filler(parser);
}
