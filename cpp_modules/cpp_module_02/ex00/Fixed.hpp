#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &fixed);
    ~Fixed();
    Fixed &operator=(const Fixed &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	static const int point = 8;
	int value;
};

#endif
