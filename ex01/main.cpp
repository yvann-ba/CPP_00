#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data myData;
    myData.id = 3000;
    myData.name = "Captain Flam";

    std::cout << "Original Data pointer: " << &myData << std::endl;
    std::cout << "myData.id   = " << myData.id << std::endl;
    std::cout << "myData.name = " << myData.name << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);

    Data* dataPtr = Serializer::deserialize(raw);

    std::cout << "Deserialized Data pointer: " << dataPtr << std::endl;

    if (dataPtr == &myData)
    {
        std::cout << "Pointers match! The serialization/deserialization worked" << std::endl;
    }
    else
    {
        std::cout << "Pointers do NOT match!" << std::endl;
    }

    std::cout << "dataPtr->id   = " << dataPtr->id << std::endl;
    std::cout << "dataPtr->name = " << dataPtr->name << std::endl;

    return 0;
}
