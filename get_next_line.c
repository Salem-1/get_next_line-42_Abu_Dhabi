/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:13:00 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/18 18:39:41 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *result;
	
	result = malloc(BUFFER_SIZE);
	if (!result)
		return(NULL);
	read(fd, result, BUFFER_SIZE);
	if (result[0] == -1 || !*result)
		return (check_err(result, "there is nothing else to read\n"));
		
	return (result);
}
