#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

#include <stdio.h>
int main(void)
{
    unsigned char i;
    i = 6;
    print_bits(i);
}