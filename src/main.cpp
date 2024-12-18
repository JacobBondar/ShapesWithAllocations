#include <iostream>
#include "Pixel.h"
#include "Image.h"

int main()
{
	//tests

	auto p1 = Image(5, 2, 219);
	const auto p2 = Image(2, 5, 176);
	auto p3 = Image(10, 10, 219);
	std::cout << p1 << std::endl << p2 << std::endl << p3 << std::endl ;

	if (p1 != p2) std::cout << "yay!\n";
	std::cout << "p1 != p2" << std::endl;
	std::cout << p1 << std::endl << p2 << std::endl;

	if ((p1 & p2) == p1) std::cout << "yay!\n";
	std::cout << "(p1 & p2) == p1" << std::endl;
	std::cout << (p1 & p2) << std::endl << p1 << std::endl;
	std::cout << ~(p1 & p2) << std::endl;

	if ((p1 | p2) == p2) std::cout << "yay!\n";
	std::cout << "(p1 | p2) == p2" << std::endl;
	std::cout << (p1 | p2) << std::endl << p2 << std::endl;
	std::cout << ~(p1 | p2) << std::endl;

	p3 &= p1;
	if (p3 == p1) std::cout << "yay!\n";
	std::cout << "p3 == p1" << std::endl;
	std::cout << p3 << std::endl << p1 << std::endl;

	p3 |= p2;
	if (p3 == p2) std::cout << "yay!\n";
	std::cout << "p3 == p2" << std::endl;
	std::cout << p3 << std::endl << p2 << std::endl;
	
	exit(EXIT_SUCCESS);
}