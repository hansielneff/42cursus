#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <sstream>

class PmergeMe
{
public:
	static void timeContainerSorts(const std::string &sequence);

private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);

	static std::vector<unsigned long> sort_vector(const std::string &sequence);
	static std::deque<unsigned long> sort_deque(const std::string &sequence);

	template<typename T>
	static void merge_sort(T &seq)
	{
		if (seq.size() <= 1) return;

		typename T::iterator mid = seq.begin() + (seq.size() / 2);
		T left_half(seq.begin(), mid);
		T right_half(mid, seq.end());

		merge_sort(left_half);
		merge_sort(right_half);

		typename T::iterator seq_it = seq.begin();
		typename T::iterator left_it = left_half.begin();
		typename T::iterator right_it = right_half.begin();

		while (left_it < left_half.end() && right_it < right_half.end()) {
			if (*left_it < *right_it) {
				*seq_it = *left_it;
				left_it++;
			} else {
				*seq_it = *right_it;
				right_it++;
			}
			seq_it++;
		}

		while (left_it < left_half.end()) {
			*seq_it = *left_it;
			left_it++;
			seq_it++;
		}

		while (right_it < right_half.end()) {
			*seq_it = *right_it;
			right_it++;
			seq_it++;
		}
	}
};

#endif
