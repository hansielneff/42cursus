/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:51:45 by helneff           #+#    #+#             */
/*   Updated: 2023/01/25 10:03:28 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "instructions.h"
#include "solutions.h"
#include "short_sort.h"
#include "radix_sort.h"

static int	check_duplicates(char *input[], size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

static size_t	determine_input_size(int argc, char *input[])
{
	size_t	size;

	if (argc < 2)
		exit(1);
	else if (argc > 2)
		size = argc - 1;
	else
	{
		size = 0;
		while (*(input++))
			++size;
	}
	return (size);
}

static char	**parse_input(int argc, char *argv[], size_t *out_size)
{
	char	**input;
	size_t	i;
	int		sign;
	char	*itoa_cmp;

	input = argv + 1;
	if (argc == 2)
		input = ft_split(*input, ' ');
	*out_size = determine_input_size(argc, input);
	i = 0;
	while (i < *out_size)
	{
		itoa_cmp = ft_itoa(ft_atoi(input[i]));
		sign = (input[i][0] == '-' || input[i][0] == '+');
		if (ft_strlen(input[i]) - sign != ft_digitsl(ft_atoi(input[i]), 10)
			|| !ft_isdigit(input[i][sign]) || check_duplicates(input, *out_size)
			|| ft_strncmp(input[i], itoa_cmp, ft_strlen(input[i])))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		free(itoa_cmp);
		++i;
	}
	return (input);
}

static void	free_input(char	**input, int argc, size_t size)
{
	if (argc == 2)
	{
		while (size-- > 0)
			free(input[size]);
		free(input);
	}
}

int	main(int argc, char	*argv[])
{
	char	**input;
	size_t	size;
	t_stack	*a;
	t_list	*solution;

	if (argc < 2)
		return (1);
	input = parse_input(argc, argv, &size);
	if (*input == NULL)
		return (1);
	a = create_stack(input, size);
	if (!is_sorted(a, 0))
	{
		convert_stack_positional(a, size);
		if (size <= 5)
			solution = short_sort(&a, NULL, size);
		else
			solution = radix_sort(&a, NULL, size);
		ft_lstiter(solution, print_solution);
		ft_lstclear(&solution, free_solution);
	}
	free_stack(&a);
	free_input(input, argc, size);
	return (0);
}
