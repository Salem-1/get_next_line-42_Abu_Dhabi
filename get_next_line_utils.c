/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:11:35 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/19 20:18:59 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char * fill_remaining(char * tmp, char *remaining, int counter, int i);
void clean_tmp(char *tmp, int i);
char *ft_strjoin(char *tmp,char *result,int counter, int   i);
int check_nl_or_null(char *tmp, int counter,char *remaining);



char  *filler(int fd, char *result)
{
	int		counter;
	char	*tmp;
	static char *remaining;
	
	printf("starting the filler , remaining is %s", remaining);
	counter = BUFFER_SIZE;
	tmp = NULL;
	//while(++i < BUFFER_SIZE)
	//	tmp[i] = result[i];
	printf("filler\n");
	if(check_nl_or_null(remaining, counter, tmp) > 0)
	{
		printf("remaining is already full\n");
		tmp = ft_strjoin(remaining, "", BUFFER_SIZE, -1);
		//printf("##################before ending FILLER, tmp is <%s>\n", tmp);
		clean_tmp(tmp,0);
		return (tmp);
	}
	
	printf("remaining is empty, starting from beginging\n");
	read(fd, result, BUFFER_SIZE);
	tmp = ft_strjoin(result, "", counter + 1, -1);
	
	while (!check_nl_or_null(tmp, counter, remaining))
	{
		printf("filling the tmp loop remaning is empty\n");
		counter += BUFFER_SIZE;
		read(fd, result, BUFFER_SIZE);
		tmp = ft_strjoin(tmp, result, counter, -1); //counter is the new malloc
	}

	printf("nulling tmp and return it back to get_next_line(fd)\n");
	//tmp[counter] = '\0';
	remaining = fill_remaining(tmp, remaining, counter, check_nl_or_null(tmp, counter, remaining));
	printf("##################before ending FILLER, remaining is <%s>\n", remaining);

	clean_tmp(tmp, 0);

	return (tmp);
}

char * fill_remaining(char * tmp, char *remaining, int counter, int i)
{
	int	j;

	j = -1;
	remaining = malloc(BUFFER_SIZE);
	if (!remaining)
		i = counter;
	//check for the NULL later
	//printf("counter = (%d) , i = (%d), remainging should be --------------------------------><%s>\n" ,counter,i, &tmp[i]);
	while (++i < counter)
	{
		j++;
		remaining[j] = tmp[i]; 	
	}
	printf("remainging buff ---------------------><%s>\n" ,remaining);
	return (remaining);
}

/*clean the extra memory in tmp after the /n or \0*/
void clean_tmp(char *tmp, int i)
{
	printf("inside clean tmp\n");
	//printf("tmp is <%s>", tmp);
	while(tmp[i])
	{
		printf("inside the cleaner tmp[%d] = %c", i, tmp[i]);
		if (tmp[i] == '\n')
			{
				printf("found new line, putting null after it\n");
				tmp[i+ 1] = '\0';
				break;
			}
			i++;
	}
}

int check_nl_or_null(char *tmp, int counter,char *remaining)
{
	
	int					i;
	i = -1;
	printf("checking null or new line\n");
	if (remaining == NULL && tmp == NULL)
		return (0);
	

	//printf("tmp = %s\n", tmp);
	while (++i < counter)
	{
		if (tmp[i] == '\0')
			return(i);
		else if (tmp[i] == '\n')
		{
			return(i);
		}
	}
	return (0);
}

/*Takes input as 2 strings and length, output sum of the 2 strings*/
char *ft_strjoin(char *tmp,char *result,int counter, int i)
{
	printf("inside strjoin\n");
	char	*new;
	int		j;
	
	j = -1;
	new = malloc(counter);
	if(!new)
		return (NULL);
	while (++i < BUFFER_SIZE ) 
	{
		new[i] = tmp[counter - BUFFER_SIZE   + i];
		printf("\ni = %d ,%c", counter - BUFFER_SIZE  + i,tmp[counter - BUFFER_SIZE  + i]);
	}
	i--;
	if (counter != BUFFER_SIZE)
	{
		printf("inside strjoing reaminign is empty\n");
		while (++i < counter + BUFFER_SIZE)  
			new[i] = result[++j];
	}
	return (new);
}