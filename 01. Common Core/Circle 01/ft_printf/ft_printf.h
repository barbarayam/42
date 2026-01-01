/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:22:08 by bayam             #+#    #+#             */
/*   Updated: 2025/07/19 22:14:53 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_str(char *s);
int	ft_print_ptr(void *ptr);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, int uppercase);
int	ft_print_percent(void);
int	ft_print_hex_recursive(uintptr_t n, const char *base);

#endif