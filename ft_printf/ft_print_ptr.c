/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:32:33 by bayam             #+#    #+#             */
/*   Updated: 2025/07/19 22:18:42 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				count;
	uintptr_t		addr;

	count = 0;
	addr = (uintptr_t)ptr;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	else
	{
		count += write(1, "0x", 2);
		count += ft_print_hex_recursive(addr, "0123456789abcdef");
		return (count);
	}
}
