#include "./Serialize/Serialize.hpp"
#include <iostream>

int main()
{
	Data dataStruct;
	Data* deserializedDataStruct;
	dataStruct.m_data = 10;

	uintptr_t	uintPtr;

	uintPtr = Serialize::serialize(&dataStruct);
	deserializedDataStruct = Serialize::deserialize(uintPtr);

	std::cout << &dataStruct << " & " << dataStruct.m_data << std::endl;
	std::cout << deserializedDataStruct << " & " << deserializedDataStruct->m_data << std::endl;
}