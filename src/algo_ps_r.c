/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ps_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:09:16 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/30 05:50:05 by pbergero         ###   ########.fr       */
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
	piles->nb_step++;
}

void	rb(t_piles *piles, int flag)
{
	int	temp;

	temp = piles->b[0];
	pull_up(piles->b, piles->b_size);
	piles->b[piles->b_size - 1] = temp;
	if (flag)
		piles->step = ft_strjoin(piles->step, "rb\n", 1, 0);
	piles->nb_step++;
}

void	rr(t_piles *piles, int flagA, int flagB)
{
	if (flagA)
		ra(piles, !flagB);
	if (flagB)
		rb(piles, !flagA);
	if (flagA && flagB)
	{
		piles->nb_step--;
		piles->step = ft_strjoin(piles->step, "rr\n", 1, 0);
	}
}
