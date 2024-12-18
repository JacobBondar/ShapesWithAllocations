#include "ImageDataStructure.h"
#include "Image.h"

//-----------------------------------------------------------------------------

ImageDataStructure::ImageDataStructure() : m_ptr(NULL), m_height(0), m_width(0) {}

//-----------------------------------------------------------------------------

ImageDataStructure::~ImageDataStructure()
{
	for (int row = 0; row < m_height; row++)
	{
		delete[] m_ptr[row];
	}
	delete[] m_ptr;
}

//-----------------------------------------------------------------------------

int ImageDataStructure::getHeight() const
{
	return m_height;
}

//-----------------------------------------------------------------------------

int ImageDataStructure::getWidth() const 
{
	return  m_width;
}

//-----------------------------------------------------------------------------

void ImageDataStructure::setHeight(int height)
{
	m_height = height;
}

//-----------------------------------------------------------------------------

void ImageDataStructure::setWidth(int width)
{
	m_width = width;
}

//-----------------------------------------------------------------------------

void ImageDataStructure::setFirstPtr(const Pixel& p)
{
	if (m_height == 0 || m_width == 0) return;

	m_ptr = new (std::nothrow) Pixel * [m_height];
	checkAllocation(m_ptr);

	for (int row = 0; row < m_height; row++)
	{
		m_ptr[row] = new (std::nothrow) Pixel[m_width];
		checkAllocation(m_ptr[row]);

		for (int cell = 0; cell < m_width; cell++)
		{
			m_ptr[row][cell] = p;
		}
	}
}

//-----------------------------------------------------------------------------

void ImageDataStructure::setNewPtr(unsigned int oldHeight)
{
	deletePtr(oldHeight);

	m_ptr = new (std::nothrow) Pixel * [m_height];
	checkAllocation(m_ptr);

	for (int row = 0; row < m_height; row++)
	{
		m_ptr[row] = new (std::nothrow) Pixel[m_width];
		checkAllocation(m_ptr[row]);
	}
}

//-----------------------------------------------------------------------------

Pixel& ImageDataStructure::getPixel(unsigned int y, unsigned int x) const // Change
{
	return m_ptr[y][x];
}

//-----------------------------------------------------------------------------

void ImageDataStructure::deletePtr(unsigned int oldHeight)
{
	if (m_ptr == NULL) return;

	for (int row = 0; row < oldHeight; row++)
	{
		delete[] m_ptr[row];
		m_ptr[row] = NULL;
	}
	delete[] m_ptr;
	m_ptr = NULL;
}

//-----------------------------------------------------------------------------

void ImageDataStructure::checkAllocation(const void const* ptr)
{
	if (ptr == NULL)
	{
		std::cerr << "Can't allocate memory!\n";
		exit(EXIT_FAILURE);
	}
}