/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:33:40 by msariasl          #+#    #+#             */
/*   Updated: 2023/06/11 19:33:42 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_sleep(time_t microsec, t_pd *pdinner)
{
	time_t	init;

	init = get_time();
	while (get_time() - init < microsec)
	{
		pthread_mutex_lock(&pdinner->msg);
		if (pdinner->stop == TRUE)
		{
			pthread_mutex_unlock(&pdinner->msg);
			break ;
		}
		pthread_mutex_unlock(&pdinner->msg);
		if (pdinner->nbr_philo < 100)
			usleep(100);
		else
			usleep(1000);
	}
}
