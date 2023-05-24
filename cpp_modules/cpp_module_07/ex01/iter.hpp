#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template<typename T>
void iter(T arr[], std::size_t size, void (*action)(T const &))
{
	for (std::size_t i = 0; i < size; i++)
		action(arr[i]);
}

#endif
