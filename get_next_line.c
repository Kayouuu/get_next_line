/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:00:00 by psaulnie          #+#    #+#             */
/*   Updated: 2021/11/30 17:35:03 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_nl(char **str)
{
	char	*save;
	char	*tmp;

	tmp = ft_strndup(*str, '\n');
	save = ft_strndup(ft_strchr(*str) + 1, '\0');
	free(*str);
	*str = save;
	return (tmp);
}

char	*clean(char *str)
{
	free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*str = NULL;
	char		*returned_str;
	int			readed;

	returned_str = 0;
	readed = 1;
	if (read(fd, buffer, 0) < 0)
		return (NULL);
	while (!ft_strchr(str) && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (0);
		buffer[readed] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (0);
	}
	if (ft_strchr(str))
		return (extract_nl(&str));
	if (str && str[0])
		returned_str = ft_strndup(str, '\0');
	str = clean(str);
	return (returned_str);
}
