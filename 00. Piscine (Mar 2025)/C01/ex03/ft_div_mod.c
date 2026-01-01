/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:32:48 by bayam             #+#    #+#             */
/*   Updated: 2025/03/23 19:05:50 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int div_result;
	int mod_result;

	a = 17;
	b = 3;

	printf("a = %d, b = %d\n",a, b);
	ft_div_mod(a, b, &div_result, &mod_result);
	printf("div_result = %d, mod_result = %d\n", div_result, mod_result);
}
*/