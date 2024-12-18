#pragma once
#include "Pixel.h"

class Image;

class ImageDataStructure
{
public:
	ImageDataStructure();
	~ImageDataStructure();
	
	int getHeight() const;
	int getWidth() const;
	void setHeight(int height);
	void setWidth(int width);
	void setFirstPtr(const Pixel& p);
	Pixel& getPixel(unsigned int y, unsigned int x) const;
	void setNewPtr(unsigned int oldHeight);

private:
	Pixel** m_ptr;
	int m_height;
	int m_width;

	void checkAllocation(const void const* m_ptr);
	void deletePtr(unsigned int oldWidth);
};