/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:42:34 by nmizin            #+#    #+#             */
/*   Updated: 2018/02/07 12:02:56 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Assignment name  : wdmatch
 * Expected files   : wdmatch.c
 * Allowed functions: write
 * --------------------------------------------------------------------------------
 *
 *  Write a program that takes two strings and checks whether it's possible to
 *  write the first string with characters from the second string, while respecting
 *  the order in which these characters appear in the second string.
 *
 *  If it's possible, the program displays the string, followed by a \n, otherwise
 *  it simply displays a \n.
 *
 *  If the number of arguments is not 2, the program displays a \n.
 *
 *  Examples:
 *
 *  $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
 *  faya$
 *  $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
 *  $
 *  $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
 *  quarante deux$
 *  $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
 *  $
 *  $>./wdmatch | cat -e
 *  $
 */
 
#include <unistd.h>
#include <stdio.h>

int f_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	int count;
	int j;

	if (argc == 3)
	{
		i = 0;
		count = 0;
		j = 0;
		while(argv[1][i])
		{
			while (argv[2][j] != argv[1][i] && argv[2][j])
				j++;
			if (argv[1][i] == argv[2][j])
				count++;
			i++;
		}
		if (f_len(argv[1]) == count)
		{
			i = 0;
			while(argv[1][i])
				write(1,&argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
