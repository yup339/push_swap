/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:34:03 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/09 14:37:53 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	str = (char *)s;
	if (!str)
		return (NULL);
	while (s[i])
		i++;
	while (n++ <= i)
		if (*str++ == (char)c)
			return (--str);
	return (0);
}
