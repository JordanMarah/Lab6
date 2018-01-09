#ifndef MYVECTOR3 
#define MYVECTOR3


/// C00218412
/// Jordan Marah
/// 

#include <iostream>
#include <SFML/Graphics.hpp>


class MyVector3
{
public:
	double x;
	double y;
	double z;

	MyVector3();
	~MyVector3();
	std::string toString();

	// Constructors
	MyVector3(double t_x, double t_y, double t_z);
	MyVector3(sf::Vector3f t_sfVector);
	MyVector3(sf::Vector3i t_sfVector);
	MyVector3(sf::Vector2i t_sfVector);
	MyVector3(sf::Vector2u t_sfVector);
	MyVector3(sf::Vector2f t_sfVector); 
	
	// Operators
	bool operator == (const MyVector3 t_right) const;
	bool operator != (const MyVector3 t_right) const;


	MyVector3 operator +(const MyVector3 t_right) const;
	MyVector3 operator -(const MyVector3 t_right) const;
	MyVector3 operator *(const double t_scalar) const;
	MyVector3 operator /(const double t_divisor) const;
	MyVector3 operator +=(const MyVector3 t_right);
	MyVector3 operator -=(const MyVector3 t_right);

	
	// negative of a vector 
	MyVector3 operator -();
	
	// Gets the length of the vector
	double length()const;

	// Length  of vector squared
	double lengthSquared()const;

	// dot product of the two vectors
	double dot(const MyVector3 t_other) const;

	// cross product of the two vectors
	MyVector3 crossProduct(const MyVector3 t_other)const;

	// gets the angle made by the two vectors
	double angleBetween(const MyVector3 t_other)const;

	// the vector when length is 1
	MyVector3 unit() const;

	// changes the vector to have length of 1
	void normalise();

	// projection of other onto the current vector so answer will parralell to current vector.
	MyVector3 projection(const MyVector3 t_other)const;
	
	MyVector3 rejection(const MyVector3 t_other)const;


	operator sf::Vector2f() { return sf::Vector2f{ static_cast<float>(x), static_cast<float>(y) }; }; 
	operator sf::Vector2i() { return sf::Vector2i{ static_cast<int>(x), static_cast<int>(y) }; };
	operator sf::Vector2u() { return sf::Vector2u{ static_cast<unsigned int>(x), static_cast<unsigned int>(y) }; };
	operator sf::Vector3i() { return sf::Vector3i{ static_cast<int>(x), static_cast<int>(y), static_cast<int>(z) }; };
	operator sf::Vector3f() { return sf::Vector3f{ static_cast<float>(x), static_cast<float>(y), static_cast<float>(z) }; };
	
};



#endif // !MYVECTOR3