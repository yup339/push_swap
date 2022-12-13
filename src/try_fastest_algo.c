/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fastest_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:54:01 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/13 00:39:53 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test_push_ra(t_piles *piles)
{
	reset_copy(piles);
	push_from_fix_rotation(piles);
}

void	test_push_rb(t_piles *piles)
{
	reset_copy(piles);
	push_big_from_block(piles);
}

void	test_push_rr(t_piles *piles)
{
	reset_copy(piles);
	push_from_double_rotation(piles);
}

void	test_push_rrr(t_piles *piles)
{
	reset_copy(piles);
	push_from_reverse_double_rotation(piles);
}
