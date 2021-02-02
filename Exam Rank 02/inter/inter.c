/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:20:02 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:20:07 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int ft_chek(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int buf[127] = { 0 };
	int i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (ft_chek(argv[1][i], argv[2]) && buf[(int)argv[1][i]] == 0)
			{
				buf[(int)argv[1][i]] = 1;
				ft_putchar(argv[1][i]);
			}
			++i;
		}
	}
	ft_putchar('\n');
	return (0);
}
