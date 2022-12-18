/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_using_b_piles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:19:39 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/18 00:34:51 by pbergero         ###   ########.fr       */
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
	if (piles->flag)
		pa(piles);
}

int	get_index(t_piles *piles)
{
	int	i;

	i = 0;
	while (i < piles->b_size - 1)
	{
		if (is_pushable(piles, i))
			return (i);
		if (is_pushable(piles, piles->b_size - 1 - i))
			return (piles->b_size - 1 - i);
		i++;
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
	if (piles->step_rb <= piles->smallest_opt)
	{
	piles->current_opt[0] = OPT_RB;
	piles->smallest_opt = piles->step_rb;
	}
	push_a_from_i(piles, i);
	if (piles->flag)
		piles->blocksize[piles->block_nb]--;
}
