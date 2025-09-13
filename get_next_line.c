/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/13 13:32:40 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(int fd)
{
	char	*buffer;
	char	*chunk;
	int		bytes_read;

	bytes_read = 0;
	chunk = malloc(sizeof(char));
	chunk[0] = '\0';
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (get_nl_char(buffer) < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		ft_strlcat(chunk, buffer, ft_strlen(chunk) + bytes_read + 1);
		if (bytes_read == 0)
			break ;
	}
	if (bytes_read < BUFFER_SIZE) // Control EOF
		ft_strlcat(chunk, buffer, ft_strlen(chunk) + bytes_read + 1);
	return (chunk);
}

void	check_remain(char **remain, char **line)
{
	char	*ptr_temp;
	int		nl_index;

	nl_index = 0;
	ptr_temp = NULL;
	if (get_nl_char(*remain) >= 0)
	{
		nl_index = get_nl_char(*remain);
		ft_strlcpy(*line, *remain, nl_index + 1);
		ft_strlcpy(ptr_temp, &*remain[nl_index], ft_strlen(*remain) - nl_index);
		free(*remain);
		ft_strlcpy(*remain, ptr_temp, ft_strlen(ptr_temp));
	}
	else if (get_nl_char(*remain) < 0)
	{
		*line = malloc((ft_strlen(*remain) + 1) * sizeof(char));
		ft_strlcpy(*line, *remain, ft_strlen(*remain) + 1);
		free(*remain);
		*remain = NULL;
	}
}

void	fill_line(char **remain, char **line, char **buffer)
{
	char	*ptr_tmp;

	ptr_tmp = NULL;
	if (*remain == NULL)
	{
		if (*line == NULL)
			*line = malloc((get_nl_char(*buffer) + 1) * sizeof(char));
		ptr_tmp = ft_strjoin(*line, *buffer);
		free(*line);
		*line = ptr_tmp;
		ptr_tmp = NULL;
		*remain = malloc((ft_strlen(*buffer) - ft_strlen(*line) + 1) * sizeof(char));
		ft_strlcpy(*remain, (*buffer + get_nl_char(*buffer) + 1), ft_strlen(*buffer) - ft_strlen(*line) + 2);
	}
	else
	{
		if (*line == NULL)
			*line = malloc((get_nl_char(*buffer) + ft_strlen(*remain) + 1) * sizeof(char));
		ft_strlcat(*line, *buffer, ft_strlen(*line) + ft_strlen(*buffer) + 1);
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*remain;

	line = NULL;
	buffer = NULL;
	if (!remain)
		remain = NULL;
	else
		check_remain(&remain, &line);
	buffer = fill_buffer(fd);
	fill_line(&remain, &line, &buffer);
	free(buffer);
	return (line);
}
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char	*str;
	int		i;

	str = NULL;
	if (argc != 2)
		return (0);
	int	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < 6)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	return (0);
}