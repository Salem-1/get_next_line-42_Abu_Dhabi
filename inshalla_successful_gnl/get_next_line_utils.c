/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:11:35 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/27 08:38:53 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char *tmp, char *reader, int counter)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(counter);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	if (tmp == NULL)
	{
		while(++i < counter)
			new[i] = reader[i];
		free(tmp);
		return (new);
	}
	while (++i < counter - BUFFER_SIZE)	
		new[i] = tmp[i];
	i--;
	while (++i < counter)
		new[i] = reader[++j];
	free(tmp);
	return (new);
}

int check_null_or_nl(char *tmp, int counter)
{
	
	int	i;
	
	if(tmp == NULL)
		return (1);
	i = -1;
	while (++i < counter)
	{
		if(tmp[i] == '\0')
			return (0);
		else if (tmp[i] == '\n')
			return (i);
	}
	return (-1);
}


char *filler(char *reader, char *tmp, char *result, int fd)
{
	int	read_len;
	int	counter;
	
	counter = BUFFER_SIZE;
	read_len = 0;
	if (tmp != NULL)
	{	
		counter += BUFFER_SIZE;
		if (check_null_or_nl(tmp, BUFFER_SIZE) > -1)
			reader[0] = '\0';
	}
	while (check_null_or_nl(reader, BUFFER_SIZE) == -1)
	{
		read_len = read(fd, reader, BUFFER_SIZE);
		reader[read_len] = '\0';
		tmp = ft_strjoin(tmp, reader, counter);
		counter += BUFFER_SIZE;
	}
	result = clean_result(result, tmp, counter - BUFFER_SIZE);
	free(tmp);
	free(reader);
	return (result);
}

char *check_filled_result(char *result, char *tmp, char *reader, int fd)
{
	int	new_line_index;
	
	if (check_null_or_nl(result, BUFFER_SIZE) <= 0)
	{
		free(result);
		return ("error: Nothing more to read");
	}
	new_line_index = check_null_or_nl(result, BUFFER_SIZE);
	if (result[new_line_index + 1] != '\0') 
	{
		
		tmp = ft_strjoin(tmp, &result[new_line_index + 2], BUFFER_SIZE);
		free(result);
		return (filler( reader,tmp, result, fd));//the tmp should be in reader place but not to be filled 
	}
	return ("error : Nothing more to read");
}