/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:04:30 by jsobel            #+#    #+#             */
/*   Updated: 2018/05/25 17:41:13 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

# define BUFF_SIZE 30

typedef struct		s_data
{
	char			*line;
	char			*tmp;
	int				index;
	struct s_data	*next;
}					t_data;

void				ft_free(int fd, t_data **l);
int					ft_read_buf(int flag, char *buf, t_data **p);
int					ft_reader(const int fd, t_data **p);
t_data				*ft_set_p(const int fd, t_data **l);
int					get_next_line(const int fd, char **line);

#endif
