/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:59:02 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/27 23:02:07 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	is_str_int(char *str)
{
	int	len;

	if (!str)
		return (0);
	if (*str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*(++str) != '\0')
		if (!ft_isdigit(*str))
			return (0);
	len = (int)(str - 1 - (str[0] == '-'));
	if (len > 10)
		return (0);
	if (len == 10)
	{
		if (str[0] != '-' && ft_strcmp(str, "2147483647") > 0)
			return (0);
		if (str[0] == '-' && ft_strcmp(str, "-2147483648") > 0)
			return (0);
	}
	return (1);
}
