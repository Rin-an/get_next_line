/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <ssadiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:00:37 by ssadiki           #+#    #+#             */
/*   Updated: 2022/03/24 19:53:21 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		is_nl(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_line(char *s);
char	*ft_keep(char *s);
char	*ft_read(char *s, int fd);
#endif
