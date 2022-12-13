/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:14:32 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/12 22:39:43 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_reversesorted(int *pile, int size)
{
	int	i;
	int	previous_number;

	i = 1;
	previous_number = pile[0];
	while (i < size)
	{
		if (previous_number < pile[i])
			return (0);
		previous_number = pile[i];
		i++;
	}
	return (1);
}

int	blocked_pushed(t_piles *piles)
{
	int	i;

	i = 0;
	while (i < piles->a_size)
	{
		if (piles->a[i] < piles->mid_nbr[piles->block_nb])
			return (0);
		i++;
	}
	return (1);
}

int	getmax(t_piles *piles)
{
	int	i;
	int	max;
	int	i_max;

	max = INT_MIN;
	i = 0;
	i_max = 0;
	while (i < piles->b_size)
	{
		if (piles->b[i] > max)
		{
			max = piles->b[i];
			i_max = i;
		}
		i++;
	}
	return (i);
}

void	find_mid_nbr(t_piles *piles)
{
	solve_array(piles);
	piles->mid_nbr[piles->block_nb] = piles->solve[piles->a_size / 4];
}
