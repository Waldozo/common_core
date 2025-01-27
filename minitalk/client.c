#include "minitalk.h"

void	sending_signal(pid_t pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(42);
		}
		str++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Invalid number of arguments.\n");
		printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
	}
	else
		sending_signal(atoi(argv[1]), argv[2]);
	return (0);
}
