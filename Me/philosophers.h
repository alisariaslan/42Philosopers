/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:38:19 by msariasl          #+#    #+#             */
/*   Updated: 2023/05/30 16:08:05 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX	2147483647
# define EATING		"is eating"
# define THINKING	"is thinking"
# define SLEEPING	"is sleeping"
# define TAKEN_FORK	"has taken a fork"

typedef struct s_philo_info
{

	time_t				time_to_starv;
	time_t				time_eating;
	time_t				time_sleeping;
	int					nbr_meals;
	pthread_mutex_t		*fork;
	pthread_mutex_t		msg;
	pthread_mutex_t		mstop;
	time_t				init;
	int					stop;
}	t_philo_info;

typedef struct s_philo
{
	int					index;
	pthread_t			thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	t_philo_info		*info;
}	t_philo;



int		check_args(int argc, char **argv);

#endif