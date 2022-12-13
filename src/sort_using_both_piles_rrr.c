/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_using_both_piles_rrr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:40:53 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/13 00:34:47 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	do_rrr_util_good(t_piles *piles)
{
	int	offset;

	offset = piles->offset_a;
	while (piles->b[0] < piles->a[0]
				&& piles->b[0] > piles->a[piles->a_size - 1])
	{
		if (piles->step_rrr > piles->nb_elem * 2)
			break ;
		rrr(piles, piles->flag, piles->flag);
		offset--;
		piles->step_rrr++;
	}
	if (piles->flag)
		piles->offset_a = offset;
}


void	push_from_reverse_double_rotation(t_piles *piles)
{
	do_rrr_util_good(piles);
	if (piles->flag)
	{
		pa(piles);
		piles->blocksize[piles->block_nb]--;
	}
}
