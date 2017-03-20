/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 10:31:40 by bbrunell          #+#    #+#             */
/*   Updated: 2016/02/09 11:51:25 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 32

size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
long int			ft_verifint(const char *str);
char				**ft_strsplit(char const *s, char c);
void				ft_strdel(char **as);
int					get_next_line(int const fd, char **line);
int					ft_check_end(char *s1);

#endif
