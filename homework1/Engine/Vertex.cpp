#include "Vertex.hpp"

namespace Engine
{

//member functions
Vertex::Vertex(float x, float y, float z) : _x(x), _y(y), _z(z) {}
Vertex::Vertex() {}

float Vertex::getX() const
{
	return _x;
}

void Vertex::setX(float x)
{
	_x = x;
}

float Vertex::getY() const
{
	return _y;
}

void Vertex::setY(float y)
{
	_y = y;
}

float Vertex::getZ() const
{
	return _z;
}

void Vertex::setZ(float z)
{
	_z = z;
}


Vertex& Vertex::operator=(const Vertex &other)
{
	this->_x -= other._x;
	this->_y -= other._y;
	this->_z -= other._z;
	return *this;
}

String ToString(const Vertex& vertex)
{
	std::ostringstream oss;
	oss << "(" << vertex.getX() 
		<< "," << vertex.getY()
		<< "," << vertex.getZ() << ")";
	return oss.str();
}

Vertex operator-(const Vertex& vertex)
{
	Vertex newVertex(-vertex.getX(), -vertex.getY(), -vertex.getZ());
	return newVertex;
}

Vertex& operator+=(Vertex& lhs, const Vertex& rhs)
{
	lhs.setX(lhs.getX()+rhs.getX());
	lhs.setY(lhs.getY()+rhs.getY());
	lhs.setZ(lhs.getZ()+rhs.getZ());
	return lhs;
}

Vertex& operator-=(Vertex& lhs, const Vertex& rhs)
{
	lhs.setX(lhs.getX()-rhs.getX());
	lhs.setY(lhs.getY()-rhs.getY());
	lhs.setZ(lhs.getZ()-rhs.getZ());
	return lhs;
}

Vertex operator+(const Vertex &v1, const Vertex &v2)
{
	Vertex v = v1;
	v += v2;
	return v;
}

std::ostream& operator<<(std::ostream& os, const Vertex& vertex)
{
	os 	<< "(" << vertex._x
		<< "," << vertex._y
		<< "," << vertex._z << ")";
	return os;
}




std::istream& operator>>(std::istream& is, Vertex& vertex)
{
	String tempx, tempy, tempz;
	float x, y, z;

	if(is==std::cin) {std::cout << "Enter a float value for x:";}
	is >> tempx;
	
	if(is==std::cin) {std::cout << std::endl;}
	if(is==std::cin) {std::cout << "Enter a float value for y:";}
	is >> tempy;
	
	if(is==std::cin) {std::cout << std::endl;}
	if(is==std::cin) {std::cout << "Enter a float value for z:";}
	is >> tempz;
	

	try
	{
		x = std::stof(tempx);
		y = std::stof(tempy);
		z = std::stof(tempz);
		vertex.setX(x);
		vertex.setY(y);
		vertex.setZ(z);
	} 
	catch (const std::exception& e)
	{
		std::cerr<<e.what()<<" failed"<<std::endl;
	}
	std::cout<<ToString(vertex);
	return is;
}

}