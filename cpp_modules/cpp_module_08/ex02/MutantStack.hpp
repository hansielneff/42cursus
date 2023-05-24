#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <vector>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef class Iterator
	{
	public:
		Iterator(MutantStack &stack);
		Iterator(const Iterator &other);
		~Iterator();
		Iterator &operator=(const Iterator &other);

		const MutantStack<T> &getStack() const;
		size_t getIndex() const;
		const T &getValue() const;

		Iterator &operator++();
		Iterator &operator--();
		T &operator*();
		bool operator!=(const Iterator &other);
	private:
		MutantStack &stack;
		size_t index;
		T value;

		void update_value();
	} iterator;

	MutantStack();
	MutantStack(const MutantStack<T> &other);
	~MutantStack();
	MutantStack &operator=(const MutantStack<T> &other);

	operator std::stack<T>() const { return std::stack<T>(*this); }

	Iterator begin();
	Iterator end();
};

# include "MutantStack.tpp"

#endif
