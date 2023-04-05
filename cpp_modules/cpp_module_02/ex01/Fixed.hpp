#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &fixed);
	Fixed(const int value);
	Fixed(const float value);
    ~Fixed();
    Fixed &operator=(const Fixed &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
private:
	static const int point = 8;
	int value;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
