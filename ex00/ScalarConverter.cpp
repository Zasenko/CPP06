#include "ScalarConverter.hpp"
#include <cstdlib>
#include <float.h>
#include <iomanip>
		

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

// bool isDouble(const std::string &s)
// {
//     char *idx = NULL;

//     double d = std::strtod(s.c_str(), &idx);

//     if (*idx == '\0')// || (*idx && *idx != 'f' ) )
//     {
        
//     }
//     else {
//             std::cout << "d: " << d << ", i: '" << *idx << "'" << std::endl;


//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;
//         std::cout << "float: impossible" << std::endl;
//         std::cout << "double: impossible" << std::endl;

//     }

//     return true;
// }
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

    if (isPseudoLiteral(s)) {
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

    } else if (isDouble(s, sLenght)) {
        std::cout << "YES isDouble" << std::endl;

        d = std::strtod(s.c_str(), NULL);



        i = static_cast<int>(d);
        if (i < 32 || i > 126) std::cout << "char: Non displayable" << std::endl;
        else std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;




        std::cout << "int: ";
        if (d <= static_cast<double>(-2147483648) || d >= static_cast<double>(2147483647)) {
            std::cout << "impossible";
        } else {
            std::cout << static_cast<int>(d);
        }
        std::cout << std::endl;




        std::cout << "float: ";
        if (d > FLT_MAX) {
            std::cout << "+inf";
        } else if (d < FLT_MIN) {
            std::cout << "-inf";
        } else {
            std::cout << std::fixed << std::setprecision(1) << d;
        }
        std::cout << "f" << std::endl;


        std::cout << "double: " << i << ".0" << std::endl;






    } else if (isFloat(s, sLenght)) {
        std::cout << "YES isFloat" << std::endl;

        // char *p = NULL;
        // float f = std::strtod(s.c_str(), &p);

        // std::cout << "f: " << f << ", y: " << p << std::endl;
//setpresigion



        // i = static_cast<int>(d);
        // if (i < 32 || i > 126) std::cout << "char: Non displayable" << std::endl;
        // else std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

        // std::cout << "int: " << i << std::endl;



        // std::cout << "float: " << i << ".0f" << std::endl;



        // std::cout << "double: " << i << ".0" << std::endl;




    } else if (isInt(s, sLenght)) {
        std::cout << "YES isInt" << std::endl;
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
        i = static_cast<int>(num);
        if (i < 32 || i > 126) std::cout << "char: Non displayable" << std::endl;
        else std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << i << ".0f" << std::endl;
        std::cout << "double: " << i << ".0" << std::endl;
    } else {
        std::cerr << "Error: Argument is not correct" << std::endl;
    }
}
