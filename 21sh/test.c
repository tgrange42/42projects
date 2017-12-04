/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:18:25 by tgrange           #+#    #+#             */
/*   Updated: 2017/12/04 17:42:01 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*deletechar(char *str, int *w)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str)))))
		return (NULL);
	ret = ft_strncpy(ret, str, *w - 1);
	i = ft_strlen(ret);
	j = *w;
	while (str[j])
		ret[i++] = str[j++];
	*w += ft_strlen(ret) - ft_strlen(str);
	ft_strdel(&str);
	return (ret);
}

char	*includechar(char *str, char c, int *w)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	ret = ft_strncpy(ret, str, *w);
	if (c)
		ret[*w] = c;
	i = ft_strlen(ret);
	j = *w;
	while (str[j])
		ret[i++] = str[j++];
	*w += 1;
	ft_strdel(&str);
	return (ret);
}

int		init(struct termios *term, struct termios *saved_term)
{
	char	*name_term;

	name_term = NULL;
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) != 1 || tcgetattr(0, term) != 0 ||
		tcgetattr(0, saved_term) != 0)
		return (-1);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	if (tcsetattr(0, 0, term) != 0)
		return (-1);
	return (1);
}

int		handle_keys(char *buf, char *line, int *pos)
{
	if (buf[0] == 127 && !(buf [1] + buf[2] + buf[3]))
		line = deletechar(line, pos);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
		*pos -= *pos > 0 ? 1 : 0;
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
		*pos += *pos < ft_strlen(line) ? 1 : 0;
	else
		return (0);
	// if (*pos > ft_strlen(line))
	// 	*pos = ft_strlen(line);
	// if (*pos < 0)
	// 	*pos = 0;
	return (1);
}

void	test(char *buf)
{
	char	*line;
	int		pos;

	pos = 0;
	line = ft_strnew(0);
	while (1)
	{
		ft_bzero(buf, 4);
		read(0, buf, 4);
		if (!handle_keys(buf, line, &pos))
			line = includechar(line, buf[0], &pos);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		ft_putstr_fd(line, 0);
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), pos, 0), 0);
	}
}

int		main(void)
{
	char	buf[4];
	struct termios	term;
	struct termios	saved_term;

	if (init(&term, &saved_term) == -1)
		return (-1);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	test(buf);
	ft_putstr_fd(tgetstr("te", NULL), 0);
	if (tcsetattr(0, 0, &saved_term) != 0)
		return (-1);
	return (0);
}
