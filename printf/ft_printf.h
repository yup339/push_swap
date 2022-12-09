/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 01:32:18 by pbergero          #+#    #+#             */
/*   Updated: 2022/12/03 13:42:03 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	printnbr(int nbr);
int	printunsignednbr(unsigned int nbr);
int	printhexa(unsigned int nbr, char *base);
int	printstr(char *str);
int	printptr(uintptr_t ptr);
#endif