/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:48:07 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/09 10:51:32 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_vf/get_next_line.h"
#include <stdio.h>

void	test(const char *file)
{
	// arquivos base:
	int		fd = open(file, O_RDONLY);
	char	*gnl = get_next_line(fd);

	while (gnl != NULL)
	{
		printf("%s", gnl);
		free(gnl);
		gnl = get_next_line(fd);
	}
	if (gnl)
		free(gnl);
	close (fd);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Teste com somente um numero: \"./a.out x\"\n");
		printf("Teste 0 = lyrics.txt;\n");
		printf("Teste 1 = multilines.txt;\n");
		printf("Teste 2 = longline.txt;\n");
		printf("Teste 3 = no_newline.txt;\n");
		printf("Teste 4 = empty.txt;\n");
		printf("Teste 5 = just_newlines.txt;\n");
		printf("Teste 6 = single_newline.txt;\n");
		printf("Teste 7 = invalid fd.\n");
		return (1);
	}
	
	int	option = atoi(argv[1]);
	
	if (option == 0)
	{
		printf("====    Rap God, Eminem    ====\n\n");
		test("./main/tests/lyrics.txt");
	}
	
	else if (option == 1)
	{
		printf("==== Arquivo com várias linhas normais ====\n\n");
		test("./main/tests/multilines.txt");
	}

	else if (option == 2)
	{
		printf("==== Arquivo com linha muito longa ====\n\n");
		test("./main/tests/longline.txt");
	}

	else if (option == 3)
	{
		printf("==== Arquivo sem quebra de linha no final ====\n\n");
		test("./main/tests/no_newline.txt");
	}

	else if (option == 4)
	{
		printf("==== Arquivo vazio ====\n\n");
		test("./main/tests/empty.txt");
	}

	else if (option == 5)
	{
		printf("==== Arquivo com várias quebras de linha consecutivas ====\n\n");
		test("./main/tests/just_newlines.txt");
	}

	else if (option == 6)
	{
		printf("==== Arquivo com apenas um \\n ====\n\n");
		test("./main/tests/single_newline.txt");
	}

	else if (option == 7)
	{
		printf("==== File descriptor inválido ====\n\n");
		char *line = get_next_line(-1);
		if (!line)
			printf("fd tratado.\n");
		else
		{
			printf("fd nao tratado, retornando: %s\n", line);
			free(line);
		}
	}
	else
		printf("Escolha entre 0 e 7.\n");
    return (0);
}
