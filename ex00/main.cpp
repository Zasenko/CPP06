#include "ScalarConverter.hpp"
#include <string>

int main(int ac, char *av[])
{
    if (ac != 2) {
        std::cerr << "Error: program need 1 argument" << std::endl;
        return 1;
    }
    const std::string arg = av[1];
    ScalarConverter::convert(arg);
    return 0;
}
