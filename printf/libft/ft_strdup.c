/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:34:06 by pbergero          #+#    #+#             */
/*   Updated: 2022/11/09 14:54:52 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!ptr || !s)
		return (ptr);
	ft_strlcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}
