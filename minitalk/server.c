/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:05:42 by walid             #+#    #+#             */
/*   Updated: 2025/02/22 17:47:30 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_str(char *str, unsigned char i)
{
	int		len;
	char	*dest;
	int		j;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	dest = malloc(len + 2);
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (str && str[j] != '\0')
	{
		dest[j] = str[j];
		j++;
	}
	dest[len] = i;
	dest[len + 1] = '\0';
	free(str);
	return (dest);
}

void	ft_handler(int signal)
{
	static int				bit = 0;
	static unsigned char	i = 0;
	static char				*str = NULL;

	if (signal == SIGUSR1)
		i |= (1 << bit); // Fixe le bit correspondant à i
	bit++;               // Passe au bit suivant
	if (bit == 8)
	{
		str = ft_str(str, i);
		if (!str) // Si l'ajout échoue, afficher une erreur
		{
			ft_printf("Erreur dans l'ajout du caractère à str\n");
			return ;
		}
		if (i == '\0')
		{
			write(1,  str, sizeof(str-1));
			free(str);  // Libère la mémoire après l'affichage du message
			str = NULL; // Réinitialise str pour le prochain message
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
	}
	return (0);
}

// #include "minitalk.h"

// static void	ft_handle_char(unsigned char c)
// {
// 	static char		buffer[1024];
// 	static size_t	buffer_index = 0;

// 	if (c == '\0')
// 	{
// 		write(1, buffer, buffer_index);
// 		write(1, "\n", 1);
// 		buffer_index = 0;
// 	}
// 	else
// 	{
// 		buffer[buffer_index++] = c;
// 		if (buffer_index == sizeof(buffer) - 1)
// 		{
// 			write(1, buffer, buffer_index);
// 			buffer_index = 0;
// 		}
// 	}
// }

// void	ft_handler_serv(int sig, siginfo_t *info, void *unused)
// {
// 	static unsigned char	c = 0;
// 	static int				bit_count = 0;

// 	(void)unused;
// 	c |= (sig == SIGUSR1) << bit_count;
// 	bit_count++;
// 	if (bit_count == 8)
// 	{
// 		ft_handle_char(c);
// 		bit_count = 0;
// 		c = 0;
// 	}
// 	kill(info->si_pid, SIGUSR1); // Acknowledge receipt
// }

// int	main(void)
// {
// 	struct sigaction act;

// 	sigemptyset(&act.sa_mask);
// 	act.sa_sigaction = ft_handler_serv;
// 	act.sa_flags = SA_SIGINFO;
// 	if (sigaction(SIGUSR1, &act, NULL) == -1 || sigaction(SIGUSR2, &act,
// 			NULL) == -1)
// 	{
// 		ft_printf("Error: sigaction failed\n");
// 		return (1);
// 	}
// 	ft_printf("SERVER PID: [%d]\n", getpid());
// 	while (1)
// 		pause();
// 	return (0);
// }