/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:20:09 by bayam             #+#    #+#             */
/*   Updated: 2025/04/09 20:54:19 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_index_in_base(char c, char *base);
char	*ft_itoa_base(int nbr, char *base);
char	*convert_to_base(long num, char *base, int is_negative);

static void	process_whitespace_and_sign(char **str, int *sign)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	base_len;
	int	result;
	int	digit;

	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	if (!ft_check_base(base) || base_len < 2)
		return (0);
	process_whitespace_and_sign(&str, &sign);
	while (*str)
	{
		digit = ft_index_in_base(*str, base);
		if (digit == -1)
			break ;
		result = result * base_len + digit;
		str++;
	}
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(num, base_to);
	return (result);
}

/*include <stdio.h>
int main(void)
{
    char *result = ft_convert_base("42", "0123456789", "01");
    printf("42 in binary: %s\n", result);
    
    // Debug: Check if atoi_base is working correctly
    int num = ft_atoi_base("42", "0123456789");
    printf("42 converted to int: %d\n", num);
    
    // Debug: Check if itoa_base is working correctly
    char *binary = ft_itoa_base(42, "01");
    printf("42 converted directly to binary: %s\n", binary);
    
    free(result);
    free(binary);
    return 0;
}*/