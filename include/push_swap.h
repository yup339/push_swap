/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:10 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/18 00:33:43 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# include <limits.h>

# define SMALL_SORT_LIMITS 5

# define OPT_RA 1
# define OPT_RRA 2
# define OPT_RB 3
# define OPT_RR 4
# define OPT_RRR 5
# define OPT_MIX_RA_RRB 6
# define OPT_MIX_RRA_RB 7
# define GROUP_100 3
# define GROUP_500 7
# define LIMITS_100 3
# define LIMITS_500 20
# define DEPTH_SEARCH 3

typedef struct s_piles
{
	int		*a;
	int		a_size;
	int		*b;
	int		b_size;	
	int		*test_a;
	int		*test_b;
	int		block_nb;
	int		mid_nbr[50];
	int		blocksize[50];
	int		deep_search_choice[DEPTH_SEARCH];
	int		nb_elem;
	int		*solve;
	char	*step;
	int		nb_step;
	int		max;
	int		i1;
	int		i2;
	int		min1;
	int		min2;
	int		offset_a;
	int		offset_b;
	int		step_ra;
	int		step_rra;
	int		step_rb;
	int		step_rr;
	int		step_rrr;
	int		step_ra_rrb;
	int		step_rra_rb;
	int		current_deep_count;	
	int		best_step_count;
	int		excess_ra;
	int		excess_rb;
	int		excess_rrb;
	int		excess_rra;
	int		smallest_opt;
	int		current_opt[DEPTH_SEARCH];
	int		opt[DEPTH_SEARCH];
	int		flag;
	int		target;
}	t_piles;

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
void	fastest_push(t_piles *piles);
void	push_big_from_block(t_piles *piles);
void	make_copy(t_piles *piles);
int		getmax(t_piles *piles);
void	fix_rotation(t_piles *piles);
void	test_push_rb(t_piles *piles);
void	test_push_rra(t_piles *piles);
void	test_push_ra(t_piles *piles);
void	test_push_rr(t_piles *piles);
void	test_push_rrr(t_piles *piles);
void	test_push(t_piles *piles, void (*f)(t_piles *piles), int flag);
void	push_from_reverse_double_rotation(t_piles *piles);
void	push_from_double_rotation(t_piles *piles);
void	reset_copy(t_piles *piles);
int		is_pushable(t_piles *piles, int i);
void	push_using_ra(t_piles *piles);
void	push_using_rb(t_piles *piles);
void	push_using_rb(t_piles *piles);
void	push_using_rrb(t_piles *piles);
void	push_using_rra(t_piles *piles);
void	push_mix_ra_rrb(t_piles *piles);
int		check_around(t_piles *piles);
int		in_block(t_piles *piles, int i);
void	push_mix_rra_rb(t_piles *piles);
void	push_but_top3(t_piles *piles);
void	remove_exess_ra(t_piles *piles);
void	remove_exess_rra(t_piles *piles);
void	remove_exess_rb(t_piles *piles);
void	remove_exess_rrb(t_piles *piles);
void	reset_counters(t_piles *piles);

#endif