#include "ScalarConverter.hpp"
#include <cstdlib>

void convertToChar(std::string &s, int count)
{
        (void) count;



    // int i = static_cast<int>(s);

    std::cout << "char: '" << s << "'" << std::endl;
}
void convertToInt(std::string &s, int count)
{
    (void) count;
    std::cout << "int: " << s << std::endl;

}
void convertToFloat(std::string &s, int count)
{
        (void) count;

    std::cout << "float: " << s << std::endl;

}
void convertToDouble(std::string &s, int count)
{
        (void) count;

    std::cout << "double: " << s << std::endl;
}

void ScalarConverter::convert(const std::string &s)
{
    std::cout << s << std::endl;
    int sCount = s.length();

    if (sCount < 1) {
        std::cerr << "Error: Empty argument" << std::endl;
        std::exit(1);
    }

    if (sCount == 1 && !isdigit(s.c_str()[0]))
    {
        // char
        // only printable 
    }

    char *i = NULL;
    double d = std::strtod(s.c_str(), &i);

    std::cout << "d: " << d << ", i: " << i << std::endl;

    char *y = NULL;
    float f = std::strtof(s.c_str(), &y);
    std::cout << "f: " << f << ", y: " << y  << std::endl;


    // convertToChar(s, sCount);
    // convertToInt(s, sCount);
    // convertToFloat(s, sCount);
    // convertToDouble(s, sCount);
}
