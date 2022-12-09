/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 05:30:56 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/28 17:41:48 by pbergero         ###   ########.fr       */
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

static char	*ft_itoa_hexa(unsigned long long ptr, char *base)
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

int	printhexa(unsigned int nbr, char *base)
{
	char	*nb;
	int		nd;

	nb = ft_itoa_hexa(nbr, base);
	nd = printstr(nb);
	free(nb);
	return (nd);
}
