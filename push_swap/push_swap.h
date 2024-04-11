/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:35:11 by eperperi          #+#    #+#             */
/*   Updated: 2024/04/11 23:52:12 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

char	**ft_split(char const *s, char c);
void	print(long *a, int len);
size_t	ft_strlen(const char *s);
int		counter(char const *s, char c);
char	*get_string(char const *s, int i, int len);
char	**calc(char **res, const char *s, char c, int i);
long	ft_atol(char *str);

#endif