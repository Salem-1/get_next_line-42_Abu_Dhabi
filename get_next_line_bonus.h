/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:12:54 by ahsalem           #+#    #+#             */
/*   Updated: 2022/07/24 11:23:13 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_mystrcpy(char *result, char *reader);
char	*ft_strjoin(char *tmp, char *reader, int counter);
int		isnl(char *tmp, int counter);
char	*filler(char *reader, char *result, int fd);
void	null_me(char *reader);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*f(int read_len, int fd, char *reader, char *result);
void	fill_reader(char *reader, char *tmp);

#endif