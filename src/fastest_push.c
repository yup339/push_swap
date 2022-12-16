/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastest_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:05:43 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/16 05:01:38 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reset_copy(t_piles *piles)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < piles->a_size)
	{
		piles->a[a] = piles->test_a[a];
		a++;
	}
	while (b < piles->b_size)
	{
		piles->b[b] = piles->test_b[b];
		b++;
	}
}

int	is_pushable(t_piles *piles, int i)
{
	if (piles->a[piles->a_size - 1] == piles->max)
	{
		if (piles->a[0] > piles->b[i])
			return (1);
	}
	else
	{
		if (piles->a[0] > piles->b[i]
			&& piles->a[piles->a_size - 1] < piles->b[i])
			return (1);
	}
	return (0);
}

static void	choose_fastest_algo(t_piles *piles)
{
	if (piles->opt == OPT_RA)
		push_using_ra(piles);
	if (piles->opt == OPT_RRA)
		push_using_rra(piles);
	if (piles->opt == OPT_RB)
		push_big_from_block(piles);
	if (piles->opt == OPT_RR)
		push_from_double_rotation(piles);
	if (piles->opt == OPT_RRR)
		push_from_reverse_double_rotation(piles);
	if (piles->opt == OPT_MIX_RA_RRB)
		push_mix_ra_rrb(piles);
	if (piles->opt == OPT_MIX_RRA_RB)
		push_mix_rra_rb(piles);
}

void	fastest_push(t_piles *piles)
{
	piles->step_ra = 0;
	piles->step_rra = 0;
	piles->step_rb = 0;
	piles->step_rr = 0;
	piles->step_rrr = 0;
	piles->step_ra_rrb = 0;
	piles->step_rra_rb = 0;
	piles->flag = 0;
	make_copy(piles);
	test_push(piles, push_using_ra);
	test_push(piles, push_using_rra);
	test_push(piles, push_big_from_block);
	test_push(piles, push_from_double_rotation);
	test_push(piles, push_from_reverse_double_rotation);
	test_push(piles, push_mix_ra_rrb);
	test_push(piles, push_mix_rra_rb);
	reset_copy(piles);
	piles->flag = 1;
	choose_fastest_algo(piles);
}
