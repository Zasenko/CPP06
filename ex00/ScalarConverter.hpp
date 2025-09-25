#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
    public:
    static void convert(const std::string &s); // "h" "6546546" std::stod

    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &src);

    static bool isInt(const std::string &s, int count);
    static bool isDouble(const std::string &s, int count);
    static bool isFloat(const std::string &s, int count);
    static bool isPseudoLiteral(const std::string &s);
    static bool isChar(const std::string &s, int count);
    static void convertNumber(const std::string &s);
    static void convertChar(const std::string &s, int sLenght);
    static void convertPseudoLiteral(const std::string &s, int sLenght);
};

#endif
