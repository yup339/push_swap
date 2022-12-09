/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:39:46 by pbergero          #+#    #+#             */
/*   Updated: 2022/10/28 17:03:12 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_mappied;
	unsigned int	i;

	i = 0;
	str_mappied = ft_strdup(s);
	if (!str_mappied)
		return (NULL);
	while (s[i])
	{
		str_mappied[i] = f(i, s[i]);
		i++;
	}
	return (str_mappied);
}
