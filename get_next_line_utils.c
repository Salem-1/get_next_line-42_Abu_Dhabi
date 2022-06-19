/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:11:35 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/19 07:13:39 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void clean_tmp(char *tmp, int i);
int check_nl_or_null(char *tmp, int counter);
char *ft_strjoin(char *tmp,char *result,int counter);

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
	while (!check_nl_or_null(tmp, counter))
	{
		counter += BUFFER_SIZE;
		read(fd, result, BUFFER_SIZE);
		tmp = ft_strjoin(tmp, result, counter); //counter is the new malloc
	}
	// if(check_nl_or_null(tmp, counter) == -1) //protecting the program for NULL malloc result
	// 	return (NULL);
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
	static char	*remaining;
	int					i;
	int					j;

	remaining = malloc(BUFFER_SIZE);
	if (!remaining)
		return (-1); //this is an error as this is an int fun,if not ok, else return-ve num and return null somewhere in your program
	i = -1;
	j = -1;
	while (++i < counter)
	{
		if (tmp[i] == '\0')
			return(i);
		else if (tmp[i] == '\n')
		{
			//printf("counter = (%d) , i = (%d), remainging should be --------------------------------><%s>\n" ,counter,i, &tmp[i]);
			while (++i < counter)
			{
				j++;
				remaining[j] = tmp[i]; //saving the rest of the string in static arr to use next time
			//	printf("%c", remaining[j]);
			}
			//printf("remainging buff --------------------------------><%s>\n" ,remaining);
			return(i);
		}
	}
	return (0);
}

/*Takes input as 2 strings and length, output sum of the 2 strings*/
char *ft_strjoin(char *tmp,char *result,int counter)
{
	char	*new;
	int		i;
	int		j;
	
	j = -1;
	//printf("inside strjoin counter is %d\n", counter);
	i = -1;
	new = malloc(counter);
	if(!new)
		return (NULL);	
	while (++i < counter - BUFFER_SIZE)  //copying the tmp arr to the new array
		new[i] = tmp[i];
	i--;
	//printf("new = %s\n", new);
	while (++i < counter + BUFFER_SIZE)  
		new[i] = result[++j];
	//free(tmp);
	//printf("new = %s\n", new);
	return (new);
}