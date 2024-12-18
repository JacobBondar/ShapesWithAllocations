#pragma once
#include <iosfwd>

//-----------------------------------------------------------------------------

const unsigned int BLACK_COLOR = 219;
const unsigned int GRAY_COLOR = 176;
const unsigned int WHITE_COLOR = 32;

//-----------------------------------------------------------------------------

class Pixel
{
public:
	Pixel( unsigned char pixel = ' ' );
	unsigned char getColor() const;
	Pixel& operator=(unsigned char c);

private:
	unsigned char m_color;
};

//-----------------------------------------------------------------------------

bool operator==(const Pixel& p1, const Pixel& p2);
bool operator!=(const Pixel& p1, const Pixel& p2);
std::ostream& operator<<(std::ostream&, const Pixel& p);
Pixel operator|(const Pixel& p1, const Pixel& p2);
Pixel& operator|=(Pixel& p1, const Pixel& p2);
Pixel operator&(const Pixel& p1, const Pixel& p2);
Pixel& operator&=(Pixel& p1, const Pixel& p2);