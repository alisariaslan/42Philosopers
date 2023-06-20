/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:38:19 by msariasl          #+#    #+#             */
/*   Updated: 2023/06/11 20:05:27 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define TAKEN_FORK "has taken a fork"
# define INT_MAX 2147483647
# define STOP 1
# define CONTINUE 0
# define FALSE 0
# define TRUE 1

typedef struct s_philo_dinner	t_pd;

typedef struct s_philo
{
	int							id;
	pthread_t					thread;
	pthread_mutex_t				*r_fork;
	pthread_mutex_t				*l_fork;
	time_t						last_meal;
	int							nbr_meals;
	int							stop;
	t_pd						*pdinner;
}								t_philo;

typedef struct s_philo_dinner
{
	t_philo						*philo;
	int							nbr_philo;
	time_t						time_to_starv;
	time_t						time_eating;
	time_t						time_sleeping;
	int							nbr_meals;
	pthread_mutex_t				*fork;
	pthread_mutex_t				msg;
	pthread_mutex_t				mstop;
	time_t						init;
	int							stop;
}								t_pd;

int								check_args(int argc, char **argv);
void							init_philo(t_pd *pdinner);
int								init_struct(t_pd *pdinner, char **argv);
int								init_mutex(t_pd *pdinner);
void							free_struct(t_pd *pdinner);
int								life(t_philo *philo, char *event);
void							*routine(void *arg);
int								check_limit_meals(t_pd *pdinner);
void							verify_death(t_pd *pdinner);
int								philos_threads_born(t_pd *pdinner);
time_t							get_time(void);
void							print_events(t_philo *philo, char *event);
void							to_sleep(time_t microsec, t_pd *pdinner);
void							ft_putstr_fd(char *s, int fd);
int								ft_str_isdigit(char *str);
int								chek_str_int_positive(const char *nptr);
int								ft_atoi(const char *nptr);
void							*ft_calloc(size_t nmemb, size_t size);
int								ft_strcmp(char *s1, char *s2);

#endif