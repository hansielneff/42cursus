#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &arr);
	~Array();
	Array &operator=(const Array &arr);
	T &operator[](unsigned int index) const;

	unsigned int size() const;

private:
	unsigned int _size;
	T *_data;
};

# include "Array.tpp"

#endif
