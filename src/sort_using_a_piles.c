/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_using_a_piles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:20:22 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/12 23:47:26 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	make_ccw_rotation(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	while (piles->target > piles->a[0])
	{
		ra(piles, piles->flag);
		offset++;
		piles->step_ra++;
	}
	if (piles->flag)
		piles->offset_a = offset;
}

static void	make_cw_rotation(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	while ((piles->target < piles->a[0]
			&& piles->target < piles->a[piles->a_size - 1]) && offset)
	{
		rra(piles, piles->flag);
		offset--;
		piles->step_ra++;
	}
	if (piles->flag)
		piles->offset_a = offset;
}

void	update_rotation(t_piles *piles)
{
	if ((piles->target < piles->a[0]
			&& piles->target < piles->a[piles->a_size - 1]) && piles->offset_a)
		make_cw_rotation(piles);
	else
		make_ccw_rotation(piles);
}

void	push_from_fix_rotation(t_piles *piles)
{
	piles->target = piles->b[0];
	update_rotation(piles);
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}
