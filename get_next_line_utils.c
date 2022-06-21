/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:11:35 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/21 07:46:27 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char * fill_remaining(char * tmp, char *remaining, int counter, int i);
void clean_tmp(char *tmp, int i);
char *ft_strjoin(char *tmp,char *result,int counter, int   i);
int check_nl_or_null(char *tmp, int counter,char *remaining);

//reprocess the filler if it's still full
//mdify the fill remainging part for the remaning of remaining, how about swap function to swap the tmp and remaining
//of remaining, why not ??!!
char  *filler(int fd, char *result, char *tmp)
{
	int		counter;
	static char *remaining;
	
	printf("starting the filler , remaining is %s", remaining);
	
	counter = BUFFER_SIZE;
	//while(++i < BUFFER_SIZE)
	//	tmp[i] = result[i];
	
	printf("filler\n");
	
	if(check_nl_or_null(remaining, counter, tmp) > 0)
	{
		printf("remaining is already full\n");
		
		tmp = ft_strjoin(remaining, "", BUFFER_SIZE + 1, -1);
		
		//printf("##################before ending FILLER, tmp is <%s>\n", tmp);
		
		remaining = fill_remaining(tmp, remaining, counter, check_nl_or_null(tmp, counter, remaining));
		clean_tmp(tmp,0);
		return (tmp);
	}
	
	printf("remaining is empty, starting from beginging\n");
	
	read(fd, result, BUFFER_SIZE);
	tmp = ft_strjoin(result, "", counter + 1, -1);
	int iter = 0;
	//I believe you can use recursion instead of the code below
	//Keep filling untill you reach null then retrun
	while (!check_nl_or_null(tmp, counter  , remaining)) //I belive the bug in counter
	{
		
		//counter += BUFFER_SIZE;
		read(fd, result, BUFFER_SIZE);
		
		printf("filling the tmp loop remaning is empty, the %dth iteration@@@@@result = %s\n", ++iter, result);
		
		tmp = ft_strjoin(tmp, result, counter, -1); //counter is the new malloc
		counter += BUFFER_SIZE;
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
	

	printf("tmp = %s | insidde check_null&\n", tmp);
	while (++i < counter)
	{
		//printf("tmp[%d] = %c\n", i, tmp[i]);
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
	printf("inside strjoin tmp = <%s>, result = <%s>, counter = %d\n", tmp, result, counter);
	char	*new;
	int		j;
	
	i = -1;
	j = -1;
	new = malloc(counter);
	if(!new)
	{
		printf("WTH new is NULL");
		return (NULL);
	}
	while (++i < counter - 1 ) 
	{
		new[i] = tmp[i];
		printf("\ni = %d,  clacl = %d ,%c",i,  i,tmp[ i]);
	}
	i--;
	if (counter - 1 != BUFFER_SIZE)
	{
		printf("inside strjoing reaminign is empty\n");
		while (++i < counter + BUFFER_SIZE)  
			new[i] = result[++j];
	}
	printf("HEY!!!!!! new = %s\n", new);
	return (new);
}