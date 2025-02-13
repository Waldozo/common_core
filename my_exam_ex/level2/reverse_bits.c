
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
        write(1, "octet = ", 9);
        print_bits(octet);
        write(1, "\n", 1);
        write(1, "res = ", 7);
        print_bits(res);
        write(1, "\n", 1);
        octet = octet / 2;
        i--;
        write(1, "octet / 2 = ", 13);
        print_bits(octet);
        write(1, "\n", 1);

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