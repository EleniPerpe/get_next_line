/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:10:16 by tgmelin           #+#    #+#             */
/*   Updated: 2024/03/29 12:21:23 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_memcpy(char *_dst, char *_src, size_t _size)
{
	size_t	i;

	if (_size == SIZE_MAX)
	{
		_dst++[0] = _src++[0];
		_size--;
	}
	i = 0;
	while (i < _size)
	{
		_dst[i] = _src[i];
		i++;
	}
}

ssize_t	ft_memchr(char *_buffer, char _c, ssize_t _size)
{
	ssize_t	i;

	i = 0;
	while (i < _size && _buffer[i] != _c)
	{
		i++;
	}
	if (_buffer[i] == _c)
		return (i);
	return (-1);
}

void	ft_memclr(char *_mem, size_t _size)
{
	while (_size)
	{
		*_mem++ = 0;
		_size--;
	}
}
