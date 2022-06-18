/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:13:00 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/18 20:48:18 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *result;
	char *tmp;
	
	tmp = NULL;
	result = malloc(BUFFER_SIZE);
	if (!result)
		return(NULL);
	read(fd, result, BUFFER_SIZE);
	if (result[0] == -1 || !*result)
		return (check_err(result, "there is nothing else to read\n"));
	tmp = filler(fd, result, tmp);
	return (tmp);
}

char *memory_cleaner(char *tmp)
{
	//takes tmp, measure the len till \n or \0
	//copy it to new str with exat size 
	//free(tmp) & result &everything else needed.
}