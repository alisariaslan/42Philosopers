/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:05:10 by msariasl          #+#    #+#             */
/*   Updated: 2023/05/30 16:45:27 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo my_philo;

	int args_ok = is_args_ok(argc, argv);
	if (!args_ok)
		return 1;
	
	int philoCount = atoi(argv[1]);
	int deathTime = atoi(argv[2]);
	int eatTime = atoi(argv[3]);
	int sleepTime = atoi(argv[4]);
	int eachTime;

	if(argc == 6)
		eachTime = atoi(argv[5]); 
}