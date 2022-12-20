/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_using_both_piles_rr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:50:51 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/20 10:03:29 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	do_rr_util_good(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	piles->step_rr = 0;
	while (!is_pushable(piles, 0) && piles->step_rr <= piles->nb_elem)
	{
		rr(piles, piles->flag, piles->flag);
		piles->step_rr++;
		offset++;
		if (!is_pushable(piles, 0) && is_pushable(piles, 1))
		{
			rb(piles, piles->flag);
			piles->step_rr++;
			break ;
		}
	}
	if (piles->flag)
		piles->offset_a = offset;
}

void	push_from_double_rotation(t_piles *piles)
{
	do_rr_util_good(piles);
	piles->current_deep_count += piles->step_rr;
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}
