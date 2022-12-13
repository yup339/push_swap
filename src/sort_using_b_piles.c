/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_using_b_piles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:19:39 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/13 01:00:17 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a_from_i(t_piles *piles, int i)
{
	if (i > piles->b_size / 2)
	{
		while (i < piles->b_size)
		{
			i++;
			rrb(piles, piles->flag);
			if (piles->flag)
				piles->offset_b--;
			piles->step_rb++;
		}
	}
	else
	{
		while (i)
		{
			i--;
			rb(piles, piles->flag);
			if (piles->flag)
				piles->offset_b++;
			piles->step_rb++;
		}
	}
	if (piles->flag == 1)
		pa(piles);
}

int	get_index(t_piles *piles)
{
	int	i;

	i = -1;
	if (piles->offset_a)
	{
		while (++i < piles->b_size - 1)
		{
			if (piles->b[i] < piles->a[0]
				&& piles->b[i] > piles->a[piles->a_size - 1])
				return (i);
			if (piles->b[piles->b_size - i] < piles->a[0]
				&& piles->b[piles->b_size - i] > piles->a[piles->a_size - 1])
				return (piles->b_size - i);
		}
	}
	else
	{
		while (++i < piles->b_size - 1)
		{
			if (piles->b[i] < piles->a[0])
				return (i);
			if (piles->b[piles->b_size - i] < piles->a[0])
				return (piles->b_size - i);
		}
	}
	return (-1);
}

void	push_big_from_block(t_piles *piles)
{
	int	i;

	i = get_index(piles);
	if (i == -1)
	{
		piles->step_rb = piles->nb_elem * 10;
		return ;
	}
	push_a_from_i(piles, i);
	if (piles->flag)
		piles->blocksize[piles->block_nb]--;
}
