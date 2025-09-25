#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

void convertPseudoLiteral(const std::string &s, int sLenght)
{
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
}

void convertChar(const std::string &s, int sLenght)
{
    (void)sLenght;

    char c = s[0];
    if (sLenght == 1 && !isdigit(s.c_str()[0])) c = s[0];
    else if (sLenght == 3 && s.c_str()[0] == '\'' && s.c_str()[2] == '\'') c = s[1];

    int i = static_cast<unsigned int>(c);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (i < 32 || i > 126) std::cout << "char: Non displayable";
    else std::cout << "char: '" << c << "'";
    std::cout << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void convertNumber(const std::string &s)
{
    char *endptr = NULL;
    double d = std::strtod(s.c_str(), &endptr);
    if (endptr == s.c_str() || (*endptr && *endptr != 'f'))
    {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return ;
    }
    float f = static_cast<float>(d);
    int i = static_cast<int>(d);
    char c = static_cast<char>(d);

    std::cout << std::fixed << std::setprecision(1) << "char: ";
    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || std::isnan(d)) {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(c)) std::cout << "Non displayable" << std::endl;
    else { std::cout << "'" << c << "'" << std::endl; }

    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    std::cout << "float: ";
    if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else if (f == std::numeric_limits<float>::infinity())
        std::cout << "+inff" << std::endl;
    else if (f == -std::numeric_limits<float>::infinity())
        std::cout << "-inff" << std::endl;
    else
        std::cout << f << "f" << std::endl;

    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inf" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
    else
        std::cout << d << std::endl;
}

bool isChar(const std::string &s, int count)
{
    if (count == 1 && !isdigit(s.c_str()[0])) return true;
    else if (count == 3 && s.c_str()[0] == '\'' && s.c_str()[2] == '\'') return true;
    else return false;
}

bool isPseudoLiteral(const std::string &s)
{
    if (s == "-inff" || s == "-inf" || s == "+inff" || s == "+inf" || s == "nanf" || s == "nan") {
        return true;
    }
    else return false;
}

bool isFloat(const std::string &s, int count)
{
    bool sign = false;
    if (s[0] == '-' || s[0] == '+') sign = true;
    if ((sign && !isdigit(s[1])) || (!sign && !isdigit(s[0]))) return false; // ERROR

    bool dot = false;
    bool f = false;

    for (int i = sign ? 1 : 0; i < count; i++) {
        if (!isdigit(s[i])) {
            if (s[i] == '.') {
                if (dot) {
                    return false; // ERROR
                } else {
                    dot = true;
                    if (i + 1 >= count ) return false; // ERROR
                    else if (!isdigit(s[i + 1])) return false; // ERROR
                }
            } else if (s[i] == 'f') {
                if (i != count - 1) return false; // ERROR
                else f = true;
            } else return false; // ERROR
        }
    }
    return (dot && f);
}

bool isDouble(const std::string &s, int count)
{
    bool sign = false;
    if (s[0] == '-' || s[0] == '+') sign = true;
    if ((sign && !isdigit(s[1])) || (!sign && !isdigit(s[0]))) return false; // ERROR

    bool dot = false;

    for (int i = sign ? 1 : 0; i < count; i++) {
        if (!isdigit(s[i])) {
            if (s[i] == '.') {
                if (dot) {
                    return false; // ERROR
                } else {
                    dot = true;
                    if (i + 1 >= count ) return false; // ERROR
                    else if (!isdigit(s[i + 1])) return false; // ERROR
                }
            } else return false; // ERROR
        }
    }
    return (dot);
}

bool isInt(const std::string &s, int count)
{
    bool sign = false;
    if (s[0] == '-' || s[0] == '+') sign = true;

    for (int i = sign ? 1 : 0; i < count; i++) {
        if (!isdigit(s[i])) {
            return false; // ERROR
        }
    }
    return true;
}

void ScalarConverter::convert(const std::string &s)
{
    int sLenght = s.length();

    if (sLenght < 1) {
        std::cerr << "Error: Empty argument" << std::endl;
        std::exit(1);
    }

    if (isPseudoLiteral(s)) {
        convertPseudoLiteral(s, sLenght);
    } else if (isChar(s, sLenght)) {
        convertChar(s, sLenght);
    } else if (isDouble(s, sLenght)) {
        convertNumber(s);
    } else if (isFloat(s, sLenght)) {
        convertNumber(s);
    } else if (isInt(s, sLenght)) {
        if (sLenght > 11) {
            std::cerr << "Error: Number is too big" << std::endl;
            return;
        }
        long num = std::strtoll(s.c_str(), NULL, 10);
        if (num < -2147483648) {
            std::cerr << "Error: Number is too small" << std::endl;
            return;
        } else if (num > 2147483647) {
            std::cerr << "Error: Number is too big" << std::endl;
            return;
        }
        convertNumber(s);
    } else {
        std::cerr << "Error: Argument is not correct" << std::endl;
    }
}
