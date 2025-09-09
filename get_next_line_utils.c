/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/09 20:17:06 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	get_nl_char(char *str)
{
	int	nl_index;

	nl_index = 0;
	while (str[nl_index] != '\0' && str[nl_index] != '\n')
	{
		nl_index++;
	}
	if (str[nl_index] == '\0')
		nl_index = -1;
	else if (str[nl_index] == '\n')
		return (nl_index);
	return (-1);
	
}
