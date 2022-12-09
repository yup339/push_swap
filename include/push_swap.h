/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:10 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/07 19:59:51 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# include <limits.h>

typedef struct s_piles
{
	int		*a;
	int		a_size;
	int		*b;
	int		b_size;
	int		block_nb;
	int		mid_nbr[100];
	int		blocksize[100];
	int		nb_elem;
	int		*solve;
	char	*step;
	int		nb_step;
	int		i1;
	int		i2;
	int		min1;
	int		min2;
	int		offset;
	int		flag;
	int		target;
}	t_piles;

# ifndef SMALL_SORTING_LIMITS
#  define SMALL_SORTING_LIMITS 5
# endif

void	sb(t_piles *piles, int flag);
void	sa(t_piles *piles, int flag);
void	ss(t_piles *piles, int flagA, int flagB);
void	pa(t_piles *piles);
void	pb(t_piles *piles);
void	ra(t_piles *piles, int flag);
void	rb(t_piles *piles, int flag);
void	rr(t_piles *piles, int flagA, int flagB);
void	rra(t_piles *piles, int flag);
void	rrb(t_piles *piles, int flag);
void	rrr(t_piles *piles, int flagA, int flagB);
int		print_solution(t_piles *piles);
void	ft_clean_piles(t_piles *piles);
t_piles	*ft_make_piles(int argc, char **argv);
void	pull_up(int *pile, int size);
void	pull_down(int *pile, int size, int nb);
int		check_param(int argc, char **argv);
void	small_sort(t_piles *piles);
int		check_sort(t_piles *piles);
int		is_int(char *nb);
int		in_order(int *pile, int size);
void	move_smallest_num_b(t_piles *piles);
void	bring_back_b(t_piles *piles);
int		checkdouble(int *pile, int size);
void	remove_partern(t_piles	*piles);
void	push_b_from_i(t_piles *piles, int i);
int		find_smallest_index(t_piles *piles);
void	check_rotation(t_piles *piles);
void	solve_array(t_piles *piles);
void	big_sort(t_piles *piles);
int		b_is_reversesorted(t_piles piles);
int		blocked_pushed(t_piles *piles);
void	find_mid_nbr(t_piles *piles);
void	sort3(t_piles *piles);
int		get_big_index(t_piles *piles);
int		get_right_i(int i1, int i2, int size);
void	push_a_from_i(t_piles *piles, int i);

//gonna need to be remove
void	show_piles(int *piles, int size);

#endif