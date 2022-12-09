/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:29:46 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/30 13:09:49 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	copy_array(t_piles *piles)
{
	int	i;

	i = 0;
	while (i < piles->a_size)
	{
		piles->solve[i] = piles->a[i];
		i++;
	}
}

void	solve_array(t_piles *piles)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	copy_array(piles);
	while (i++ < piles->a_size - 1)
	{
		j = -1;
		while (j++ < piles->a_size - 2)
		{
			if (piles->solve[j] > piles->solve[j + 1])
			{
				temp = piles->solve[j];
				piles->solve[j] = piles->solve[j + 1];
				piles->solve[j + 1] = temp;
			}
		}
	}
}
