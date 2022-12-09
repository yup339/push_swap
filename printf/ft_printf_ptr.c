/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:59:55 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/28 17:41:50 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getsize(unsigned long long ptr)
{
	int	size;

	size = 0;
	while (ptr)
	{
		ptr /= 16;
		size++;
	}
	return (size);
}

char	*ptrtostring(unsigned long long ptr, char *base)
{
	int		size;
	char	*str;

	size = getsize(ptr);
	if (!ptr)
		++size;
	str = ft_calloc(size + 1, 1);
	if (!str)
		return (NULL);
	while (size--)
	{
		str[size] = base[ptr % 16];
		ptr /= 16;
	}
	return (str);
}

int	printptr(uintptr_t ptr)
{
	int		nd;
	char	*str;

	nd = printstr("0x");
	str = ptrtostring((unsigned long long)ptr, "0123456789abcdef");
	nd += printstr(str);
	free (str);
	return (nd);
}
