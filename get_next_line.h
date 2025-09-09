/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:19:52 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/09 20:27:50 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		get_nl_char(char *str);

#endif