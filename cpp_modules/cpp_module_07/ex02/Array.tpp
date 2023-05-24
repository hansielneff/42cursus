template <typename T>
Array<T>::Array()
: _size(0)
, _data(nullptr)
{}

template <typename T>
Array<T>::Array(unsigned int n)
: _size(n)
, _data(new T[n])
{}

template <typename T>
Array<T>::Array(const Array &arr)
: _size(arr.size())
, _data(new T[arr.size()])
{
	unsigned int size = arr.size();
	for (unsigned int i = 0; i < size; i++)
		_data[i] = arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &arr)
{
	if (this == &arr) return *this;

	unsigned int size = arr.size();
	delete[] _data;
	_data = new T[size];
	for (unsigned int i = 0; i < size; i++)
		_data[i] = arr[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size) throw std::exception();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
