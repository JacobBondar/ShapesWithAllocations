#pragma once
#include <iostream>
#include "ImageDataStructure.h"
#include "Pixel.h"

class Image
{
public:
	Image();
	Image(int width, int height);
	Image(int width, int height, Pixel pixel);
	Pixel& operator()(unsigned int x, unsigned int y);
	Pixel operator()(unsigned int x, unsigned int y) const;
	Image& operator=(const Image& image2);

	unsigned int getHeight() const;
	unsigned int getWidth() const;

private:
	ImageDataStructure m_data;
	void insertIntoMembers(int width, int height, const Pixel& p);
	Pixel& getPixelForOperator(unsigned int x, unsigned int y) const;
};

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


