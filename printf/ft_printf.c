/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 01:32:08 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/28 17:44:27 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	nd;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	nd = 0;
	while (str[nd])
		nd++;
	write (1, str, nd);
	return (nd);
}

static int	getnextarg(char c, va_list	var)
{
	int	nd;

	nd = 0;
	if (c == 'c')
		nd = printchar(va_arg(var, int));
	else if (c == 's')
		nd = printstr(va_arg(var, char *));
	else if (c == 'p')
		nd = printptr(va_arg(var, uintptr_t));
	else if (c == 'd')
		nd = printnbr(va_arg(var, int));
	else if (c == 'i')
		nd = printnbr(va_arg(var, int));
	else if (c == 'u')
		nd = printunsignednbr(va_arg(var, unsigned int));
	else if (c == 'x')
		nd = printhexa(va_arg(var, int), "0123456789abcdef");
	else if (c == 'X')
		nd = printhexa(va_arg(var, int), "0123456789ABCDEF");
	else if (c == '%')
		nd = printchar('%');
	return (nd);
}

int	ft_printf(const char *ptr, ...)
{
	int		nd;
	va_list	var;
	int		i;

	va_start(var, ptr);
	i = 0;
	nd = 0;
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			i++;
			nd += getnextarg(ptr[i], var);
		}
		else
			nd += printchar(ptr[i]);
		i++;
	}
	va_end(var);
	return (nd);
}
