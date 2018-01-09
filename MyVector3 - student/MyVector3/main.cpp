/// C00218412
/// Jordan Marah
/// My own 3D vector class
/// 12 hours
/// 
/// 
/// </summary>
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "MyVector3.h"
#include <SFML\Graphics.hpp>
#include <string>



// The main is where methods will be tested to see if they work by comparing the method to expected results

int main()
{
	MyVector3 vectorOne{};
	MyVector3 vectorTwo{ 3.0,7.0,-8.0 };
	MyVector3 vectorThree{ 4.2, 5.6, 3.8 };

	std::cout << vectorOne.toString() << std::endl;
	std::cout << "Null / default constructor" << std::endl;
	std::cout << "----------------------" << std::endl;

	vectorOne = vectorTwo + vectorThree;
	std::cout << "Addition" << std::endl;
	std::cout << "(7.2, 12.6, -4.2)" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "----------------------" << std::endl;

	vectorOne = vectorTwo - vectorThree;
	std::cout << "Subtraction" << std::endl;
	std::cout << "(-1.2, 1.4, -11.8)" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "----------------------" << std::endl;

	MyVector3 multiply{ 8.2, -3, 2.4 };
	double scaler = 3.0;
	std::cout << "Multiply" << std::endl;
	std::cout << "(24.6, -9, 7.2" << std::endl;
	std::cout << (multiply * scaler).toString() << std::endl;
	std::cout << "-------------------" << std::endl;

	MyVector3 division{ 28, 35.3, 80 };
	double divisor = 5;
	std::cout << "Division" << std::endl;
	std::cout << "(5.6, 7.06, 16)" << std::endl;
	std::cout << (division / divisor).toString() << std::endl;
	std::cout << "----------------------" << std::endl;

	MyVector3 negativeVector;
	negativeVector = -MyVector3{ 2.8, -9.7, -6.1 };
	std::cout << "Negative" << std::endl;
	std::cout << "(-2.8, 9.7, 6.1)" << std::endl;
	std::cout << negativeVector.toString() << std::endl;
	std::cout << "----------------------" << std::endl;

	MyVector3 equality{ 3.0,7.0,5.0 };
	bool result;
	result = equality == vectorTwo;
	std::cout << "Equality" << std::endl;
	std::cout << "0" << std::endl;
	std::cout << result << std::endl;
	std::cout << "----------------------" << std::endl;

	double length{ 0.0 };
	length = vectorThree.length();
	std::cout << "Length" << std::endl;
	std::cout << "7.964923" << std::endl;
	std::cout << length << std::endl;
	std::cout << "-----------------------" << std::endl;

	double lengthSq{ 0.0 };
	lengthSq = vectorThree.lengthSquared();
	std::cout << "Length Squared" << std::endl;
	std::cout << "63.44" << std::endl;
	std::cout << lengthSq << std::endl;
	std::cout << "-----------------------" << std::endl;

	double dotProduct{ 0.0 };
	MyVector3 dotVector{ 2, 4, 6 };
	MyVector3 scalerVector{ 1, -2, 3 };
	dotProduct = dotVector.dot(scalerVector);
	std::cout << "Dot" << std::endl;
	std::cout << "12" << std::endl;
	std::cout << dotProduct << std::endl;
	std::cout << "-----------------------" << std::endl;

	MyVector3 crossProduct;
	MyVector3 vectorU{ 1, -1, 2 };
	MyVector3 vectorV{ 3, 0, 2 };
	crossProduct = vectorU.crossProduct(vectorV);
	std::cout << "Cross" << std::endl;
	std::cout << "(-2, 4, 3)" << std::endl;
	std::cout << crossProduct.toString() << std::endl;
	std::cout << "-----------------------" << std::endl;
	
	double angleBetween = 0;
	MyVector3 angleBetweenV1{ 4, 0, 7 };
	MyVector3 angleBetweenV2{ -2, 1, 3 };
	angleBetween = angleBetweenV1.angleBetween(angleBetweenV2);
	std::cout << "Angle Between" << std::endl;
	std::cout << "64.47" << std::endl;
	std::cout << angleBetween << std::endl;
	std::cout << "-----------------------" << std::endl;

	MyVector3 unitVector{ 2, 3, 4 };
	std::cout << "Unit" << std::endl;
	std::cout << "(0.3714, 0.5571, 0.7428)" << std::endl;
	std::cout << unitVector.unit().toString() << std::endl;
	std::cout << "-----------------------" << std::endl;

	unitVector.normalise();
	std::cout << "Normalized" << std::endl;
	std::cout << "(0.3714, 0.5571, 0.7428)" << std::endl;
	std::cout << unitVector.toString() << std::endl;
	std::cout << "-----------------------" << std::endl;

	MyVector3 projectionVector{ 2, -1, 3 }; 
	MyVector3 projectAlong{ 1, -3, -1 };
	MyVector3 newVector = projectAlong.projection(projectionVector);
	std::cout << "Projection" << std::endl;
	std::cout << "(0.181818181, -0.545454545, -0.181818181)" << std::endl;
	std::cout << newVector.toString() << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::system("pause");
	return EXIT_SUCCESS;
}


