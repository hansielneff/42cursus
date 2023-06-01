template<typename T>
MutantStack<T>::Iterator::Iterator(MutantStack &stack)
: stack(stack), index(stack.size()), value(stack.top()) {}

template<typename T>
MutantStack<T>::Iterator::Iterator(const Iterator &other)
: stack(other.stack), index(other.index), value(other.value) {}

template<typename T>
MutantStack<T>::Iterator::~Iterator() {}

template<typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator=(const Iterator &other)
{
	if (this == &other) return *this;

	stack = other.stack;
	index = other.index;
	value = other.value;
	return *this;
}

template<typename T>
const MutantStack<T> &MutantStack<T>::Iterator::getStack() const { return stack; }

template<typename T>
size_t MutantStack<T>::Iterator::getIndex() const { return index; }

template<typename T>
const T &MutantStack<T>::Iterator::getValue() const { return value; }

template<typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator++()
{
	if (++index < stack.size()) update_value();
	return *this;
}

template<typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator--()
{
	if (--index >= 0) update_value();
	return *this;
}

template<typename T>
T &MutantStack<T>::Iterator::operator*() { return value; }

template<typename T>
bool MutantStack<T>::Iterator::operator!=(const Iterator &other)
{
	return &stack != &other.getStack() || index != other.getIndex();
}

template<typename T>
void MutantStack<T>::Iterator::update_value()
{
	std::stack<T> tmp(stack);
	size_t size = stack.size() - 1;
	for (size_t i = 0; i < size - index; i++) tmp.pop();
	value = tmp.top();
}

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this == &other) return *this;

	std::stack<T>::operator=(other);
	return *this;
}

template<typename T>
typename MutantStack<T>::Iterator MutantStack<T>::begin()
{
	Iterator result(*this);
	while (result.getIndex() > 0) --result;
	return result;
}

template<typename T>
typename MutantStack<T>::Iterator MutantStack<T>::end()
{
	return Iterator(*this);
}
