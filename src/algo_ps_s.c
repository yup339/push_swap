/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ps_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:24:49 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/30 05:50:33 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_piles *piles, int flag)
{
	int	temp;

	if (piles->a_size <= 1)
		return ;
	temp = piles->a[0];
	piles->a[0] = piles->a[1];
	piles->a[1] = temp;
	piles->nb_step++;
	if (flag == 1)
		piles->step = ft_strjoin(piles->step, "sa\n", 1, 0);
}

void	sb(t_piles *piles, int flag)
{
	int	temp;

	if (piles->b_size <= 1)
		return ;
	temp = piles->b[0];
	piles->b[0] = piles->b[1];
	piles->b[1] = temp;
	piles->nb_step++;
	if (flag == 1)
		piles->step = ft_strjoin(piles->step, "sb\n", 1, 0);
}

void	ss(t_piles *piles, int flagA, int flagB)
{
	if (flagA)
		sa(piles, !flagB);
	if (flagB)
		sb(piles, !flagA);
	if (flagA && flagB)
	{
		piles->step = ft_strjoin(piles->step, "ss\n", 1, 0);
		piles->nb_step--;
	}
}
