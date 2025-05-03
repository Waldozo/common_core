#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) {
    if(argc == 1){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        int i = 1; 
        while (i < argc ) 
        {
            char *megaphone = argv[i];
            int j = 0;
            while( megaphone[j] != '\0')
            {
                megaphone[j] = std::toupper(megaphone[j]);
                j++;
                
            }
            i++;
            std::cout << megaphone << "";
        }
        std::cout << std::endl;
    }
    return 0;
}