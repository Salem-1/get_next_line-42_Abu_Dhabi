/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:11:35 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/29 06:46:34 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//the remaining part to check the filled result
//do the testers inshalla

char *ft_strjoin(char *tmp, char *reader, int counter, char flag)
{
	char	*new;
	int		i;
	int		j;
	
	//printf("reader = %s", reader);
	new = malloc(counter);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	if (tmp == NULL || flag == 'c')
	{
		while(++i < counter)
		{
		//	printf("reader[%d] = <%c>\n", i, reader[i]);
			new[i] = reader[i];
		}
		//free(tmp);
		return (new);
	}
	while (++i < counter - BUFFER_SIZE)	
		new[i] = tmp[i];
	i--;
	while (++i < counter)
		new[i] = reader[++j];
	//free(tmp);
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
		{
			return (++i);
		}
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
			reader[0] = '\0'; //nulling the reader to break the loop below
	}
	while (check_null_or_nl(reader, BUFFER_SIZE) == -1 || check_null_or_nl(tmp, counter) == -1)
	{
		read_len = read(fd, reader, BUFFER_SIZE);
		reader[read_len] = '\0';
		tmp = ft_strjoin(tmp, reader, counter, 'j');
		counter += BUFFER_SIZE;
	}
	//printf("tmp = <%s>", tmp);
	result = clean_result(result, tmp, reader,counter - BUFFER_SIZE);
	//I am not sure weather there is a need for the reamain_fill(), or I can 
	//do the job inside clean_result()
	remaining_fill( tmp, reader, counter);
	//printf("reader last = <%s>", reader);
	free(tmp);
	return (result);
}

void remaining_fill(char *tmp, char *reader ,int counter)
{
	int		new_line_index;
	char	*remaining;
	int		i;

	i = -1;
	remaining = NULL;
	new_line_index = check_null_or_nl(tmp, counter);
	// printf("newlineindex = %d\n", new_line_index);
	if (new_line_index <= 0)
	{
		reader[0] = '\0';
	}
	else
	{
		//printf("remaining in tmp %d(%s)",new_line_index, &tmp[new_line_index +1]);
		//I am using buffer size as if there is new line or null, the reader will stop
		//there and will not read the rest
		remaining = ft_strjoin(reader, &tmp[new_line_index ], BUFFER_SIZE , 'j');
		null_me(reader);
		while (remaining[++i])
			reader[i] = remaining[i];
		//printf("reader is %s, remaining is %s\n", reader, remaining);
		//printf("remaning fill reader = <%s>", reader);
		free(remaining);
	}
}

/*
char *check_filled_result(char *result, char *tmp, char *reader, int fd)
{
	int	new_line_index;
	
	if (check_null_or_nl(reader, BUFFER_SIZE) <= 0)
	{
		return (error_message("error: Nothing more to read\n"));
	}
	new_line_index = check_null_or_nl(reader, BUFFER_SIZE);
	if (reader[new_line_index + 1] != '\0') 
	{
		
		tmp = ft_strjoin(tmp, &result[new_line_index + 2], BUFFER_SIZE);
		//free(result);
		return (filler( reader,tmp, result, fd));//the tmp should be in reader place but not to be filled 
	}
	return (error_message("error: Nothing more to read\n"));
}*/

void null_me(char *reader)
{
	int	i;
	
	i = -1;
	while (reader[++i])
		reader[i] = '\0';
}