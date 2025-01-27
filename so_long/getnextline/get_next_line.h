/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:29:39 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:01 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000000
# endif

char	*ftr_strdup(const char *src);
char	*get_next_line(int fd);
char	*ftr_strjoin(char *s1, char *s2);
size_t	ftr_strlen(const char *c);
char	*ftr_strchr(const char *str, int n);
size_t	ftr_strlcat(char *dst, char *src, size_t size);
size_t	ftr_strlcpy(char *dst, char *src, size_t size);

#endif
