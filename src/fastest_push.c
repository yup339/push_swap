/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastest_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:05:43 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/13 01:02:08 by pbergero         ###   ########.fr       */
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

/*static void	choose_fastest_algo(t_piles *piles)
{
	if (piles->step_ra <= piles->step_rb && piles->step_ra <= piles->step_rr
		&& piles->step_ra <= piles->step_rrr)
		push_from_fix_rotation(piles);
	else if (piles->step_rb <= piles->step_ra
		&& piles->step_rb <= piles->step_rr
		&& piles->step_rb <= piles->step_rrr)
		push_big_from_block(piles);
	else if (piles->step_rr <= piles->step_ra
		&& piles->step_rr <= piles->step_rb
		&& piles->step_rr <= piles->step_rrr)
		push_from_fix_rotation(piles);
	else
		push_from_fix_rotation(piles);
}
*/
static void	choose_fastest_algo2(t_piles *piles)
{
	if (piles->step_ra <= piles->step_rb)
		push_from_fix_rotation(piles);
	else
		push_big_from_block(piles);
}

void	fastest_push(t_piles *piles)
{
	piles->step_ra = 0;
	piles->step_rb = 0;
	piles->step_rr = 0;
	piles->step_rrr = 0;
	piles->flag = 0;
	make_copy(piles);
	test_push_ra(piles);
	test_push_rb(piles);
	test_push_rr(piles);
	test_push_rrr(piles);
	reset_copy(piles);
	piles->flag = 1;
	choose_fastest_algo2(piles);
}
