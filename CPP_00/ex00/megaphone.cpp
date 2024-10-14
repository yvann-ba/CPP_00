#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    if (argc >= 2)
    {
        for(int i = 1; i < argc; i++)
        {
            for(int y = 0; argv[i][y] != '\0'; y++)
                argv[i][y] = std::toupper(argv[i][y]);
        }
        for(int i = 1; i < argc; i++)
            std::cout << argv[i];    
    std::cout << std::endl;

    }
    return (0);
}