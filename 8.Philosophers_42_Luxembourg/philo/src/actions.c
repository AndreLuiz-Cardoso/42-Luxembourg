/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <ancardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:00:06 by ancardos          #+#    #+#             */
/*   Updated: 2024/09/13 11:50:58 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philosopher *philo)
{
	pthread_mutex_lock(philo->m_left_fork);
	pthread_mutex_lock(philo->m_right_fork);
	if (stop_dinner(philo->status))
	{
		pthread_mutex_unlock(philo->m_right_fork);
		pthread_mutex_unlock(philo->m_left_fork);
		return ;
	}
	philo->eat_again += 1;
	pthread_mutex_lock(&philo->status->m_meals_repeated);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->status->m_meals_repeated);
	pthread_mutex_lock(&philo->status->m_last_meal);
	philo->last_meal = print_status(philo, EATING);
	pthread_mutex_unlock(&philo->status->m_last_meal);
	mssleep(philo->status->time_of_eating);
	pthread_mutex_unlock(philo->m_right_fork);
	pthread_mutex_unlock(philo->m_left_fork);
}

void	thinking(t_philosopher *philo)
{
	if (stop_dinner(philo->status))
		return ;
	print_status(philo, THINKING);
}

void	sleeping(t_philosopher *philo)
{
	if (stop_dinner(philo->status))
		return ;
	print_status(philo, SLEEPING);
	mssleep(philo->status->time_of_sleeping);
}
