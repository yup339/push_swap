/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:24:01 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/16 03:03:24 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	checkdouble(int *pile, int size)
{
	int	nbr;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		nbr = pile[i];
		j = i + 1;
		while (j < size)
		{
			if (nbr == pile[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int(char *nb)
{
	long	n;

	n = ft_long_atoi(nb);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

int	check_param(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i] != NULL)
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fix_rotation(t_piles *piles)
{
	int	i;
	int	smallest;

	i = find_smallest_index(piles);
	smallest = piles->a[i];
	if (i > piles->a_size / 2)
		while (piles->a[0] != smallest)
			rra(piles, 1);
	else
		while (piles->a[0] != smallest)
			ra(piles, 1);
}

int	main(int argc, char **argv)
{
	t_piles	*piles;

	piles = ft_make_piles(argc, argv);
	if (!piles)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (piles->nb_elem <= SMALL_SORT_LIMITS)
		small_sort(piles);
	else
		big_sort(piles);
	fix_rotation(piles);
	ft_printf("%s", piles->step);
	ft_clean_piles(piles);
	return (1);
}
