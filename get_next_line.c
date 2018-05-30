/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:04:13 by jsobel            #+#    #+#             */
/*   Updated: 2018/05/30 18:11:30 by jsobel           ###   ########.fr       */
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

int		ft_read_buf(int flag, char *buf, t_data **p, int len)
{
	int		i;
	char	*link;

	i = -1;
	while (++i < len)
	{
		(*p)->tmp[i] = buf[i];
		if (!flag && buf[i] == '\n' && (flag = i + 1))
		{
			(*p)->tmp[i] = 0;
			if (!(link = ft_strjoin((*p)->line, (*p)->tmp)))
				return (-1);
		}
	}
	(*p)->tmp[i] = 0;
	if (!flag)
	{
		if (!(link = ft_strjoin((*p)->line, (*p)->tmp)))
			return (-1);
	}
	else
		ft_memcpy((*p)->tmp, (*p)->tmp + flag, BUFF_SIZE - flag + 1);
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
	flag = 0;
	while ((*p)->tmp[++i])
	{
		(*p)->line[i] = (*p)->tmp[i];
		if ((*p)->line[i] == '\n')
		{
			(*p)->line[i] = 0;
			ft_memcpy((*p)->tmp, (*p)->tmp + i + 1, BUFF_SIZE - i);
			return (1);
		}
	}
	while (!flag && (len = read(fd, buf, BUFF_SIZE)))
	{
		if (len == -1 || (flag = ft_read_buf(flag, buf, p, len)) == -1)
			return (-1);
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
			(*l)->line = NULL;
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
	static t_data	*l;
	t_data			*p;
	int				state;

	if (!(p = ft_set_p(fd, &l)))
		return (-1);
	if (p->line)
		free(p->line);
	if (!(p->line = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ft_bzero(p->line, BUFF_SIZE + 1);
	if ((state = ft_reader(fd, &p)) == -1)
		return (-1);
	*line = NULL;
	if ((p->line[0] || state != 0) && !(*line = ft_strdup(p->line)))
		return (-1);
	if (!state)
		ft_free(fd, &l);
	return (*line != NULL || state != 0);
}
