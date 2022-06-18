/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:12:54 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/18 14:06:06 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100

# endif
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>//delete it before submission

char *get_next_line(int fd);
