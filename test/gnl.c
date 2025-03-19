#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void *ft_calloc(int count, int size)
{
    void *ptr;
    int i;

    ptr = malloc(count * size);
    if (ptr == NULL)
        return (NULL);
    i = 0;
    while (i < count * size)
    {
        ((char *)ptr)[i] = 0;
        i++;
    }
    return (ptr);
}

char *ft_substr(char *buffer, int start, int len)
{
    char *str;
    int i;

    str = malloc(len + 1);
    if (str == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = buffer[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL; // Buffer pour stocker les caractères
	static int	index = 0; // Index du buffer
	char		*line; // Ligne à retourner
	int			i; // Index pour parcourir la ligne

	if (buffer == NULL) // Si le buffer est vide, lire une nouvelle ligne
	{
		buffer = ft_calloc(100000000, sizeof(char)); // Allouer de la mémoire pour le buffer
		if (buffer == NULL) // Vérifier si l'allocation a réussi
			return (NULL);
		read(fd, buffer, 100000000); // Lire une ligne dans le buffer
		index = 0; // Réinitialiser l'index du buffer
	}
	i = index; // Initialiser l'index de la ligne
	while (buffer[index] != '\n' && buffer[index] != '\0') // Parcourir le buffer jusqu'à la fin de la ligne
		index++;
	line = ft_substr(buffer, i, index - i); // Extraire la ligne du buffer
	if (buffer[index] == '\n') // Si la ligne est terminée par un retour à la ligne
		index++; // Passer au caractère suivant
	else // Sinon, la fin du fichier a été atteinte
	{
		free(buffer); // Libérer la mémoire allouée pour le buffer
		buffer = NULL; // Réinitialiser le buffer
	}
	return (line); // Retourner la ligne extraite
}

int main(int ac, char **av)
{
    int fd;
    char *line;

    if (ac != 2)
        return (1);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}