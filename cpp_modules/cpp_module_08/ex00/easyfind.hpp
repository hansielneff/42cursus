#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
int &easyfind(T container, int number)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), number);
	if (iter == container.end()) throw std::exception();
	return *iter;
}

#endif
