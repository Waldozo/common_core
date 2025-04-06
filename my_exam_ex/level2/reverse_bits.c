
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
unsigned char reverse_bits(unsigned char octet)
{
    int i = 8;

    unsigned char res = 0;
    print_bits(octet);
    write(1, "\n", 1);
    while(i > 0)
    {
        res = res * 2 + (octet % 2);
        octet = octet / 2;
        i--;
    }
    return(res);
}



#include <stdio.h>
int main(void)
{
    unsigned char i;
    i = 6;
    unsigned char rev;

    rev = reverse_bits(i);
    // print_bits(i);
    // write(1, "\n", 1);
}