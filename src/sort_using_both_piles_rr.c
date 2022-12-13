/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_using_both_piles_rr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:50:51 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/13 00:33:11 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	do_rr_util_good(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	while (piles->b[0] > piles->a[0] && offset > piles->nb_elem * 2)
	{
		rr(piles, piles->flag, piles->flag);
		offset++;
		piles->step_ra++;
	}
	if (piles->flag)
		piles->offset_a = offset;
}

void	push_from_double_rotation(t_piles *piles)
{
	do_rr_util_good(piles);
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}
