/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ps_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:14:16 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/07 20:25:24 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_piles *piles, int flag)
{
	pull_down(piles->a, piles->a_size, piles->a[piles->a_size - 1]);
	if (flag == 1)
		piles->step = ft_strjoin(piles->step, "rra\n", 1, 0);
	piles->nb_step++;
}

void	rrb(t_piles *piles, int flag)
{
	pull_down(piles->b, piles->b_size, piles->b[piles->b_size - 1]);
	if (flag == 1)
		piles->step = ft_strjoin(piles->step, "rrb\n", 1, 0);
	piles->nb_step++;
}

void	rrr(t_piles *piles, int flagA, int flagB)
{
	if (flagA)
		rra(piles, !flagB);
	if (flagB)
		rrb(piles, !flagA);
	if (flagA && flagB)
	{
		piles->step = ft_strjoin(piles->step, "rrr\n", 1, 0);
		piles->nb_step--;
	}
}
