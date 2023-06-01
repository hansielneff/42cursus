#include "Span.hpp"

#include <algorithm>
#include <exception>

Span::Span(unsigned int N) : size(N) {}

Span::Span(const Span &span) : size(span.getSize()) {}

Span::~Span() {}

Span &Span::operator=(const Span &span)
{
	if (this == &span) return *this;

	data.clear();
	unsigned int new_size = span.getSize();
	for (unsigned int i = 0; i < new_size; i++)
		data.push_back(span.getData()[i]);
	return *this;
}

unsigned int Span::getSize() const
{
	return size;
}

const std::vector<int> &Span::getData() const
{
	return data;
}

void Span::addNumber(int n)
{
	if (data.size() >= size) throw std::exception();
	data.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	unsigned int smallest = *std::max_element(data.begin(), data.end());
	std::vector<int> tmp(data);
	std::sort(tmp.begin(), tmp.end());
	unsigned int tmp_size = tmp.size();
	for (unsigned int i = 0; i < tmp_size - 1; i++)
	{
		unsigned int span = std::abs(tmp[i] - tmp[i + 1]);
		if (span < smallest) smallest = span;
	}
	return smallest;
}

unsigned int Span::longestSpan() const
{
	return *std::max_element(data.begin(), data.end())
			- *std::min_element(data.begin(), data.end());
}
