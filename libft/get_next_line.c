/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:40:57 by dadavyde          #+#    #+#             */
/*   Updated: 2018/01/11 18:41:03 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_line(char **line, char *str, t_node *rest_of_line)
{
	char		*next_str;
	char		*res;
	char		*str_2;

	next_str = ft_strchr(str, '\n');
	(next_str == NULL) ? (next_str = str + ft_strlen(str)) : 0;
	res = ft_strsub(str, 0, next_str - str);
	if (!(str_2 = ft_strjoin(*line, res)))
		return (-1);
	ft_memdel((void**)&res);
	ft_memdel((void**)line);
	*line = str_2;
	if (*next_str == '\n')
	{
		next_str = ft_strsub(next_str, 1, ft_strlen(next_str) - 1);
		ft_memdel((void**)&(rest_of_line->str));
		rest_of_line->str = next_str;
		return (1);
	}
	ft_memdel((void**)&(rest_of_line->str));
	return (0);
}

static int		free_list(char **line, int ret, t_node **begin,
				t_node **rest_of_line)
{
	t_node		*tmp;

	if (ret == 0 && *line != NULL)
		return (1);
	tmp = *begin;
	if (*begin != *rest_of_line)
	{
		while (tmp->next != NULL && tmp->next != *rest_of_line)
			tmp = tmp->next;
		tmp->next = (*rest_of_line)->next;
	}
	else
		*begin = (*rest_of_line)->next;
	ft_memdel((void**)rest_of_line);
	(*line != NULL) ? free(*line) : 0;
	*line = NULL;
	return (ret);
}

static int		read_file(char **line, t_node **begin, t_node **rest_of_line)
{
	char		buff[BUFF_SIZE];
	int			ret;
	char		*str;

	if (!(str = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while (1)
	{
		ret = read((*rest_of_line)->fd, buff, BUFF_SIZE);
		if (ret < 0 || ret == 0)
		{
			ft_memdel((void**)&str);
			return (free_list(line, ret, begin, rest_of_line));
		}
		else
		{
			str = ft_strncpy(str, buff, ret);
			str[ret] = '\0';
			if (check_line(line, str, *rest_of_line))
			{
				ft_memdel((void**)&str);
				return (1);
			}
		}
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_node	*begin;
	t_node			*rest_of_line;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	rest_of_line = begin;
	while (rest_of_line != NULL && rest_of_line->fd != fd)
		rest_of_line = rest_of_line->next;
	if (rest_of_line == NULL)
	{
		if (!(rest_of_line = malloc(sizeof(t_node))))
			return (-1);
		ft_bzero((void*)rest_of_line, (size_t)(sizeof(t_node)));
		rest_of_line->fd = fd;
		rest_of_line->next = begin;
		begin = rest_of_line;
	}
	if (rest_of_line->str != NULL)
		if (check_line(line, rest_of_line->str, rest_of_line))
			return (1);
	return (read_file(line, &begin, &rest_of_line));
}
