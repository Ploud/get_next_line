/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:04:13 by jsobel            #+#    #+#             */
/*   Updated: 2018/05/28 19:12:16 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free(int fd, t_data **l)
{
	t_data	*f;

	f = *l;
	if ((*l)->index == fd)
	{
		*l = (*l)->next;
		ft_strdel(&(f->tmp));
		ft_strdel(&(f->line));
		free(f);
	}
	else
		ft_free(fd, &(*l)->next);
}

int		ft_read_buf(int flag, char *buf, t_data **p)
{
	int		i;
	char	*link;

	i = 0;
	link = (*p)->line;
	while (buf[i])
	{
		(*p)->tmp[i] = buf[i];
		if (flag < 0 && buf[i] == '\n')
		{
			(*p)->tmp[i] = 0;
			if (!(link = ft_strjoin((*p)->line, (*p)->tmp)))
				return (-1);
			flag = i;
		}
		i++;
	}
	(*p)->tmp[i] = 0;
	if (flag < 0 && buf[0])
		link = ft_strjoin((*p)->line, (*p)->tmp);
	else
		ft_memcpy((*p)->tmp, (*p)->tmp + flag + 1, BUFF_SIZE - flag);
	ft_strdel(&((*p)->line));
	(*p)->line = link;
	return (flag);
}

int		ft_reader(const int fd, t_data **p)
{
	int		i;
	int		flag;
	int		len;
	char	buf[BUFF_SIZE + 1];

	i = -1;
	flag = -1;
	while ((*p)->tmp[++i])
	{
		(*p)->line[i] = (*p)->tmp[i];
		(*p)->tmp[i] = 0;
		if ((*p)->line[i] == '\n')
		{
			(*p)->line[i] = 0;
			ft_memcpy((*p)->tmp, (*p)->tmp + i + 1, BUFF_SIZE - i);
			return (1);
		}
	}
	while (flag < 0 && (len = read(fd, buf, BUFF_SIZE)))
	{
		if (len == -1)
			return (-1);
		buf[len] = 0;
		flag = ft_read_buf(flag, buf, p);
	}
	return (len > 0);
}

t_data	*ft_set_p(const int fd, t_data **l)
{
	if ((*l) && (*l)->index != fd)
		return (ft_set_p(fd, &(*l)->next));
	else
	{
		if (!(*l))
		{
			if (!((*l) = malloc(sizeof(t_data))))
				return (NULL);
			(*l)->index = fd;
			if (!((*l)->line = malloc(sizeof(char) * (BUFF_SIZE + 1))))
				return (NULL);
			if (!((*l)->tmp = malloc(sizeof(char) * (BUFF_SIZE + 1))))
				return (NULL);
			ft_bzero((*l)->tmp, BUFF_SIZE + 1);
			(*l)->next = NULL;
		}
		return ((*l));
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_data	*l = NULL;
	t_data			*p;
	int				state;

	if (!(p = ft_set_p(fd, &l)))
		return (-1);
	ft_bzero(p->line, ft_strlen(p->line) + 1);
	if ((state = ft_reader(fd, &p)) == -1)
		return (-1);
	*line = NULL;
	if (p->line[0] || state != 0)
		*line = ft_strdup(p->line);
	if (!state)
		ft_free(fd, &l);
	return (*line != NULL || state != 0);
}