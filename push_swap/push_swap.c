/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:44:48 by eperperi          #+#    #+#             */
/*   Updated: 2024/04/12 00:45:15 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(long *a, int len);
long	*make_stack(char **argv, int argc, int *len, int i);

int	main(int argc, char **argv)
{
	char	**stack_a;
	int		i;
	long	*temp;
	int		len;

	i = 0;
	len = 0;
	stack_a = NULL;
	temp = make_stack(argv, argc, &len, 0);
	print(temp, len);
	free (temp);
	return (0);
}

void	print(long *a, int len)
{
	int	i;
	int	num;

	i = 0;
	while (i < len)
	{
		printf("%ld\n", a[i]);
		i++;
	}
}

long	*make_stack(char **argv, int argc, int *len, int i)
{
	long	*temp;
	char	**stack_a;

	if (argc == 2)
	{
		stack_a = ft_split(argv[1], ' ');
		while (stack_a[i])
			i++;
	}
	else
	{
		stack_a = (char **)malloc(argc * sizeof(char *));
		if (stack_a == NULL)
			return (0);
		i = 0;
		while (i < argc - 1)
		{
			stack_a[i] = argv[i + 1];
			i++;
		}
		stack_a[argc] = NULL;
	}
	temp = (long *)malloc(i * sizeof(long));
	if (temp == NULL)
		return (0);
	*len = i;
	while (--i > -1)
		temp[i] = ft_atol(stack_a[i]);
	return (temp);
}
