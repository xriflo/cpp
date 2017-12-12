#include <iostream>
#include <sstream>

namespace Engine
{
	typedef std::string String;
	class Vertex
	{
	public:
		float _x;
		float _y;
		float _z;
	public:
		float getX() const;
		void setX(float x);
		float getY() const;
		void setY(float y);
		float getZ() const;
		void setZ(float z);
		explicit Vertex(float x, float y, float z);
		explicit Vertex();
		Vertex& operator=(const Vertex &other); 
		
	};

	String ToString(const Vertex& vertex);
	Vertex operator-(const Vertex& vertex);
	Vertex& operator+=(Vertex& lhs, const Vertex& rhs);
	Vertex& operator-=(Vertex& lhs, const Vertex& rhs);
	Vertex operator+(const Vertex &v1, const Vertex &v2);
	std::ostream& operator<<(std::ostream& os, const Vertex& vertex);
	std::istream& operator>>(std::istream& os, Vertex& vertex);
}