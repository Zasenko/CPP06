#include "Base.hpp"

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}

Base *generate(void)
{
    std::srand(time(0));
    if (std::rand() % 2) {
        return
    } else if (std::rand() % 3) {

    } else {

    }
}
void identify(Base* p)
{

}
void identify(Base& p)
{

}
