/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 05:44:06 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/12 22:45:17 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	element_search_close_front(t_piles *piles)
{
	int	i;

	i = 0;
	while (i <= piles->a_size / 2)
	{
		if (piles->a[i] < piles->mid_nbr[piles->block_nb])
			return (1);
		if (piles->a[piles->a_size - i - 1] < piles->mid_nbr[piles->block_nb])
			return (0);
		i++;
	}
	return (0);
}

static void	splitlist(t_piles *piles)
{
	if (blocked_pushed(piles))
		return ;
	if (piles->mid_nbr[piles->block_nb] > piles->a[0])
	{
		piles->blocksize[piles->block_nb]++;
		pb(piles);
		splitlist(piles);
		return ;
	}
	if (element_search_close_front(piles))
	{
		while (piles->mid_nbr[piles->block_nb] <= piles->a[0])
			ra(piles, 1);
	}
	else
	{
		while (piles->mid_nbr[piles->block_nb] <= piles->a[0])
			rra(piles, 1);
	}
	splitlist(piles);
}

static void	sort_block(t_piles *piles)
{
	int	flag;

	flag = 0;
	if (!piles->blocksize[piles->block_nb])
		return ;
	fastest_push(piles);
	sort_block(piles);
}

void	big_sort(t_piles *piles)
{
	if (check_sort(piles))
		return ;
	check_rotation(piles);
	if (check_sort(piles))
		return ;
	while (piles->a_size > 3)
	{
		piles->block_nb++;
		find_mid_nbr(piles);
		splitlist(piles);
	}
	if (piles->a_size == 3)
		sort3(piles);
	else if (piles->a[0] > piles->a[1])
		sa(piles, 1);
	while (piles->block_nb)
	{
		piles->offset_a = 0;
		piles->offset_b = 0;
		fix_rotation(piles);
		sort_block(piles);
		piles->block_nb--;
	}
}
