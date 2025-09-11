/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/11 00:06:02 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(int fd)
{
	char	*buffer;
	char	*chunk;
	int		bytes_read;

	bytes_read = 0;
	chunk = malloc(1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (get_nl_char(buffer) < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		ft_strlcat(chunk, buffer, ft_strlen(chunk) + bytes_read + 1);
	}
	if (bytes_read < BUFFER_SIZE) // Control EOF
		;
	return (chunk);
}

void	check_remain(char *remain, char *line)
{
	// if *remain has '\n'
	//   set content until '\n' to *line
	//   set content starting from '\n' to *remain
	// if *remain has content without '\n'
	//   set all *remain content to *line
	// 
	// 
	
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*remain;

	line = NULL;
	if (!remain)
		remain = NULL;
	else //if (get_nl_char(remain) < 0)
		check_remain(remain, line);

	// if *line has \n
	//   return line
	// else
	//   read content and concatenate at *line until '\n'
	// return *line
	buffer = fill_buffer(fd);
	line = malloc((get_nl_char(buffer) + 1) * sizeof(char));
	ft_strlcpy(line, buffer, get_nl_char(buffer) + 2);
	remain = malloc((ft_strlen(buffer) - ft_strlen(line) + 1) * sizeof(char));
	ft_strlcpy(remain, (buffer + get_nl_char(buffer) + 1), ft_strlen(buffer) - ft_strlen(line) + 2);
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
	while (i < 2)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	// str = get_next_line(fd);
	// printf("%s", str);
	free(str);
	return (0);
}