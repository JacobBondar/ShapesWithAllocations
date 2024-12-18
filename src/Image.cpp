#include "Image.h"

//-----------------------------------------------------------------------------

Image::Image()
{
	insertIntoMembers(0, 0, NULL);
}

//-----------------------------------------------------------------------------

Image::Image(int height, int width)
{
	Pixel p(' ');
	insertIntoMembers(height, width, p);
}

//-----------------------------------------------------------------------------

Image::Image(int height, int width, Pixel pixel)
{
	insertIntoMembers(height, width, pixel);
}

//-----------------------------------------------------------------------------

Pixel& Image::operator()(unsigned int y, unsigned int x)
{
	return getPixelForOperator(y, x);
}

//-----------------------------------------------------------------------------

Pixel Image::operator()(unsigned int y, unsigned int x) const
{
	return getPixelForOperator(y, x);
}

//-----------------------------------------------------------------------------

Image& Image::operator=(const Image& image)
{
	if (this != &image)
	{
		unsigned int oldHeight = m_data.getHeight();

		m_data.setHeight(image.getHeight());
		m_data.setWidth(image.getWidth());
		m_data.setNewPtr(oldHeight);

		for (int row = 0; row < m_data.getHeight(); row++)
		{
			for (int col = 0; col < m_data.getWidth(); col++)
			{
				(*this)(row, col) = image(row, col);
			}
		}
	}
	return *this;
}

//-----------------------------------------------------------------------------

bool operator==(const Image& image1, const Image& image2)
{
	if (sameSize(image1, image2)) return false;

	for (int row = 0; row < image1.getHeight(); row++)
	{
		for (int col = 0; col < image1.getWidth(); col++)
		{
			if (image1(row, col).getColor() != image2(row, col).getColor())
				return false;
		}
	}
	return true;
}

//-----------------------------------------------------------------------------

bool operator!=(const Image& image1, const Image& image2)
{
	return !(image1 == image2);
}

//-----------------------------------------------------------------------------

Image operator+(const Image& image1, const Image& image2)
{
	unsigned int bigHeight = 0, bigWidth = 0;

	bigHeight = getBigger(image1.getHeight(), image2.getHeight());
	bigWidth = image1.getWidth() + image2.getWidth();
	Image bigImage(bigHeight, bigWidth);

	for (unsigned int y = 0; y < bigHeight; y++)
	{
		unsigned int x = 0;
		while (x < image1.getWidth() && y < image1.getHeight())
		{
			bigImage(y, x) = image1(y, x);
			x++;
		}

		unsigned int ogX = x = image1.getWidth();
		while (x < image2.getWidth() + ogX && y < image2.getHeight())
		{
			bigImage(y, x) = image2(y, x - ogX);
			x++;
		}
	}
	return bigImage;
}

//-----------------------------------------------------------------------------

Image& operator+=(Image& image1, const Image& image2)
{
	image1 = image1 + image2;
	return image1;
}

//-----------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Image& image)
{	
	for (int y = 0; y < image.getHeight(); y++)
	{
		for (int x = 0; x < image.getWidth(); x++)
		{
			os << image(y, x);
			
		}
		os << std::endl;
	}
	return os;
}

//-----------------------------------------------------------------------------

Image operator|(const Image& image1, const Image& image2)
{
	unsigned int bigHeight = 0, bigWidth = 0;
	bigHeight = getBigger(image1.getHeight(), image2.getHeight());
	bigWidth = getBigger(image1.getWidth(), image2.getWidth());
	Image bigImage(bigWidth, bigHeight);

	for (int row = 0; row < bigHeight; row++)
	{
		for (int col = 0; col < bigWidth; col++)
		{
			if (row < image1.getHeight() && row < image2.getHeight() &&
				col < image1.getWidth() && col < image2.getWidth())
			{
				bigImage(row, col) = image1(row, col) | image2(row, col);
			}

			else if (row < image1.getHeight() && col < image1.getWidth())
			{
				bigImage(row, col) = image1(row, col);
			}

			else if (row < image2.getHeight() && col < image2.getWidth())
			{
				bigImage(row, col) = image2(row, col);
			} 
		}
	}
	return bigImage;
}

//-----------------------------------------------------------------------------

Image& operator|=(Image& image1, const Image& image2)
{
	image1 = image1 | image2;
	return image1;
}

//-----------------------------------------------------------------------------

Image operator&(const Image& image1, const Image& image2)
{
	unsigned int smallHeight = 0, smallWidth = 0;

	smallHeight = image1.getHeight() < image2.getHeight() ? 
				  image1.getHeight() : image2.getHeight();

	smallWidth = image1.getWidth() < image2.getWidth() ? 
				 image1.getWidth() : image2.getWidth();

	Image smallImage(smallHeight, smallWidth);

	for (int row = 0; row < smallHeight; row++)
	{
		for (int col = 0; col < smallWidth; col++)
		{
			smallImage(row, col) = image1(row, col) & image2(row, col);
		}
	}
	return smallImage;
}

//-----------------------------------------------------------------------------

Image& operator&=(Image& image1, const Image& image2)
{
	image1 = image1 & image2;
	return image1;
}

//-----------------------------------------------------------------------------

Image operator*(const Image& image, unsigned int value)
{
	Image newImage;

	for (int num = 0; num < value; num++)
	{
		newImage += image;
	}
	return newImage;
}

//-----------------------------------------------------------------------------

Image operator*(unsigned int value, Image& image)
{
	return image * value;
}

//-----------------------------------------------------------------------------

Image& operator*=(Image& image, unsigned int value)
{
	image = image * value;
	return image;
}

//-----------------------------------------------------------------------------

Image& operator*=(unsigned int value, Image& image)
{
	image *= value;
	return image;
}

//-----------------------------------------------------------------------------

Image operator~(const Image& image)
{
	Image newImage;
	newImage = image;

	for (int row = 0; row < image.getHeight(); row++)
	{
		for (int col = 0; col < image.getWidth(); col++)
		{
			if (newImage(row, col).getColor() == WHITE_COLOR)
			{
				newImage(row, col) = BLACK_COLOR;
			}

			else if (newImage(row, col).getColor() == BLACK_COLOR)
			{
				newImage(row, col) = WHITE_COLOR;
			}
		}
	}
	return newImage;
}

//-----------------------------------------------------------------------------

unsigned int Image::getHeight() const
{
	return m_data.getHeight();
}

//-----------------------------------------------------------------------------

unsigned int Image::getWidth() const
{
	return m_data.getWidth();
}

//-----------------------------------------------------------------------------

void Image::insertIntoMembers(int height, int width ,const Pixel& p)
{
	m_data.setHeight(height);
	m_data.setWidth(width);
	m_data.setFirstPtr(p);
}

//-----------------------------------------------------------------------------

Pixel& Image::getPixelForOperator(unsigned int y, unsigned int x) const
{
	if (x >= m_data.getWidth() || y >= m_data.getHeight())
	{
		std::cerr << "You have exceeded the limits of the pictures, the " <<
			"default set now to the first index in the array\n";
		return m_data.getPixel(0, 0);
	}
	return m_data.getPixel(y, x);
}

//-----------------------------------------------------------------------------

bool sameSize(const Image& image1, const Image& image2)
{
	return image1.getHeight() != image2.getHeight() ||
		image1.getWidth() != image2.getWidth();
}

//-----------------------------------------------------------------------------

unsigned int getBigger(unsigned int firstValue, unsigned int secondValue)
{
	return firstValue > secondValue ? firstValue : secondValue;
}

//-----------------------------------------------------------------------------

unsigned int getSmaller(unsigned int firstValue, unsigned int secondValue)
{
	return firstValue < secondValue ? firstValue : secondValue;
}