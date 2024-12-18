#pragma once
#include <iostream>
#include "ImageDataStructure.h"
#include "Pixel.h"

//-----------------------------------------------------------------------------

class Image
{
public:
	Image();
	Image(int height, int width);
	Image(int height, int width, Pixel pixel);
	Pixel& operator()(unsigned int y, unsigned int x);
	Pixel operator()(unsigned int y, unsigned int x) const;
	Image& operator=(const Image& image2);

	unsigned int getHeight() const;
	unsigned int getWidth() const;

private:
	ImageDataStructure m_data;
	void insertIntoMembers(int height, int width, const Pixel& p);
	Pixel& getPixelForOperator(unsigned int y, unsigned int x) const;
};

//-----------------------------------------------------------------------------

bool operator==(const Image& image1, const Image& image2);
bool operator!=(const Image& image1, const Image& image2);
Image operator+(const Image& image1, const Image& image2);
Image& operator+=(Image& image1, const Image& image2);
std::ostream& operator<<(std::ostream& os, const Image& image);
Image operator|(const Image& image1, const Image& image2);
Image& operator|=(Image& image1, const Image& image2);
Image operator&(const Image& image1, const Image& image2);
Image& operator&=(Image& image1, const Image& image2);
Image operator*(const Image& image, unsigned int value);
Image& operator*(unsigned int value, const Image& image);
Image& operator*=(Image& image, unsigned int value);
Image& operator*=(unsigned int value, Image& image);
Image operator~(const Image& image);

bool sameSize(const Image& image1, const Image& image2);
unsigned int getBigger(unsigned int firstValue, unsigned int secondValue);
unsigned int getSmaller(unsigned int firstValue, unsigned int secondValue);


