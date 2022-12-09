/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:20:43 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/07 17:46:38 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* if()  1 et 2 | 1 et 3 | 2 et 3 */
void	sort3(t_piles *piles)
{
	int	flag;

	flag = 0;
	if (piles->b[0] < piles->b[1])
		flag = 1;
	if (piles->a[0] > piles->a[1] && piles->a[0] < piles->a[2]
		&& piles->a[1] < piles->a[2])
		ss(piles, 1, flag);
	if (piles->a[0] > piles->a[1] && piles->a[0] > piles->a[2]
		&& piles->a[1] > piles->a[2])
		ss(piles, 1, flag);
	if (piles->a[0] < piles->a[1] && piles->a[0] < piles->a[2]
		&& piles->a[1] > piles->a[2])
		ss(piles, 1, flag);
	if (piles->a[0] > piles->a[1] && piles->a[0] > piles->a[2]
		&& piles->a[1] < piles->a[2])
		ra(piles, 1);
	if (piles->a[0] < piles->a[1] && piles->a[0] > piles->a[2]
		&& piles->a[1] > piles->a[2])
		rra(piles, 1);
}

int	get_right_i(int i1, int i2, int size)
{
	if (i2 < size / 2 && i1 < size / 2 && i1 > i2)
		return (i1);
	if (i2 < size / 2 && i1 < size / 2 && i1 > i2)
		return (i2);
	if (i2 < size / 2 && i1 > size)
		return (i2);
	if (i1 < size / 2 && i2 > size)
		return (i1);
	if (i1 > i2)
		return (i2);
	return (i1);
}

static int	find_closest_index(t_piles *piles)
{
	int	i;

	i = -1;
	piles->min1 = INT_MAX;
	piles->min2 = INT_MAX - 1;
	while (i++ < piles->a_size - 1)
	{
		if (piles->a[i] < piles->min2 || piles->a[i] < piles->min1)
		{
			if (piles->min1 > piles->min2)
			{
				piles->min1 = piles->a[i];
				piles->i1 = i;
			}
			else
			{
				piles->min2 = piles->a[i];
				piles->i2 = i;
			}
		}
	}
	return (get_right_i(piles->i1, piles->i2, piles->a_size));
}

static void	move2smallest(t_piles *piles)
{
	int	i;

	i = find_closest_index(piles);
	push_b_from_i(piles, i);
	i = find_smallest_index(piles);
	push_b_from_i(piles, i);
}

void	small_sort(t_piles *piles)
{
	if (check_sort(piles))
		return ;
	check_rotation(piles);
	if (check_sort(piles))
		return ;
	if (piles->a_size == 5)
		move2smallest(piles);
	if (piles->a_size == 4)
		push_b_from_i(piles, find_smallest_index(piles));
	sort3(piles);
	bring_back_b(piles);
	if (!check_sort(piles))
		sa(piles, 1);
}
