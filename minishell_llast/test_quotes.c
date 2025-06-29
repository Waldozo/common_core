#include <stdio.h>
#include <stdlib.h>

int	utils_parse_pipe_test(char *str, int i, int *found_pipe)
{
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			char	quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
				i++;
			if (str[i])
				i++;
			*found_pipe = 0;
		}
		else if (str[i] == '|')
		{
			if (*found_pipe)
			{
				*found_pipe = 2;
				return (0);
			}
			*found_pipe = 1;
			i++;
		}
		else if (str[i] == ' ')
			i++;
		else
		{
			*found_pipe = 0;
			while (str[i] && str[i] != ' ' && str[i] != '|' 
				&& str[i] != '\'' && str[i] != '"')
				i++;
		}
	}
	return (i);
}

int	parse_error_pipe_test(char *str)
{
	int	i;
	int	found_pipe;

	i = 0;
	found_pipe = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		return (0);
	}
	i = utils_parse_pipe_test(str, i, &found_pipe);
	if (found_pipe > 0)
	{
		printf("syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

int main()
{
	printf("Test 1: echo \"<< |\"\n");
	printf("Result: %s\n", parse_error_pipe_test("echo \"<< |\"") ? "OK" : "ERROR");
	
	printf("\nTest 2: echo \"||\" \n");
	printf("Result: %s\n", parse_error_pipe_test("echo \"||\"") ? "OK" : "ERROR");
	
	printf("\nTest 3: echo hello | grep test\n");
	printf("Result: %s\n", parse_error_pipe_test("echo hello | grep test") ? "OK" : "ERROR");
	
	printf("\nTest 4: echo hello || grep test\n");
	printf("Result: %s\n", parse_error_pipe_test("echo hello || grep test") ? "OK" : "ERROR");
	
	return (0);
}
