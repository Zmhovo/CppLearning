#include "Array.h"

Array::Array()
{
	for (int i = 0; i < exampleSize; i++)
	{
		example[i] = 1;
	}

	for (int i = 0; i < another.size(); i++)
	{
		another[i] = 2;
	}

}

Array::~Array()
{
}

std::ostream& operator<<(std::ostream& stream, const Vertex & vertex)
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z;

	return stream;
}

Vertex::Vertex(float x, float y, float z)
	:x(x),y(y),z(z)
{
}
