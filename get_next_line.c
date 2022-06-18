/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:13:00 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/18 14:29:48 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int line_len(int fd);
void fill_result(int fd, char *resutl);

char *get_next_line(int fd)
{
//if the fd changed before programend, give undefined behaviour, (Don't handlei)
	int x;
	char *result;

	//if (bad_line)
	//	return err_message();
	x = line_len(fd);
	printf("len = %d\n", x);
	
	result = malloc(x);
	if (!result)
		return(NULL);
	fill_result(fd, result);
	return (result);

}

//end with this
void fill_result(int fd, char *result)
{
	read(fd, result, BUFFER_SIZE);	
}

//start with this, 
//loop over the line till you reach the /n or EOF
//if no \0, you allocate + 1 for \0
	
int line_len(int fd)
{
	int	x;
	char *tmp;
	
	tmp = malloc(1);
	x = 0;
	if (!tmp)
		return(0);
	read(fd, tmp, 1);
	
	if (fd == -1)
		return(0);
	while(*tmp != '\n' && *tmp != -1)
	{
		x++;
		read(fd, tmp, 1);
		printf("<%s>\n", tmp);	
	}
	free(tmp);
	return (x);
}
