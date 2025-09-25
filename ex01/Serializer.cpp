#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    //It takes a pointer and converts it to the unsigned integer type uintptr_t.
    // (void)ptr;

    //std::bit_cast
    
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    //it takes an unsigned integer parameter and converts it to a pointer to Data.
    // (void)raw;

    return reinterpret_cast<Data*>(raw);

}
