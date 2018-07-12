/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 23:29:48 by cababou           #+#    #+#             */
/*   Updated: 2018/02/27 01:50:49 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char			*read_file(char *filepath)
{
	char	*content;
	char	*buf;
	size_t	readbytes;
	int		fd;

	content = ft_strnew(0);
	buf = ft_strnew(READ_BUF_SIZE);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((readbytes = read(fd, buf, READ_BUF_SIZE)) > 0)
		content = ft_strjoin(content, ft_strsub(buf, 0, readbytes, 0), 3);
	return (content);
}

t_parser_number	*get_next_number(char *content, int startpoint)
{
	char			*buf;
	t_parser_number	*number;
	size_t			i;

	number = malloc(sizeof(t_parser_number));
	number->read_characters = 0;
	i = startpoint;
	buf = ft_strnew(0);
	while (content[i] == ' ' || content[i] == '\n')
	{
		number->read_characters++;
		i++;
	}
	while (content[i] != ' ' && content[i] != '\0' && content[i] != '\n')
	{
		buf = ft_strjoin(buf, ft_strsub(content, i, 1, 0), 3);
		number->read_characters++;
		i++;
	}
	number->read_number = ft_atoi(buf);
	return (number);
}

t_lstcontainer	*parse_file(char *filepath)
{
	char			*content;
	size_t			i;
	int				*xz;
	t_lstcontainer	*pointlist;
	t_parser_number	*number;

	pointlist = lstcontainer_new();
	content = read_file(filepath);
	i = 0;
	xz = malloc(sizeof(int *) * 2);
	xz[0] = 0;
	xz[1] = 0;
	while (content[i] && content[i + 1])
	{
		number = get_next_number(content, i);
		i += number->read_characters;
		pointlist->add(pointlist, new_point(xz[0], number->read_number, xz[1]),
				sizeof(t_point));
		xz[0] += 1;
		if (content[i] == '\n')
		{
			xz[0] = 0;
			xz[1] += 1;
		}
	}
	free(xz);
	return (pointlist);
}
