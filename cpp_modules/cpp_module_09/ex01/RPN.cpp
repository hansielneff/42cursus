#include "RPN.hpp"

#include <algorithm>
#include <stack>
#include <iostream>

static double add(double a, double b) { return a + b; }

static double subtract(double a, double b) { return a - b; }

static double multiply(double a, double b) { return a * b; }

static double divide(double a, double b) { return a / b; }

typedef double (*operation)(double, double);

double RPN::evaluate(const std::string &expr)
{
	static const std::string oper_symbols("+-*/");
	static const operation oper_funcs[] = {
		add, subtract, multiply, divide
	};
	std::string::const_iterator it(expr.begin());
	std::stack<double> stack;

	while (it != expr.end())
	{
		size_t oper_index = oper_symbols.find_first_of(*it);
		if (isdigit(*it))
			stack.push(*it - '0');
		else if (oper_index != std::string::npos && stack.size() >= 2)
		{
			double right_oper = stack.top(); stack.pop();
			double left_oper = stack.top(); stack.pop();
			stack.push(oper_funcs[oper_index](left_oper, right_oper));
		}
		else if (*it != ' ')
			throw std::exception();
		it++;
	}
	if (stack.size() != 1)
		throw std::exception();
	return stack.top();
}
