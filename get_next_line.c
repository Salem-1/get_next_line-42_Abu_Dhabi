/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:13:00 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/19 07:30:07 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//start your program with the remaining str instead of tmp, check it, 
//if !(\n || \0) call the read and do your job 
char *get_next_line(int fd)
{
	char		*result;
	char		*tmp;
	static char	*remaining;
	
	result = malloc(BUFFER_SIZE);
	if (!result)
		return(NULL);
	//read(fd, result, BUFFER_SIZE);
	//if (result[0] == -1 || !*result)
		//return (check_err(result, "there is nothing else to read\n"));
	tmp = filler(fd, result, remaining);
	return (tmp);
}

// char *memory_cleaner(char *tmp, static char *remaining)
// {
// 	//takes tmp, measure the len till \n or \0, clean the remainig at the null termination or the end of it 
// 	//copy it to new str with exat size 
// 	//free(tmp) & result &everything else needed.
// }