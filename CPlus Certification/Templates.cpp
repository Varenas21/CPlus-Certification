#include <iostream>
#include "Templates.h"

template <typename T>
T maxof(T a, T b)
{
	return a > b ? a : b;
}

namespace bw {
	template <typename T>
	Stack<T>::Stack(int s) {
		if (s > max_size || s < 1) throw S_err("invalid stack size");
		else S_size = s;
		S_ptr.reset(new T[S_size]);
		S_top = -1;
	}

	template <typename T>
	T& Stack<T>::push(const T& i)
	{
		if (isFull()) throw S_err("stack full");
		return S_ptr[++S_top] = i;
	}

	template<typename T>
	T& Stack<T>::pop() {
		if (isEmpty()) throw S_err("Stack empty");
		return S_ptr[S_top--];
	}
}


