/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:33:57 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/28 17:42:27 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**cpy_tab(char **src)
{
	char	**ret;
	int		i;

	i = 0;
	ret = NULL;
	if (!src)
		return (NULL);
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		ret[i] = ft_strdup(src[i]);
		i++;
	}
	return (ret);
}

char	***add_line_to_map(char ***map, char **line)
{
	char	***ret;
	int		i;

	i = 0;
	if (!(ret = (char ***)ft_memalloc(sizeof(char **) * (tri_tablen(map) + 2))))
		return (NULL);
	while (map && map[i])
	{
		ret[i] = cpy_tab(map[i]);
		i++;
	}
	ret[i] = line;
	del_triple_tab(&map);
	return (ret);
}

char	***get_map(char *map_path)
{
	char	***ret;
	char	**buf;
	char	*line;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_fdf_error(NULL, 3, map_path);
	line = NULL;
	ret = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_tabsplit(line);
		ret = add_line_to_map(ret, buf);
	}
	close(fd);
	return (ret);
}
