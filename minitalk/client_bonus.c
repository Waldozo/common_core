/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:49:23 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/19 11:49:24 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minitalk.h"

static volatile sig_atomic_t	g_signal_received = 0; // Déclaration d'une variable volatile pour indiquer la réception d'un signal

void	ft_handler(int signo, siginfo_t *siginfo, void *unused)
{
    (void)signo; // Ignorer le paramètre signo
    (void)siginfo; // Ignorer le paramètre siginfo
    (void)unused; // Ignorer le paramètre unused

	if(signo == SIGUSR1)
		g_signal_received = 1; // Mettre à jour la variable pour indiquer que le signal a été reçu
	else if(signo == SIGUSR2)
	{
		write(1, "Signal received: SIGUSR2\n", 26);
		exit(0);
	}
}

// Fonction pour envoyer un caractère au processus avec l'identifiant pid
void	ft_send_char(int pid, unsigned char c)
{
    int	bit;

    bit = 0; // Initialiser le bit à 0
    while (bit < 8) // Boucle pour envoyer chaque bit du caractère
    {
        g_signal_received = 0; // Réinitialiser la variable de signal reçu
        if (c & (1 << bit)) // Vérifier si le bit est 1
            kill(pid, SIGUSR1); // Envoyer SIGUSR1 si le bit est 1
        else
            kill(pid, SIGUSR2); // Envoyer SIGUSR2 si le bit est 0
        while (!g_signal_received) // Attendre la réception du signal
            usleep(100); // Pause de 100 microsecondes
        bit++; // Passer au bit suivant
    }
}

// Fonction pour envoyer un message au processus avec l'identifiant pid
void	send_message(int pid, const char *msg)
{
    struct sigaction act; // Déclaration d'une structure sigaction
    
    sigemptyset(&act.sa_mask); // Initialiser le masque de signaux à vide
    act.sa_flags = SA_SIGINFO; // Définir les flags pour utiliser la fonction de gestion des signaux
    act.sa_sigaction = ft_handler; // Définir la fonction de gestion des signaux
    sigaction(SIGUSR1, &act, NULL); // Enregistrer la fonction de gestion pour SIGUSR1
	sigaction(SIGUSR2, &act, NULL); // Enregistrer la fonction de gestion pour SIGUSR2
    while (*msg) // Boucle pour envoyer chaque caractère du message
    {
        ft_send_char(pid, *msg); // Envoyer le caractère courant
        msg++; // Passer au caractère suivant
    }
    ft_send_char(pid, '\0'); // Envoyer le caractère nul pour indiquer la fin du message
}

// Fonction principale
int	main(int argc, char **argv)
{
    int	pid;

    if (argc != 3) // Vérifier le nombre d'arguments
    {
        ft_printf("Usage: %s [PID] [MESSAGE]\n", argv[0]); // Afficher un message d'utilisation
        return (1); // Retourner une erreur
    }
    pid = ft_atoi(argv[1]); // Convertir le premier argument en entier (PID)
    if (pid <= 0) // Vérifier si le PID est valide
    {
        ft_printf("Invalid PID.\n"); // Afficher un message d'erreur si le PID est invalide
        return (1); // Retourner une erreur
    }
    send_message(pid, argv[2]); // Envoyer le message au processus avec l'identifiant pid
    return (0); // Retourner 0 pour indiquer que le programme s'est terminé avec succès
}