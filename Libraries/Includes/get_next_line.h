/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:27:15 by emarette          #+#    #+#             */
/*   Updated: 2025/11/08 14:13:05 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*			BUFFER_SIZE			*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

/*			Libraries			*/
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
// # include <stdio.h>

/*			Functions			*/
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int chr);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
