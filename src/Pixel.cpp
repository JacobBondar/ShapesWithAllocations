#include "Pixel.h"
#include <ostream>

//-----------------------------------------------------------------------------

Pixel::Pixel(unsigned char pixel)
{
	if (pixel == BLACK_COLOR || pixel == GRAY_COLOR || pixel == WHITE_COLOR)
	{
		m_color = pixel;
	}

	else
	{
		m_color = ' ';
	}
}

//-----------------------------------------------------------------------------

unsigned char Pixel::getColor() const
{
	return m_color;
}

//-----------------------------------------------------------------------------

bool operator==(const Pixel& p1, const Pixel& p2)
{
	return p1.getColor() == p2.getColor();
}

//-----------------------------------------------------------------------------

bool operator!=(const Pixel& p1, const Pixel& p2)
{
	return !(p1.getColor() == p2.getColor());
}

//-----------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Pixel& p)
{
	os << p.getColor();
	return os;
}

//-----------------------------------------------------------------------------

Pixel operator|(const Pixel& p1, const Pixel& p2)
{
	if (p1 == p2)
	{
		return p1;
	}

	return p1.getColor() > p2.getColor() ? p1 : p2;
}

//-----------------------------------------------------------------------------

Pixel& operator|=(Pixel& p1, const Pixel& p2)
{
	p1 = p1 | p2;
	return p1;
}

//-----------------------------------------------------------------------------

Pixel operator&(const Pixel& p1, const Pixel& p2)
{
	if (p1 == p2)
	{
		return p1;
	}

	return p1.getColor() < p2.getColor() ? p1 : p2;
}

//-----------------------------------------------------------------------------

Pixel& operator&=(Pixel& p1, const Pixel& p2)
{
	p1 = p1 & p2;
	return p1;
}

//-----------------------------------------------------------------------------

Pixel& Pixel::operator=(unsigned char c)
{
	(*this).m_color = c;
	return *this;
}