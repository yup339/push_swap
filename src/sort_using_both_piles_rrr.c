/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_using_both_piles_rrr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:40:53 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/16 02:29:53 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	do_rrr_util_good(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	while (!is_pushable(piles, 0) && piles->step_rrr < piles->nb_elem)
	{
		rrr(piles, piles->flag, piles->flag);
		offset--;
		piles->step_rrr++;
		if (!is_pushable(piles, 0) && is_pushable(piles, piles->b_size - 1))
		{
			rrb(piles, piles->flag);
			piles->step_rrr++;
			break ;
		}
	}
	if (piles->flag)
		piles->offset_a = offset;
}

void	push_from_reverse_double_rotation(t_piles *piles)
{
	do_rrr_util_good(piles);
	if (piles->step_rrr <= piles->smallest_opt)
	{
	piles->opt = OPT_RRR;
	piles->smallest_opt = piles->step_rrr;
	}
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}
