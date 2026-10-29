#include <iostream>
#include <cmath>

float distancecalc (float X1, float Y1, float X2, float Y2);

int main() {
	float X1, X2, Y1, Y2;
	std::cout << "Distance Calculator\n";
	std::cout << "Enter x value of the first point: ";
	std::cin >> X1;
	std::cout << "Enter y value of the first point: "; 
	std::cin >> Y1;
	std::cout << "Enter x value of the second point: "; 
	std::cin >> X2;
	std::cout << "Enter y value of the second point: ";
	std::cin >> Y2;
	std::cout << "\nThe distance between the two points is: " << distancecalc (X1, Y1, X2, Y2); 
	return 0;
}

float distancecalc (float X1, float Y1, float X2, float Y2){
	float d = std::sqrt(std::pow(X2 - X1, 2.0f) + std::pow(Y2 - Y1, 2.0f)); 
	return d;
}
