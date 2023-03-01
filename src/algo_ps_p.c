/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ps_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:16:10 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/12 15:13:52 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_piles *piles)
{
	int	temp;

	if (piles->b_size == 0)
		return ;
	temp = piles->b[0];
	pull_up(piles->b, piles->b_size);
	pull_down(piles->a, piles->a_size, temp);
	piles->b_size--;
	piles->a_size++;
	piles->step = ft_strjoin(piles->step, "pa\n", 1, 0);
}

void	pb(t_piles *piles)
{
	int	temp;

	if (piles->a_size == 0)
		return ;
	temp = piles->a[0];
	pull_up(piles->a, piles->a_size);
	pull_down(piles->b, piles->b_size, temp);
	piles->a_size--;
	piles->b_size++;
	piles->step = ft_strjoin(piles->step, "pb\n", 1, 0);
}

void	pull_up(int *pile, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i] = 0;
}

void	pull_down(int *pile, int size, int nb)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size)
	{
		temp = pile[i];
		pile[i] = nb;
		nb = temp;
		i++;
	}
	pile[i] = nb;
}
