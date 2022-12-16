/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:16:18 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/15 23:29:10 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	make_copy(t_piles *piles)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < piles->a_size)
	{
		piles->test_a[a] = piles->a[a];
		a++;
	}
	while (b < piles->b_size)
	{
		piles->test_b[b] = piles->b[b];
		b++;
	}
}

void	ft_clean_piles(t_piles *piles)
{
	if (piles)
	{
		if (piles->a)
			free(piles->a);
		if (piles->b)
			free(piles->b);
		if (piles->test_a)
			free(piles->test_a);
		if (piles->test_b)
			free(piles->test_b);
		if (piles->step)
			free (piles->step);
		if (piles->solve)
			free (piles->solve);
		free(piles);
	}
}

int	check_sort(t_piles *piles)
{
	int	i;
	int	previous_number;

	if (piles->a_size != piles->nb_elem)
		return (0);
	i = 1;
	previous_number = piles->a[0];
	while (i != piles->a_size)
	{
		if (previous_number > piles->a[i])
			return (0);
		previous_number = piles->a[i];
		i++;
	}
	return (1);
}

static int	add_numbers(int argc, char **argv, int *pile)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!is_int(argv[i + 1]))
			return (0);
		pile[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (i);
}

t_piles	*ft_make_piles(int argc, char **argv)
{
	t_piles	*piles;

	if (!check_param(argc, argv))
		return (NULL);
	piles = (t_piles *)malloc(sizeof(t_piles));
	piles->a = (int *)malloc(argc * sizeof(int));
	piles->b = (int *)malloc(argc * sizeof(int));
	piles->test_b = (int *)malloc(argc * sizeof(int));
	piles->test_a = (int *)malloc(argc * sizeof(int));
	piles->solve = (int *)malloc(argc * sizeof(int));
	piles->step = ft_calloc(1, 1);
	piles->nb_elem = argc - 1;
	piles->a_size = argc - 1;
	piles->b_size = 0;
	piles->nb_step = 0;
	piles->block_nb = 0;
	if (!piles ||!piles->a || !piles->b || !piles->step || !piles->solve
		|| !add_numbers(argc, argv, piles->a)
		|| !checkdouble(piles->a, piles->a_size))
		return (NULL);
	solve_array(piles);
	piles->max = piles->solve[piles->nb_elem - 1];
	return (piles);
}
