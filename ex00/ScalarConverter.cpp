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

bool isChar(const std::string &s, int count)
{
    if (count == 1 && !isdigit(s.c_str()[0])) return true;
    // else if (count == 3 && s.c_str()[0] == '\'' && s.c_str()[2] == '\'') return true;
    else return false;
}

bool isPseudoLiteral(const std::string &s)
{
    if (s == "-inff" || s == "-inf" || s == "+inff" || s == "+inf" || s == "nanf" || s == "nan") {
        return true;
    }
    else return false;
}

void ScalarConverter::convert(const std::string &s)
{
    std::cout << s << std::endl;
    int sLenght = s.length();

    if (sLenght < 1) { // TODO!!! sLenght > 
        std::cerr << "Error: Empty argument" << std::endl;
        std::exit(1);
    }

    char c = -1;
    int i = -1;
    float f = -1;
    double d = -1;
    bool isPseudo = isPseudoLiteral(s);

    if (isPseudo) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        std::cout << "float: " << s;
        if (s == "-inf" || s == "+inf" || s == "nan") std::cout << "f";
        std::cout << std::endl;

        std::cout << "double: ";
        if (s == "-inff" || s == "+inff" || s == "nanf") {
            for (int index = 0; index < sLenght - 1; index++) std::cout << s[index];
        }
        else std::cout << s;
        std::cout << std::endl;

    } else if (isChar(s, sLenght)) {
        c = s[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);

        if (i < 32 || i > 126) std::cout << "char: Non displayable" << std::endl;
        else std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    } else {


        

    }

    // char *i = NULL;
    // double d = std::strtod(s.c_str(), &i);

    // std::cout << "d: " << d << ", i: " << i << std::endl;

    // char *y = NULL;
    // float f = std::strtof(s.c_str(), &y);
    // std::cout << "f: " << f << ", y: " << y  << std::endl;


    // convertToChar(s, sCount);
    // convertToInt(s, sCount);
    // convertToFloat(s, sCount);
    // convertToDouble(s, sCount);
}
