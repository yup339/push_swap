/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_sort_ra_rb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:17:53 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/20 10:05:10 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	tested_all(t_piles *piles, int iter)
{
	if (iter == 0)
		return (0);
	if (piles->a[0] == piles->test_a[0]
		&& piles->b[0] == piles->test_b[0])
		return (1);
	return (0);
}

static void	do_ra_rrb_util_good(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	piles->step_ra_rrb = 0;
	while (!is_pushable(piles, 0) && !tested_all(piles, piles->step_ra_rrb))
	{
		if (piles->excess_ra)
		{
			ra(piles, piles->flag);
			piles->excess_ra--;
			offset++;
			piles->step_ra_rrb++;
		}
		if (!is_pushable(piles, 0) && piles->excess_rrb)
		{
			rrb(piles, piles->flag);
			piles->excess_rrb--;
			piles->step_ra_rrb++;
		}
		if (piles->flag)
		piles->offset_a = offset;
	}
}

void	push_mix_ra_rrb(t_piles *piles)
{
	do_ra_rrb_util_good(piles);
	//remove_exess_ra(piles);
	//remove_exess_rrb(piles);
	//piles->step_ra_rrb = piles->excess_ra + piles->excess_rrb;
	piles->current_deep_count += piles->step_ra_rrb;
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
	piles->step_rra_rb = 0;
	while (!is_pushable(piles, 0) && !tested_all(piles, piles->step_rra_rb))
	{
		if (piles->excess_rra)
		{
			rra(piles, piles->flag);
			piles->excess_rra--;
			offset--;
			piles->step_rra_rb++;
		}
		if (!is_pushable(piles, 0) && piles->excess_rb)
		{
			rb(piles, piles->flag);
			piles->step_rra_rb++;
			piles->excess_rb--;
		}
		if (piles->flag)
		piles->offset_a = offset;
	}
}

void	push_mix_rra_rb(t_piles *piles)
{
	do_rra_rb_util_good(piles);
	//remove_exess_rra(piles);
	//remove_exess_rb(piles);
	//piles->step_rra_rb = piles->excess_rra + piles->excess_rb;
	piles->current_deep_count += piles->step_rra_rb;
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}
