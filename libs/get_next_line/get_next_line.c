/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpak <cpak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:13:36 by sarchoi           #+#    #+#             */
/*   Updated: 2022/08/29 14:49:38 by cpak             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_malloc_str(unsigned int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	*str = '\0';
	return (str);
}

static	void	join_tmp_and_store(char **tmp, char **store)
{
	*tmp = ft_gnl_strjoin((char const *)*tmp, *store);
	free(*store);
	*store = NULL;
}

static int	ft_read_oneline(int fd, char **tmp, char **store)
{
	char	buf[BUFFER_SIZE + 1];
	int		result;
	char	*newline_in_tmp;

	result = read(fd, buf, BUFFER_SIZE);
	while (result != FT_ERROR)
	{
		buf[result] = '\0';
		if (*store != NULL)
			join_tmp_and_store(tmp, store);
		*tmp = ft_gnl_strjoin((char const *)*tmp, buf);
		newline_in_tmp = ft_strchr(*tmp, '\n');
		if (newline_in_tmp != NULL)
		{
			*newline_in_tmp = '\0';
			*store = ft_strdup(newline_in_tmp + 1);
			return (FT_SUCCESS);
		}
		else if (result == FT_EOF)
			return (FT_EOF);
		result = read(fd, buf, BUFFER_SIZE);
	}
	return (FT_ERROR);
}

int	get_next_line(int fd, char **line)
{
	static char	*store[256];
	char		*tmp;
	int			result;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (FT_ERROR);
	tmp = ft_malloc_str(0);
	result = ft_read_oneline(fd, &tmp, &store[fd]);
	if (result == FT_ERROR)
		return (FT_ERROR);
	*line = ft_strdup(tmp);
	free(tmp);
	if (result == FT_EOF)
		return (FT_EOF);
	return (FT_SUCCESS);
}
