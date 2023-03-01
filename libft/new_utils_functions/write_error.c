/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:19:46 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/27 19:24:21 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	write_error(char *cust_mess)
{
	write(2, "Error", 5);
	if (cust_mess)
	{
		write(2, ":", 1);
		write(2, cust_mess, ft_strlen(cust_mess));
	}
	write(2, "\n", 1);
}
