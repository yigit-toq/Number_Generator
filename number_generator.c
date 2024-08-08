/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:43:50 by ytop              #+#    #+#             */
/*   Updated: 2024/07/27 17:43:50 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define INT_MIN	-2147483648
#define INT_MAX	2147483647

#define SUCCESS	1
#define FAILURE	0

char	**result;

int	number_generator(int number, int length);

int	number_length(int number)
{
	int	length;

	length = 0;
	if (!number)
		return (1);
	while (number)
	{
		number /= 10;
		length++;
	}
	return (length);
}

int	main(int argc, char **argv)
{
	unsigned int	number;
	int				length;

	if (argc != 2)
		return (printf("Usage: ./number_generator [number]\n"), EXIT_FAILURE);
	number = atoi(argv[1]);
	length = number_length(number);
	if (!number_generator(number, length))
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	free_number_generator(char **number, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		if (number[index])
			free(number[index]);
		index++;
	}
	if (number)
		free(number);
	return (SUCCESS);
}

int	number_generator_alloc(int length, int *flag)
{
	int	i;

	i = 0;
	if (!(*flag))
	{
		result = calloc(length, sizeof(char *));
		if (!result)
			return (FAILURE);
		while (i < length)
		{
			result[i] = calloc(8, sizeof(char));
			if (!result[i])
				return (free_number_generator(result, length), FAILURE);
			i++;
		}
		*flag = 1;
	}
	return (SUCCESS);
}

int	number_generator_print(int length, int *flag, int *index)
{
	int	i;

	i = 0;
	if (*index == length)
	{
		*index = 0;
		*flag = 0;
		while (i < length)
		{
			printf("%-8s", result[i]);
			i++;
		}
		printf("\n");
		free_number_generator(result, length);
	}
	return (SUCCESS);
}

int	number_generator(int number, int length)
{
	static char		*numbers[10]
		= {"0️⃣", "1️⃣", "2️⃣", "3️⃣", "4️⃣",
		"5️⃣", "6️⃣", "7️⃣", "8️⃣", "9️⃣"};
	static int		index;
	static int		flag;

	if (!number_generator_alloc(length, &flag))
		return (FAILURE);
	if (number < 10)
	{
		strcpy(result[index], numbers[number]);
		index++;
	}
	else
	{
		number_generator(number / 10, length);
		number_generator(number % 10, length);
	}
	number_generator_print(length, &flag, &index);
	return (SUCCESS);
}
