/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:05:10 by msariasl          #+#    #+#             */
/*   Updated: 2023/05/31 14:20:04 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	exit_program(int exitcode, char *exit_message)
{
	printf("%s\n", exit_message);
	exit(exitcode);
}

/* IS NUMBER CHECK NEED TO BE ADDED*/
static int	is_args_ok(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments!\n");
		printf("For Example: ./philosophers philoCount deathTime eatTime sleepTime eachTime(optional)\n");
		return (0);
	}
	else
	{
		printf("\nARGUMENTS SET TO:\nPhilos:%s,\nDeath:%s,\nEat:%s,\nSleep:%s,\nEach:%s\n\n",
				argv[1], argv[2], argv[3], argv[4], argv[5]);
	}
	return (1);
}

static int	set_args_to(t_book *my_book, int argc, char **argv)
{
	my_book->philo_count = atoi(argv[1]);
	my_book->death_time = atoi(argv[2]);
	my_book->eat_time = atoi(argv[3]);
	my_book->sleep_time = atoi(argv[4]);
	if (argc == 6)
		my_book->each_time = atoi(argv[5]);
	if (my_book->philo_count == 1)
	{
		printf("0 1 %s \n", TAKEN_FORK);
		usleep(my_book->death_time * 1000);
		printf("%d 1 died\n", my_book->death_time);
	}
	return (1);
}

static int init_philosophers(t_book *my_book)
{
	int i = 0;
	my_book->forks = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * 4);
	while(i < my_book->philo_count)
	{
		pthread_mutex_init(&(my_book->forks[i]), NULL);
		i++;
	}
	return 1;
}

int	main(int argc, char **argv)
{
	t_book my_book;

	int args_check_ok = is_args_ok(argc, argv);
	if (!args_check_ok)
		exit_program(1, "Args error! 0x1");

	int args_set_ok = set_args_to(&my_book, argc, argv);
	if (!args_set_ok)
		exit_program(1, "Args error! 0x2");

	int is_init_success = init_philosophers(&my_book);
	if (!is_init_success)
		exit_program(1, "Init error! 0x3");
}