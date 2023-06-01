#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span &span);
	~Span();
	Span &operator=(const Span &span);

	unsigned int getSize() const;
	const std::vector<int> &getData() const;

	void addNumber(int n);

	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		while (begin != end) addNumber(*(begin++));
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

private:
	unsigned int size;
	std::vector<int> data;
};

#endif
