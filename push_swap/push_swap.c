/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:44:48 by eperperi          #+#    #+#             */
/*   Updated: 2024/04/13 20:06:53 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(long *a, int len);
long	*create_stack(char **argv, int argc, int *len, int *i);
long	*bubble_sort(long *temp, int len);
long	*index_play(long *temp, int len);
long	*array_iteration(long *temp, long *dup_temp, int len);
long	*commands_time(long *a, int len);

int	main(int argc, char **argv)
{
	char	**stack_a;
	int		i;
	long	*temp;
	long	*dup_temp;
	int		len;

	temp = create_stack(argv, argc, &len, &i);
	print(temp, len);
	dup_temp = ft_strdup(temp, len);
	temp = bubble_sort(temp, len);
	dup_temp = array_iteration(temp, dup_temp, len);
	print(dup_temp, len);
	commands_time(dup_temp, len);
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
	printf("\n");
}

long	*create_stack(char **argv, int argc, int *len, int *i)
{
	long	*temp;
	char	**stack_a;

	if (argc == 2)
		stack_a = ft_split(argv[1], ' ', i);
	else
	{
		stack_a = (char **)malloc(argc * sizeof(char *));
		if (stack_a == NULL)
			return (0);
		*i = 0;
		while ((*i) < argc - 1)
		{
			stack_a[*i] = argv[*i + 1];
			(*i)++;
		}
		stack_a[argc] = NULL;
	}
	temp = (long *)malloc(*i * sizeof(long));
	if (temp == NULL)
		return (0);
	*len = *i;
	while (--(*i) > -1)
		temp[*i] = ft_atol(stack_a[*i]);
	return (temp);
}

long	*bubble_sort(long *temp, int len)
{
	int	i;
	int	j;
	int	swap;
	int	flag;

	i = 0;
	while (i++ < len - 1)
	{
		j = 0;
		flag = 0;
		while (j < len - i)
		{
			if (temp[j] > temp[j + 1])
			{
				swap = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = swap;
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			break ;
	}
	return (temp);
}

long	*array_iteration(long *temp, long *dup_temp, int len)
{
	int		i;
	int		j;
	long	*result;

	result = (long *)malloc (len * sizeof(long));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (dup_temp[i] != temp[j])
			j++;
		result[i] = j;
		i++;
	}
	return (result);
}

long	*commands_time(long *a, int len)
{
	long	*b;

	b = (long *) ft_calloc(len, sizeof(long));
	if (b == NULL)
		return (NULL);
	// sa(a, len);
	print(a, len);
	return (a);
}
