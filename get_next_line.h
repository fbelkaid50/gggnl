/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:03:28 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/02/06 12:28:46 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_free(char *buf, char **p);
char	*get_next_line(int fd);
void ft_edditline (char *str,char **res, size_t plc);
void ft_addback(char *str,char **res);
size_t		check_line(char *str);
char	*ft_substr(char *str, size_t from, size_t to);
size_t	ft_strlen(char *str);

#endif
