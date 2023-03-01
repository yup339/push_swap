/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_using_a_piles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:20:22 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/12 15:00:31 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	make_ccw_rotation(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	piles->step_ra = 0;
	while (!is_pushable(piles, 0) && piles->step_ra < piles->a_size)
	{
		ra(piles, piles->flag);
		offset++;
		if (offset == piles->a_size - 1)
			offset = 0;
		piles->step_ra++;
	}
	if (piles->flag)
		piles->offset_a = offset;
}

static void	make_cw_rotation(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	piles->step_rra = 0;
	while (!is_pushable(piles, 0) && piles->step_rra < piles->a_size)
	{
		rra(piles, piles->flag);
		offset--;
		if (-offset == piles->a_size - 1)
			offset = 0;
		piles->step_rra++;
	}
	if (piles->flag)
		piles->offset_a = offset;
}

void	push_using_ra(t_piles *piles)
{
	make_ccw_rotation(piles);
	piles->current_deep_count += piles->step_ra;
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}

void	push_using_rra(t_piles *piles)
{
	make_cw_rotation(piles);
	piles->current_deep_count += piles->step_rra;
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}
