/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_sort_ra_rb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:17:53 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/16 05:00:16 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	do_ra_rrb_util_good(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	while (!is_pushable(piles, 0) && piles->step_ra_rrb <= piles->nb_elem)
	{
		ra(piles, piles->flag);
		piles->step_ra_rrb++;
		offset++;
		if (!is_pushable(piles, 0))
		{
			rrb(piles, piles->flag);
			piles->step_ra_rrb++;
		}
		if (piles->flag)
		piles->offset_a = offset;
	}
}

void	push_mix_ra_rrb(t_piles *piles)
{
	do_ra_rrb_util_good(piles);
	if (piles->step_ra_rrb < piles->smallest_opt)
	{
	piles->opt = OPT_MIX_RA_RRB;
	piles->smallest_opt = piles->step_ra_rrb;
	}
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}

static void	do_rra_rb_util_good(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	while (!is_pushable(piles, 0) && piles->step_rra_rb <= piles->nb_elem)
	{
		rra(piles, piles->flag);
		piles->step_rra_rb++;
		offset--;
		if (!is_pushable(piles, 0))
		{
			rb(piles, piles->flag);
			piles->step_rra_rb++;
		}
		if (piles->flag)
		piles->offset_a = offset;
	}
}

void	push_mix_rra_rb(t_piles *piles)
{
	do_rra_rb_util_good(piles);
	if (piles->step_rra_rb < piles->smallest_opt)
	{
	piles->opt = OPT_MIX_RRA_RB;
	piles->smallest_opt = piles->step_rra_rb;
	}
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}
