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

char	*get_next_line(int fd);
char *ft_strjoin(char *tmp, char *reader, int counter, char flag);
int check_null_or_nl(char *tmp, int counter);
char *filler(char *reader, char *tmp, char *result, int fd);
char *check_filled_result(char *result, char *tmp, char *reader, int fd);
char *clean_result(char * result, char *tmp, char *reader, int counter);
char *error_message(char *error);
void null_me(char *reader);
void remaining_fill(char *tmp, char *reader ,int counter);