/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:38:19 by msariasl          #+#    #+#             */
/*   Updated: 2023/05/31 14:22:53 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define TAKEN_FORK "has taken a fork"

typedef struct s_philo_info
{
	time_t			time_to_starv;
	time_t			time_eating;
	time_t			time_sleeping;
	int				nbr_meals;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
	pthread_mutex_t	mstop;
	time_t			init;
	int				stop;
}					t_philo_info;

typedef struct s_philo
{
	int				index;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_philo_info	*info;
}					t_philo;

typedef struct s_book
{
	int				philo_count;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				each_time;
	pthread_mutex_t	*forks;
	pthread_t		*philos;
}					t_book;

#endif