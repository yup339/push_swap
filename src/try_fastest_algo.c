/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fastest_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:54:01 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/18 00:30:41 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test_push(t_piles *piles, void (*f)(t_piles *piles), int flag)
{
	if (flag)
		reset_copy(piles);
	f(piles);
}

void	reset_counters(t_piles *piles)
{
	piles->step_ra = 0;
	piles->step_rra = 0;
	piles->step_rb = 0;
	piles->step_rr = 0;
	piles->step_rrr = 0;
	piles->step_ra_rrb = 0;
	piles->step_rra_rb = 0;
	piles->flag = 0;
	piles->excess_ra = piles->nb_elem * piles->nb_elem;
	piles->excess_rb = piles->nb_elem * piles->nb_elem;
	piles->excess_rrb = piles->nb_elem * piles->nb_elem;
	piles->excess_rra = piles->nb_elem * piles->nb_elem;
}
