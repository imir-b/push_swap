/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:28:50 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 17:48:18 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_gnl_strlen(const char *str);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strndup(char *src, size_t n);
char	*ft_gnl_realloc(char *s1, char *s2);
char	*ft_add_to_stash(int fd, char *stash, int *end);
char	*ft_clean_stash(char **stash);
char	*get_next_line(int fd);

#endif
