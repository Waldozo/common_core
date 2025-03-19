/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:49:10 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/19 11:49:11 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minitalk.h"

static void	ft_handle_char(unsigned char c)
{
	static char		buffer[100000000]; // Buffer pour stocker les caractères
	static size_t	buffer_index = 0; // Index du buffer

	if (c == '\0') // Si le caractère est nul, afficher le buffer
	{
		write(1, buffer, buffer_index);
		write(1, "\n", 1);
		buffer_index = 0; // Réinitialiser l'index du buffer
	}
	else
	{
		buffer[buffer_index++] = c; // Ajouter le caractère au buffer
		if (buffer_index == sizeof(buffer) - 1) // Si le buffer est plein, l'afficher
		{
			write(1, buffer, buffer_index);
			buffer_index = 0; // Réinitialiser l'index du buffer
		}
	}
}

void	ft_handler_serv(int sig, siginfo_t *info, void *unused)
{
	static unsigned char	c = 0; // Caractère en cours de construction
	static int				bit_count = 0; // Compteur de bits

	(void)unused;
	c |= (sig == SIGUSR1) << bit_count; // Ajouter le bit reçu au caractère
	bit_count++;
	if (bit_count == 8) // Si 8 bits ont été reçus, traiter le caractère
	{
		ft_handle_char(c);
		if (c == '\0') // Si le caractère est nul, afficher le buffer
			kill(info->si_pid, SIGUSR2); // Envoyer un signal de confirmation au client
		bit_count = 0; // Réinitialiser le compteur de bits
		c = 0; // Réinitialiser le caractère
	}
	kill(info->si_pid, SIGUSR1); // Envoyer un signal de confirmation au client
}


int	main(void)
{
	struct sigaction	act; // Structure pour définir le gestionnaire de signal

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_handler_serv;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == -1 || sigaction(SIGUSR2, &act,
			NULL) == -1)
	{
		ft_printf("Error: sigaction failed\n");
		return (1);
	}
	ft_printf("SERVER PID: [%d]\n", getpid()); // Afficher le PID du serveur
	while (1)
		pause(); // Attendre les signaux
	return (0);
}