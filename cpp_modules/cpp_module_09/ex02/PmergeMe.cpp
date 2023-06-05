#include <iostream>
#include <sys/time.h>
#include <errno.h>

#include "PmergeMe.hpp"

void PmergeMe::timeContainerSorts(const std::string &sequence)
{
	struct timeval			tv;
	time_t					before;
	time_t					vec_delta;
	time_t					deq_delta;
	const int sec_to_usec = 1000000;

	// Vector
	gettimeofday(&tv, NULL);
	before = tv.tv_sec * sec_to_usec + tv.tv_usec;
	std::vector<unsigned long> vec_sorted(PmergeMe::sort_vector(sequence));
	gettimeofday(&tv, NULL);
	vec_delta = (tv.tv_sec * sec_to_usec + tv.tv_usec) - before;

	// Deque
	gettimeofday(&tv, NULL);
	before = tv.tv_sec * sec_to_usec + tv.tv_usec;
	std::deque<unsigned long> deq_sorted(PmergeMe::sort_deque(sequence));
	gettimeofday(&tv, NULL);
	deq_delta = (tv.tv_sec * sec_to_usec + tv.tv_usec) - before;

	// Results
	std::cout << "Before:\t" << sequence << std::endl;	
	
	std::cout << "After: \t";
	for (size_t i = 0; i < vec_sorted.size(); i++)
		std::cout << vec_sorted[i] << ' ';
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec_sorted.size()
		<< " elements with std::vector:\t" << vec_delta << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << deq_sorted.size()
		<< " elements with std::deque: \t" << deq_delta << " microseconds" << std::endl;
}

template<typename T>
static T parseInput(const std::string &sequence)
{
	T result;
	std::stringstream seq_stream(sequence);
	std::string num_str;
	while (seq_stream >> num_str)
	{
		size_t str_len = num_str.size();
		for (size_t i = 0; i < str_len; i++)
		{
			if (!std::isdigit(num_str.at(i)) && num_str.at(i) != '+')
			{
				std::cout << "Error\n" << num_str << " is not a valid positive integer" << std::endl;
				exit(1);
			}
		}
		unsigned long num = std::strtoul(num_str.c_str(), nullptr, 10);
		if (num == 0 || errno == ERANGE)
		{
			std::cout << "Error\nFailed to parse number: " << num_str << std::endl;
			exit(1);
		}
		result.push_back(num);
	}
	return result;
}

std::vector<unsigned long> PmergeMe::sort_vector(const std::string &sequence)
{
	std::vector<unsigned long> seq(parseInput<std::vector<unsigned long> >(sequence));
	std::vector<unsigned long>::iterator it(seq.begin());

	std::vector<unsigned long> bigger;
	std::vector<unsigned long> smaller;
	while (it + 1 < seq.end())
	{
		bigger.push_back(*it > *(it + 1) ? *it : *(it + 1));
		smaller.push_back(*it < *(it + 1) ? *it : *(it + 1));
		it += 2;
	}
	if (seq.size() % 2 != 0)
		smaller.push_back(seq.back());

	std::vector<unsigned long> sorted(bigger);
	merge_sort(sorted);

	std::vector<unsigned long>::iterator smaller_it(smaller.begin());
	while (smaller_it < smaller.end())
	{
		std::vector<unsigned long>::iterator sorted_it(sorted.begin());
		while (sorted_it <= sorted.end())
		{
			if (*smaller_it <= *sorted_it || sorted_it == sorted.end())
			{
				sorted.insert(sorted_it, *smaller_it);
				break;
			}
			sorted_it++;
		}
		smaller_it++;
	}
	return sorted;
}

std::deque<unsigned long> PmergeMe::sort_deque(const std::string &sequence)
{
	std::deque<unsigned long> seq(parseInput<std::deque<unsigned long> >(sequence));
	std::deque<unsigned long>::iterator it(seq.begin());

	std::deque<unsigned long> bigger;
	std::deque<unsigned long> smaller;
	while (it + 1 < seq.end())
	{
		bigger.push_back(*it >= *(it + 1) ? *it : *(it + 1));
		smaller.push_back(*it <= *(it + 1) ? *it : *(it + 1));
		it += 2;
	}
	if (seq.size() % 2 != 0)
		smaller.push_back(seq.back());

	std::deque<unsigned long> sorted(bigger);
	merge_sort(sorted);

	std::deque<unsigned long>::iterator smaller_it(smaller.begin());
	while (smaller_it < smaller.end())
	{
		std::deque<unsigned long>::iterator sorted_it(sorted.begin());
		while (sorted_it <= sorted.end())
		{
			if (*smaller_it <= *sorted_it || sorted_it == sorted.end())
			{
				sorted.insert(sorted_it, *smaller_it);
				break;
			}
			sorted_it++;
		}
		smaller_it++;
	}
	return sorted;
}
