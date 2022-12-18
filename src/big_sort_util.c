/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:14:32 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/16 06:42:51 by pbergero         ###   ########.fr       */
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
	int	i;
	int	group_size;

	if (piles->nb_elem >= 500)
		group_size = GROUP_500;
	else
		group_size = GROUP_100;
	i = piles->a_size / group_size;
	solve_array(piles);
	piles->mid_nbr[piles->block_nb] = piles->solve[i];
}

void	push_but_top3(t_piles *piles)
{
	piles->block_nb++;
	while (piles->a_size > 3)
	{
		if (piles->a[0] < piles->solve[piles->nb_elem - 3])
		{
			pb(piles);
			piles->blocksize[piles->block_nb]++;
		}
		else
			ra(piles, 1);
	}
}
