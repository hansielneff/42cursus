#ifndef RPN_HPP
#define RPN_HPP

# include <string>

class RPN
{
public:
	static double evaluate(const std::string &expr);

private:
	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);
};

#endif
