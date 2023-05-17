/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:35:24 by mvalient          #+#    #+#             */
/*   Updated: 2022/10/05 10:19:09 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_get_raw_line(int fd, char *extra);
char	*ft_trim_line(char *line);
char	*get_next_line(int fd);
char	*ft_gnl_strchr(const char *s, int c);
int		ft_count_until(int n, const char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(char *ntf, const char *s);

#endif
