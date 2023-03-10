/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:03:37 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 16:34:09 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_3(char *s);
void	ft_bzero_2(void *str, size_t len);
void	*ft_calloc_2(size_t count, size_t size);
char	*ft_strchr_2(char *str, char c);
void	ft_strlcpy_2(char *dest, char *src, size_t len);

char	*ft_substr_2(char *src, size_t start, size_t lenth);
char	*ft_strjoin_2(char *s1, char *s2);
char	*ft_read_line(char *tmp, int fd);
char	*ft_turncate_line(char *tmp, char **line);
void	tmp_free(char **tmp);

char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif