/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:12:54 by ahsalem           #+#    #+#             */
/*   Updated: 2022/06/28 07:19:35 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100

# endif
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>//delete it before submission
#include <string.h>

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void   *ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char *ft_strjoin(char *tmp, char *reader, int counter);
int check_null_or_nl(char *tmp, int counter);
char *filler(char *reader, char *result, int fd);
char *check_filled_result(char *result, char *tmp, char *reader, int fd);
char *clean_result(char * result, char *tmp, char *reader, int counter);
char *error_message(char *error);
void null_me(char *reader);
void remaining_fill(char *tmp, char *reader ,int counter);
int	ft_strlen(char *str);

char * ft_mystrcpy(char *result, char *reader);
