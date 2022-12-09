/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 05:44:06 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/08 19:25:14 by pbergero         ###   ########.fr       */
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

void	update_rotation(t_piles *piles)
{
	if (piles->a[0] < piles->target)
	{
		while (piles->a[0] < piles->target)
		{
			ra(piles, 1);
			piles->offset++;
		}
	}
	while (piles->target > piles->a[piles->a_size - 1] && piles->offset)
	{
		rra(piles, 1);
		piles->offset--;
	}
}

static void	push_big_from_block(t_piles *piles)
{
	int	index;
	int	flag;

	piles->i1 = 0;
	piles->i2 = 0;
	index = get_big_index(piles);
	piles->target = piles->b[index];
	//update_rotation(piles);
	push_a_from_i(piles, index);
	piles->blocksize[piles->block_nb]--;
}

static void	sort_block(t_piles *piles)
{
	int	flag;

	flag = 0;
	if (!piles->blocksize[piles->block_nb])
		return ;
	push_big_from_block(piles);
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
		piles->offset = 0;
		sort_block(piles);
		piles->block_nb--;
	}
}
