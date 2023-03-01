/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fastest_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:54:01 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/19 14:42:10 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reset_counters(t_piles *piles)
{
	piles->step_ra = 0;
	piles->step_rra = 0;
	piles->step_rb = 0;
	piles->step_rr = 0;
	piles->step_rrr = 0;
	piles->step_ra_rrb = 0;
	piles->step_rra_rb = 0;
	piles->flag = 0;
	piles->excess_ra = piles->nb_elem * piles->nb_elem;
	piles->excess_rb = piles->nb_elem * piles->nb_elem;
	piles->excess_rrb = piles->nb_elem * piles->nb_elem;
	piles->excess_rra = piles->nb_elem * piles->nb_elem;
}

static void	update_options(t_piles *piles)
{
	int	i;

	i = DEPTH_SEARCH - 1;
	piles->current_opt[i]++;
	while (i)
	{
		if (piles->current_opt[i] > NBR_OF_OPT)
		{
			piles->current_opt[i] = 1;
			piles->current_opt[i - 1]++;
		}
		i--;
	}
}

static void	update_best_option(t_piles *piles)
{
	int	i;

	i = 0;
	piles->best_deep_count = piles->current_deep_count;
	while (i < DEPTH_SEARCH)
	{
		piles->best_opt[i] = piles->current_opt[i];
		i++;
	}
}

void	deep_search(t_piles *piles)
{
	int	i;

	if (piles->current_opt[0] > NBR_OF_OPT)
	{
		return ;
	}
	i = 0;
	piles->current_deep_count = 0;
	reset_copy(piles);
	while (i < DEPTH_SEARCH)
	{
		choose_algo(piles, piles->current_opt[i]);
		i++;
		if (piles->current_deep_count > piles->best_deep_count)
			break ;
	}
	if (piles->current_deep_count < piles->best_deep_count)
		update_best_option(piles);
	update_options(piles);
	deep_search(piles);
}
