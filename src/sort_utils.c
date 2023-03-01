/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:20:54 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/12 15:12:45 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	in_order(int *pile, int size)
{
	int	i;
	int	previous_number;

	i = 1;
	previous_number = pile[0];
	while (i < size)
	{
		if (previous_number > pile[i])
			return (0);
		previous_number = pile[i];
		i++;
	}
	return (1);
}

void	bring_back_b(t_piles *piles)
{
	while (piles->b_size)
		pa(piles);
}

int	find_smallest_index(t_piles *piles)
{
	int	i;
	int	index_small_nb;
	int	smallest;

	i = 0;
	smallest = piles->a[0];
	index_small_nb = 0;
	while (i < piles->a_size)
	{
		if (smallest > piles->a[i])
		{
			smallest = piles->a[i];
			index_small_nb = i;
		}
		i++;
	}
	return (index_small_nb);
}

void	push_b_from_i(t_piles *piles, int i)
{
	if (i > piles->a_size / 2)
	{
		while (i < piles->a_size)
		{
			i++;
			rra(piles, 1);
		}
	}
	else
	{
		while (i)
		{
			i--;
			ra(piles, 1);
		}
	}
	pb(piles);
}

void	check_rotation(t_piles *piles)
{
	int	i;

	i = 1;
	while (i <= piles->a_size / 2)
	{
		ra(piles, 1);
		if (check_sort(piles))
			return ;
		i++;
	}
	i = 1;
	free(piles->step);
	piles->step = ft_calloc(1, 1);
	while (i <= piles->a_size / 2)
	{
		rra(piles, 1);
		if (check_sort(piles))
			return ;
		i++;
	}
	free(piles->step);
	piles->step = ft_calloc(1, 1);
}
