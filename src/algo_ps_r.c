/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ps_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:09:16 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/12 15:13:26 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_piles *piles, int flag)
{
	int	temp;

	temp = piles->a[0];
	pull_up(piles->a, piles->a_size);
	piles->a[piles->a_size - 1] = temp;
	if (flag)
		piles->step = ft_strjoin(piles->step, "ra\n", 1, 0);
}

void	rb(t_piles *piles, int flag)
{
	int	temp;

	temp = piles->b[0];
	pull_up(piles->b, piles->b_size);
	piles->b[piles->b_size - 1] = temp;
	if (flag)
		piles->step = ft_strjoin(piles->step, "rb\n", 1, 0);
}

void	rr(t_piles *piles, int flagA, int flagB)
{
	if (flagA)
		ra(piles, !flagB);
	if (flagB)
		rb(piles, !flagA);
	if (flagA && flagB)
	{
		piles->step = ft_strjoin(piles->step, "rr\n", 1, 0);
	}
	if (!flagA && !flagB)
	{
		ra(piles, 0);
		rb(piles, 0);
	}
}
