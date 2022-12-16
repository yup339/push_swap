/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:10 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/16 05:20:18 by pbergero         ###   ########.fr       */
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
	int		*test_a;
	int		*test_b;
	int		block_nb;
	int		mid_nbr[50];
	int		blocksize[50];
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
	int		smallest_opt;
	int		opt;
	int		flag;
	int		target;
}	t_piles;

# ifndef SMALL_SORT_LIMITS
#  define SMALL_SORT_LIMITS 5
# endif

# ifndef OPT_RA
#  define OPT_RA 1
# endif

# ifndef OPT_RRA
#  define OPT_RRA 2
# endif

# ifndef OPT_RB
#  define OPT_RB 3
# endif

# ifndef OPT_RR
#  define OPT_RR 4
# endif

# ifndef OPT_RRR
#  define OPT_RRR 5
# endif

# ifndef OPT_MIX_RA_RRB
#  define OPT_MIX_RA_RRB 6
# endif

# ifndef OPT_MIX_RRA_RB
#  define OPT_MIX_RRA_RB 7
# endif

# ifndef OPT_MIX_RRA_RB
#  define OPT_MIX_RRA_RB 7
# endif

# ifndef GROUP_100
#  define GROUP_100 3
# endif

# ifndef GROUP_500
#  define GROUP_500 5
# endif

# ifndef LIMITS_100
#  define LIMITS_100 2
# endif

# ifndef LIMITS_500
#  define LIMITS_500 10
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
void	test_push(t_piles *piles, void (*f)(t_piles *piles));
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

#endif