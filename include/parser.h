/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:49:10 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/20 12:39:00 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSER_H
# define PARSER_H

typedef struct s_fcolor
{
	int	f1;
	int	f2;
	int	f3;
} t_fcolor;

typedef struct s_ccolor
{
	int	c1;
	int	c2;
	int	c3;
} t_ccolor;

typedef struct s_parser
{
	t_list	*list;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**map;
	char	player;
	t_fcolor	fcolor;
	t_ccolor	ccolor;
} t_parser;

//parser
void	parser(t_parser *parser, char *file);
void	init_parse_vars(t_parser *parser);

//check_file
void	check_file(t_parser *parser, char *file);
void	get_map_content(t_parser *parser, int fd);
int		open_file(char *file);
void	check_file_name(char *file);
void	parse_filler(t_parser *parser);

#endif
