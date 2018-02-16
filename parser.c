/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 23:29:48 by cababou           #+#    #+#             */
/*   Updated: 2018/02/16 06:47:35 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_file(char *filepath)
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
		content = ft_strjoin(content, ft_strsub(buf, 0, readbytes));
	return (content);
}

t_list	*parse_file(char *filepath)
{
	char	*content;

	content = read_file(filepath);
}
