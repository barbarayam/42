/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:48:25 by bayam             #+#    #+#             */
/*   Updated: 2025/04/09 18:23:56 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_atoi_base_recursive(char *str, char *base, int base_len, int sign);
int	ft_check_base(char *base);
int	ft_strlen(char	*str);

int	ft_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	calculate_result_length(long num, int base_len, int is_negative)
{
	int		len;
	long	temp;

	if (num == 0)
		return (1);
	len = 1;
	temp = num;
	while (temp >= base_len)
	{
		temp /= base_len;
		len++;
	}
	if (is_negative)
		len++;
	return (len);
}

char	*convert_to_base(long num, char *base, int is_negative)
{
	int		base_len;
	int		length;
	char	*result;
	int		index;

	base_len = ft_strlen(base);
	length = calculate_result_length(num, base_len, is_negative);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	index = length -1;
	while (num > 0)
	{
		result[index--] = base[num % base_len];
		num /= base_len;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long	num;
	int		base_len;
	int		is_negative;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (NULL);
	num = nbr;
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	return (convert_to_base(num, base, is_negative));
}
