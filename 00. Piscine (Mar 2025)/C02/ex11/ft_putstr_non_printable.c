/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:37:39 by bayam             #+#    #+#             */
/*   Updated: 2025/03/26 20:21:16 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_hex(unsigned char c)
{
	const char	hex_digits[] = "0123456789abcdef";

	ft_putchar('\\');
	ft_putchar(hex_digits[c / 16]);
	ft_putchar(hex_digits[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_put_hex((unsigned char)str[i]);
		}
		i++;
	}
}

/*int main() {
    unsigned char c = '\n'; // Non-printable character (newline)
    ft_put_hex(c);          // Should print "\0a"
    return 0;
}*/