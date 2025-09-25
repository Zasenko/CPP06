#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data d;
    std::cout << d.name << std::endl;

    uintptr_t ptr = Serializer::serialize(&d);

    Data *dataPtr = Serializer::deserialize(ptr);

    if (&d == dataPtr)
    {
        std::cout << "True" << std::endl;

    } else {
        std::cout << "False" << std::endl;

    }

    return 0;
}
