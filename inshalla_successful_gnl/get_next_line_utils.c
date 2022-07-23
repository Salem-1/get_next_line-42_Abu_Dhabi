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

char * ft_mystrcpy(char *result, char *reader)
{
	int	i;

	i = -1;
	result = malloc(ft_strlen(reader) + 2);
	if (!result)
		return (NULL);
	while(reader[++i])
		result[i] = reader[i];
	result[i] = '\0';
	result[i + 1] = '\0';
	return (result);
}

char *ft_strjoin(char *tmp, char *reader, int counter)
{
	char	*new;
	int		i;
	int		j;

	new = NULL;
	new = malloc(sizeof(char *)  * counter + 2);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < counter - ft_strlen(reader))	
		new[i] = tmp[i];
	i--;
	
	while (++i < counter)
	{
		new[i] = reader[++j];
		//printf("new[%d] <%c> = reader[%d] <%c>\n",i,  new[i], j, reader[j]);
	}
	//printf("new =  %s, and i = %d counter = %d\n", new, i, counter);
	
	new[i] = '\0';
	new[i + 1] = '\0';
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
		if (tmp[i] == '\n' || tmp[i] == '\0')
			return (++i);
	}
	return (-1);
}


char *filler(char *reader, char *result, int fd)
{
	int		len_reader;
	int		read_len;
	int		counter;
	char	*tmp;


	len_reader = 0;
	tmp = NULL;
	counter = ft_strlen(result);
	
	read_len = 0;

	//printf("filler tester -----------------------\n");
	//  printf("entering filler, result = %s, reader = %s, counter = %d\n", result, reader, counter);

	while (check_null_or_nl(reader, BUFFER_SIZE) == -1)
	{
		read_len = read(fd, reader, BUFFER_SIZE);
		reader[read_len] = '\0';
		counter += read_len;
		if (read_len == 0)
			// printf("counter = %d, len(str) = %d\n", counter, ft_strlen(result));
		result = ft_strjoin(result, reader, counter);
	}
	//assumption : countr = ft_strlen(result)
	// printf("result_len = %d , read_len = %d, countre = %d, last_Char = <%c>\n", ft_strlen(result), read_len, counter, result[check_null_or_nl(result, counter)]);
	result[check_null_or_nl(result, counter)] = '\0';
	//printf("result before returning filler = <%s>\n", result);
	
	read_len = check_null_or_nl(reader, ft_strlen(reader)) - 1;
	counter = -1;
	tmp = ft_mystrcpy(tmp, reader);
	//printf("reader copy = %s, reader = %s", tmp, reader);
	len_reader = ft_strlen(reader);
	//printf("read_len = %d, readler_len = %d\n", read_len, ft_strlen(reader));
	null_me(reader);
	//printf("read_len = %d, readler_len = %d\n", read_len, ft_strlen(reader))
	//copying the reader to itself from the null or \n to the end
	// printf("len_reader = %d, len_temp = %d\n", len_reader, ft_strlen(tmp));
	while (++read_len  < len_reader  )
	{
		reader[++counter] = tmp[read_len];
//		printf("reader[%d] = <%c>\n", counter, reader[counter]);
	}
	//printf("searching for null reader[end] = <%c>\n", reader[counter]);
//	printf("remaining reader = <%s>\n", reader);
	
	free(tmp);	
	return (result);
}

void null_me(char *reader)
{
	int	i;
	
	i = -1;
	while (reader[++i])
		reader[i] = '\0';
}

