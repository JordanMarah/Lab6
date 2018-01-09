/// C00218412
/// Vector 3 class
/// Jordan Marah
/// Vector rejection not finished
#include "MyVector3.h"
#include <string.h>
#include <math.h>
#define PI           3.14159265358979323846

/// <summary>
/// Default constructor
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;	
}

MyVector3::MyVector3(double t_x, double t_y, double t_z) : // Constructor taking in 3 doubles (x, y, z)
	x{t_x},
	y{t_y},
	z{t_z}
{
}

MyVector3::MyVector3(sf::Vector3f t_sfVector) // Constructor has to cast floats to doubles
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = static_cast<double>(t_sfVector.z);
}

MyVector3::MyVector3(sf::Vector3i t_sfVector) // Constructor casts int to doubles
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = static_cast<double>(t_sfVector.z);
}

MyVector3::MyVector3(sf::Vector2i t_sfVector) // Takes in 2D vector, casts ints to doubles
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0;
}

MyVector3::MyVector3(sf::Vector2u t_sfVector) // Takes in 2D vector, casts unsigned int to doubles, z axis is 0
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0;
}

MyVector3::MyVector3(sf::Vector2f t_sfVector) // Takes in 2D vector, casts floats to doubles, z axis is 0
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0;
}

bool MyVector3::operator==(const MyVector3 t_right) const // Checks for equality
{
	const bool result{ x == t_right.x && y == t_right.y && z == t_right.z };
	return result;
}

bool MyVector3::operator!=(const MyVector3 t_right) const // Checks for inequality
{
	const bool result{ x != t_right.x || y != t_right.y || z != t_right.z };
	return result;
}

MyVector3 MyVector3::operator+(const MyVector3 t_right) const // Addition
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}

MyVector3 MyVector3::operator-(const MyVector3 t_right) const // Subtraction
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}
 
MyVector3 MyVector3::operator*(const double t_scalar) const // Multiplication
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

MyVector3 MyVector3::operator/(const double t_divisor) const // Division
{
	return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
}

MyVector3 MyVector3::operator+=(const MyVector3 t_right) // Addition
{
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;

	return MyVector3(x, y, z);
}

MyVector3 MyVector3::operator-=(const MyVector3 t_right) // Subtraction
{
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;
	return MyVector3(x, y, z);
}

MyVector3 MyVector3::operator-() // Makes vector negative
{
	return MyVector3(-x, -y, -z);
}

double MyVector3::length() const
{
	double length = 0.0;
	length = std::sqrt((x*x) + (y*y) + (z*z)); // square root of each axis squared and added together
	return length;
}

double MyVector3::lengthSquared() const
{
	double lengthSq = (x * x) + (y * y) + (z * z); // Each axis squared and added
	return lengthSq;
}

double MyVector3::dot(const MyVector3 t_other) const
{
	return ((x * t_other.x) + (y * t_other.y) + (z * t_other.z)); // multiplying corresponding coords on each vector and adding them
}

MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const // Gets vector perpendicular to each vector
{
	double u1 = x;
	double u2 = y;
	double u3 = z;
	double v1 = t_other.x;
	double v2 = t_other.y;
	double v3 = t_other.z;

	double i, j, k = 0;

	i = (u2 * v3) - (v2 * u3);
	j = (v1 * u3) - (u1 * v3);
	k = (u1 * v2) - (v1 * u2);
	return MyVector3(i, j, k);
}

double MyVector3::angleBetween(const MyVector3 t_other) const // acos(dot product / (magnitude of V1 * magnitude of V2))
{
	const double RADIAN_CONVERSION = 57.2958;
	MyVector3 angleVector{ x, y, z };
	double dotProduct = angleVector.dot(t_other);
	double angle = acos((dotProduct) / (angleVector.length() * t_other.length()));
	return angle * RADIAN_CONVERSION;
}

MyVector3 MyVector3::unit() const // Where vector magnitude is 1, new vector
{
	double vectorLength = length();
	double x1 = x / vectorLength;
	double y1 = y / vectorLength;
	double z1 = z / vectorLength;
	return MyVector3(x1, y1, z1);
}

void MyVector3::normalise()  // Changes vector to have magnitude of 1
{
	double vectorLength = length();

	x = x / vectorLength;
	y = y / vectorLength;
	z = z / vectorLength;
}

MyVector3 MyVector3::projection(const MyVector3 t_other) const // Projects 1 vector along the other to get a new vector
{
	MyVector3 projection{ x, y, z };
	double dotProduct = t_other.dot(projection);
	double vectorMultiplier = dotProduct / projection.length();
	MyVector3 newVector = (projection / projection.length()) * vectorMultiplier;
	return newVector;
}

MyVector3 MyVector3::rejection(const MyVector3 t_other) const // dont understand vector rejection
{
	return MyVector3();
}



