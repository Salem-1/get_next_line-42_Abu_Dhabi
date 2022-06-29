/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:13:00 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/29 07:05:12 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//first line call work excellent, fix the second line call
//by tracing the remaining reader and the operations that
//came after inshall
//7asbi Allah la 2elah 2la hoa 3alieh tawklt wa hoa rab el3arsh el3azeem

char *get_next_line(int fd)
{
	static char	reader[BUFFER_SIZE];
	char		*tmp;
	char		*result;
	int			read_len;
	
	result = NULL;
	tmp = NULL;
	if (reader[0])
	{
	//	printf("reader after call = %s", reader);
		
		//start coding from here inshalla fix this part..
		tmp = ft_strjoin(tmp, reader, BUFFER_SIZE, 'c');
		null_me(reader);
		read_len = read(fd, reader, BUFFER_SIZE);
		//printf("\n2ndcall reader = %s", reader);
		if (read_len == 0)
			result = clean_result(result, tmp, reader ,BUFFER_SIZE);
		else
		{
			
			tmp = ft_strjoin(reader, tmp, BUFFER_SIZE , 'j');
		//	printf("\n2nd call tmp = %s\n", tmp);
			result = filler(reader, tmp, result, fd);
		}
		return (result);
	}
	if (fd == -1)
		return (error_message("error: Nothing more to read\n"));
	read_len = read(fd, reader, 4);
	//printf("read_len = %d\n", read_len);
	if (read_len == 0)
		return (error_message("error: Nothing more to read\n"));
	reader[read_len] = '\0';
	tmp = ft_strjoin(tmp, reader, BUFFER_SIZE, 'j');
	result = filler(reader, tmp, result, fd);
	return (result);
}

char *clean_result(char * result, char *tmp, char *reader ,int counter)
{
	int		new_line_index;
	char	*new_line;
	//char	*remaining;
	//int		i;

	//i = -1;
	new_line = NULL;
	//remaining = NULL;
	new_line_index = check_null_or_nl(tmp, counter);
	//printf("thisis the enw %d**\n", new_line_index);
	if (new_line_index == 0)
	{
		//result = ft_strjoin(result, &tmp[new_line_index + 1], counter + 1, 'j');
		result = ft_strjoin(result, tmp, counter + 1, 'j');
		//result[new_line_index+ 1]= '\0';
		return (result);
	}
	else if (new_line_index == -1)
		return (error_message("error: Nothing more to read\n"));
	new_line = ft_strjoin(new_line, tmp, new_line_index + 1 , 'j');
	
	//the cod below doesn't make sense as I have remaining fill function already
	reader = ft_strjoin(reader, &tmp[new_line_index - 1], BUFFER_SIZE , 'j');
	new_line[new_line_index ] = '\0';
	//I changed the length of the copied string from counter + 2 to the below
	result = ft_strjoin(result, new_line, new_line_index + 1, 'c');
	//free(tmp);
	return (result);
}


char *error_message(char *error)
{
	return (error);
}