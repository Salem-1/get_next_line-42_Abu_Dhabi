/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:13:00 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/27 17:56:23 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char		*result;
	char			*tmp;
	char			*reader;
	int				read_len;
	
	tmp = NULL;
	reader = NULL;
	if (result != NULL)
	{
		result = check_filled_result(result, tmp, reader, fd);
		return (result);
	}
	if (fd == -1)
		return (error_message("error: Nothing more to read"));
	reader = malloc(BUFFER_SIZE);
	if (!reader)
		return (NULL);
	read_len = read(fd, reader, BUFFER_SIZE);
	reader[read_len] = '\0';
	tmp = ft_strjoin(tmp, reader, BUFFER_SIZE);
	result = filler(reader, tmp, result, fd);
	return (result);
}

char *clean_result(char * result, char *tmp, int counter)
{
	int		new_line_index;
	char	*new_line;
	char	*remaining;
	
	new_line = NULL;
	remaining = NULL;
	new_line_index = check_null_or_nl(tmp, counter);
	if (new_line_index <= 0)
	{
		result = ft_strjoin(result, tmp, counter + 1);
		result[counter+ 1]= '\0';
		return (result);
	}
	new_line = ft_strjoin(new_line, tmp, new_line_index + 1);
	new_line[new_line_index + 1] = '\0';
	printf("newline = <%s>\n",new_line);
	remaining = ft_strjoin(remaining, &tmp[new_line_index + 1], counter - new_line_index);
	result = ft_strjoin(new_line, remaining, counter + 2);
	//appending the rest of string readed after the null terminated new line
	//free(remaining);
//	free(new_line);
	return (result);
}


char *error_message(char *error)
{
	return (error);
}