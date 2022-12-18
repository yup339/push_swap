/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 05:28:34 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/17 23:26:24 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	remove_exess_rra(t_piles *piles)
{
	int	nb_rra;

	nb_rra = (piles->step_rra_rb + 1) / 2;
	piles->excess_ra = nb_rra;
	if (!is_pushable(piles, 0) || nb_rra < piles->a_size)
		return ;
	piles->excess_rra = piles->a_size % nb_rra;
}

void	remove_exess_ra(t_piles *piles)
{
	int	nb_ra;

	nb_ra = (piles->step_ra_rrb + 1) / 2;
	piles->excess_ra = nb_ra;
	if (!is_pushable(piles, 0) || nb_ra < piles->a_size)
		return ;
	piles->excess_rra = piles->a_size % nb_ra;
}

void	remove_exess_rrb(t_piles *piles)
{
	int	nb_rrb;

	nb_rrb = (piles->step_ra_rrb) / 2;
	piles->excess_rra = nb_rrb;
	if (!is_pushable(piles, 0) || nb_rrb < piles->b_size)
		return ;
	piles->excess_rrb = piles->b_size % nb_rrb;
}

void	remove_exess_rb(t_piles *piles)
{
	int	nb_rb;

	nb_rb = (piles->step_rra_rb) / 2;
	piles->excess_rb = nb_rb;
	if (!is_pushable(piles, 0) || nb_rb < piles->b_size)
		return ;
	piles->excess_rb = piles->b_size % nb_rb;
}
