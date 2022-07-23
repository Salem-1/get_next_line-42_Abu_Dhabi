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
//the processing of the returned reader before reading again
//clean it before the retuning the reader itself to test and process, 
//if found null return the error, an this will solve end of file error

//solve the strjoin error 

char *get_next_line(int fd)
{
	//printf("%d\n", fd);
	if (fd < 0 || fd == 1000 )
			return (NULL);
	static char	reader[BUFFER_SIZE + 2];
	char		*result;
	int			read_len;
	
	result = NULL;
	// printf("begining reader = <%s>\n", reader);
	if (reader[0])
	{
		result = ft_mystrcpy(result, reader);
		read_len = check_null_or_nl(result, ft_strlen(result) + 1);
		if (result[read_len - 1] == '\0')
		{
			// printf("read_len = %d\n", read_len);
			if (read_len == 0)
				return (NULL); 
			read_len = read(fd, reader, BUFFER_SIZE);
			reader[read_len] = '\0';
			result = ft_strjoin(result, reader, ft_strlen(result) + read_len );	
		}
		result = filler(reader,result, fd);
		return (result);
	}
	else
	{
		read_len = read(fd, reader, BUFFER_SIZE);
		//printf("readlen = %d, reader = <%d>\n", read_len, reader[0]);
		if (read_len == 0)
			return (NULL);
		
		reader[read_len] = '\0';
		result = ft_mystrcpy(result, reader);
		result = filler(reader,result, fd);
		return (result);
	}
}
		
// char *clean_result(char * result, char *tmp, char *reader ,int counter)
// {
// 	int		new_line_index;
// 	int		reader_index;
// 	int		i;

// 	i = -1;
// 	new_line_index = check_null_or_nl(tmp, counter);
// 	reader_index = check_null_or_nl(tmp, BUFFER_SIZE);
// 	if (new_line_index == 0)
// 	{
// 		result = ft_strjoin(result, tmp, counter , 'c');
// 		return (result);
// 	}
	
// 	else if (new_line_index == -1)
// 		return (error_message("error: Nothing more to read\n"));
// 	result = ft_strjoin(result, tmp, new_line_index + 1, 'c');
// 	result[new_line_index ] = '\0';
// 	while (++reader_index < ft_strlen(reader))
// 			reader[++i] = reader[reader_index];
// 	return (result);
// }

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if(!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

// char *error_message(char *message)
// {
// 	char *error;

// 	error = NULL;
// 	error = ft_mystrcpy(error, message);
// 	return (error);
// }
