/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:32:09 by bayam             #+#    #+#             */
/*   Updated: 2025/07/19 22:15:52 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

int	ft_print_hex_recursive(uintptr_t n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hex_recursive(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	const char	*base;
	int			count;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = ft_print_hex_recursive(n, base);
	return (count);
}
