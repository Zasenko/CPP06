#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data d;
    Data* dPtr = &d;

    uintptr_t ptr = Serializer::serialize(dPtr);
    Data *dataPtr = Serializer::deserialize(ptr);

    if (dPtr == dataPtr) std::cout << "compares equal: True" << std::endl;
    else  std::cout << "compares equal: False" << std::endl;

    return 0;
}
