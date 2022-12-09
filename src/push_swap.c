/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:24:01 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/08 15:06:15 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	checkdouble(int *pile, int size)
{
	int	nbr;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		nbr = pile[i];
		j = i + 1;
		while (j < size)
		{
			if (nbr == pile[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int(char *nb)
{
	long	n;

	n = ft_long_atoi(nb);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

int	check_param(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i] != NULL)
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

/*using for test*/

void	show_piles(int *piles, int size)
{
	for (int i = 0; i < size; i++)
		ft_printf("%d\n", piles[i]);
}

int	main(int argc, char **argv)
{
	t_piles	*piles;

	piles = ft_make_piles(argc, argv);
	if (!piles)
	{
		ft_printf("Error\n");
		return (-1);
	}
//	show_piles(piles->a, piles->a_size); 
//	ft_printf("\n");  
	if (piles->nb_elem <= 5)
		small_sort(piles);
	else
		big_sort(piles);
	print_solution(piles); 
	//ft_printf("\npile A\n"); //  
	//show_piles(piles->a, piles->a_size); // 
	//ft_printf("\n piles B \n"); // 
	//show_piles(piles->b, piles->b_size); // 
	//ft_printf("\n it took %d step", piles->nb_step);
	//ft_printf("\n for %d elements", piles->nb_elem);
	ft_clean_piles(piles);
	return (1);
}
