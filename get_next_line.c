/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:04:13 by jsobel            #+#    #+#             */
/*   Updated: 2018/05/16 18:46:04 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free(int fd, t_data **l)
{
	t_data	*p;
	t_data	*f;
	int		i;

	p = *l;
	f = *l;
	i = 0;
	while (p->index != fd)
	{
		f = p;
		p = p->next;
	}
	f->next = p->next;
	free(p->tmp);
	p->tmp = NULL;
	free(p);
	p = NULL;
	//printf("free effectué\n");
}

int		ft_read_buf(int flag, char *buf, t_data *p)
{
	int		i;
	char	*link;

	i = 0;
	link = p->line;
	while (buf[i])
	{
		p->tmp[i] = buf[i];
		if (flag < 0 && buf[i] == '\n')
		{
			p->tmp[i] = 0;
			p->line = ft_strjoin(p->line, p->tmp);
			flag = i;
		}
		i++;
	}
	if (flag < 0)
		p->line = ft_strjoin(p->line, p->tmp);
	else
		ft_memcpy(p->tmp, p->tmp + flag + 1, BUFF_SIZE - flag + 1);
	free(link);
	return (flag);
}

int		ft_reader(const int fd, t_data *p)
{
	int		i;
	int		flag;
	int		len;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	flag = -1;
	while (p->tmp[i])
	{
		p->line[i] = p->tmp[i];
		if (p->tmp[i] == '\n')
		{
			p->line[i] = 0;
			ft_memcpy(p->tmp, p->tmp + i + 1, BUFF_SIZE - i + 1);
			return (1);
		}
		i++;
	}
	while (flag < 0 && (len = read(fd, buf, BUFF_SIZE)))
	{
		if (len == -1)
			return (-1);
		buf[len] = 0;
		flag = ft_read_buf(flag, buf, p);
	}
	return ((len));
}

t_data	*ft_set_p(const int fd, t_data **l)
{
	t_data	*p;

	p = NULL;
	while ((*l) && (*l)->index != fd)
	{
		p = (*l);
		(*l) = (*l)->next;
	}
	if (!(*l))
	{
		//printf("creation chainon\n");
		if (!((*l) = malloc(sizeof(t_data))))
			return (NULL);
		(*l)->index = fd;
		if (!((*l)->line = malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (NULL);
		if (!((*l)->tmp = malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (NULL);
		ft_bzero((*l)->tmp, BUFF_SIZE + 1);
		(*l)->next = NULL;
		if (p)
			p->next = (*l);
	}
	return ((*l));
}

int		get_next_line(const int fd, char **line)
{
	static t_data	*l = NULL;
	t_data			*p;
	int				state;

	if (!(p = ft_set_p(fd, &l)))
		return (-1);
	ft_bzero(p->line, BUFF_SIZE + 1);
	state = ft_reader(fd, p);
	*line = p->line;
	if (!state)
		ft_free(fd, &l);
	return (state);
}

int	main(int argc, char **argv)
{
	int fd;
	int fd2;
	int check;
	char *line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);

	check = get_next_line(fd, &line);
	printf("%s\n", line);
	check = get_next_line(fd, &line);
	printf("%s\n", line);
	check = get_next_line(fd, &line);
	printf("%s\n\n\n", line);

	check = get_next_line(fd2, &line);
	printf("%s\n", line);
	check = get_next_line(fd2, &line);
	printf("%s\n", line);
	check = get_next_line(fd2, &line);
	printf("%s\n\n\n", line);

	check = get_next_line(fd, &line);
	printf("%s\n", line);
	check = get_next_line(fd, &line);
	printf("%s\n", line);
	check = get_next_line(fd, &line);
	printf("%s\n", line);
	check = get_next_line(fd, &line);
	printf("%s\n\n\n", line);
	return (0);
}
