#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <cstdint>
#include "../Data/Data.hpp"

class Serialize
{
private:
	Serialize();
	Serialize(const Serialize& other);
	Serialize& operator=(const Serialize &);
	~Serialize();

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif