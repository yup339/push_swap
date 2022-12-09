/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:35:09 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/28 17:41:52 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(int nbr)
{
	char	*nb;
	int		nd;

	nb = ft_itoa(nbr);
	nd = printstr(nb);
	free(nb);
	return (nd);
}

static char	*getnsize(unsigned int n)
{
	int		digit;
	long	nbr;
	char	*nb;

	digit = 1;
	nbr = n;
	while (nbr >= 10)
	{
		digit ++;
		nbr = nbr / 10;
	}
	nb = ft_calloc(digit + 1, 1);
	if (!nb)
		return (NULL);
	return (nb);
}

static int	getlen(unsigned int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}	
	return (len);
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	char	*nbr;
	int		len;
	int		i;

	nbr = getnsize(n);
	i = 0;
	if (!nbr)
		return (NULL);
	len = getlen(n);
	nbr[len] = 0;
	while (len-- > i)
	{
		nbr[len] = (n % 10) + '0';
		n /= 10;
	}
	return (nbr);
}

int	printunsignednbr(unsigned int nbr)
{
	char	*nb;
	int		nd;

	nb = ft_itoa_unsigned(nbr);
	nd = printstr(nb);
	free(nb);
	return (nd);
}
