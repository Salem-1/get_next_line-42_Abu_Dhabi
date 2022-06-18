/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:11:35 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/18 20:49:13 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void clean_tmp(char *tmp, int i);
int check_nl_or_null(char *tmp, int counter);

/*handling the case of EOF appears as first char*/
char *check_err(char *result, char *error_message)
{
	free(result);
	return (error_message);
}

char  *filler(int fd, char *result, char *tmp)
{
	int	i;
	int counter;
	
	counter = BUFFER_SIZE;
	i = -1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		free(result);
		return (NULL);
	}
	while(++i < BUFFER_SIZE)
		tmp[i] = result[i];
	//if the line didn't finish or we didn't reach the file end
	//create new tmp = tmp + result, then check again
	while (!check_nl_or_null(tmp, counter))
	{
		counter += BUFFER_SIZE;
		read(fd, result, BUFFER_SIZE);
		tmp = ft_strjoin(tmp, result, counter); //counter is the new malloc
	}
	tmp[counter] = '\0';
	clean_tmp(tmp, i=0);
	return (tmp);
}

/*clean the extra memory in tmp after the /n or \0*/
void clean_tmp(char *tmp, int i)
{
	while(tmp[i])
	{
		if (tmp[i] == '\n')
			{
				tmp[i+ 1] = '\0';
				break;
			}
			i++;
	}
}

int check_nl_or_null(char *tmp, int counter)
{
	while (i < counter)
	{
		if (tmp[i] == \n || tmp[i] == '\0')
			return(i);
	}
	return (0);
}

char *ft_strjoin(char *tmp,char *result,int counter)
{
	//new_str = tmp + result  #this is lovely python code :)
}