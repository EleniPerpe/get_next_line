/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:35:11 by eperperi          #+#    #+#             */
/*   Updated: 2024/04/13 20:05:04 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

char	**ft_split(char const *s, char c, int *i);
void	print(long *a, int len);
int		counter(char const *s, char c);
char	*get_string(char const *s, int i, int len);
char	**calc(char **res, const char *s, char c, int i);
long	ft_atol(char *str);
long	*ft_strdup(long *s1, int len);
long	*create_stack(char **argv, int argc, int *len, int *i);
long	*bubble_sort(long *temp, int len);
long	*index_play(long *temp, int len);
long	*array_iteration(long *temp, long *dup_temp, int len);
long	*commands_time(long *a, int len);
void	sa(long *a, int len);
void	*ft_calloc(size_t count, size_t size);
void	sb(long *b, int len);
void	ss(long *b, long *a, int len);
void	ft_bzero(void *s, size_t a);

#endif