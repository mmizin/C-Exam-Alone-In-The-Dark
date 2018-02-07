/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:47:46 by nmizin            #+#    #+#             */
/*   Updated: 2018/02/07 17:49:02 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Assignment name  : rot_13
 * Expected files   : rot_13.c
 * Allowed functions: write
 * --------------------------------------------------------------------------------
 *
 *  Write a program that takes a string and displays it, replacing each of its
 *  letters by the letter 13 spaces ahead in alphabetical order.
 *
 *  'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
 *
 *  The output will be followed by a newline.
 *
 *  If the number of arguments is not 1, the program displays a newline.
 *
 *  Example:
 *
 *  $>./rot_13 "abc"
 *  nop
 *  $>./rot_13 "My horse is Amazing." | cat -e
 *  Zl ubefr vf Nznmvat.$
 *  $>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
 *  NxwuM mYXVWm , 23l $
 *  $>./rot_13 | cat -e
 *  $
 *  $>
 *  $>./rot_13 "" | cat -e
 *  $
 *  $>
 */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char arg_v;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			arg_v = argv[1][i++];
			if (((arg_v >= 'a' && arg_v <= 'z') || (arg_v >= 'A' && arg_v <= 'Z')) && arg_v + 13 < 'z')
			{
					arg_v = arg_v + 13;
			}
			else if (((arg_v >= 'a' && arg_v <= 'z') || (arg_v >= 'A' && arg_v <= 'Z')) && arg_v + 13 > 'z') 
			{
					arg_v = arg_v - 13;
			}
			write(1, &arg_v, 1);
		}
	}
		write(1, "\n", 1);
	return (0);
}
