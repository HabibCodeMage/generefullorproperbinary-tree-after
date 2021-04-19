#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class stackarray
{
private:
	int capacity;
	T* array;
	int t;
public:
	stackarray(int c = 10) :capacity(c), t(-1), array(new T[capacity])
	{}
	bool empty()
	{
		return t == -1;
	}

	void push(const T& value);
	void pop()
	{
		if (empty())
			throw"stack empty";
		--t;
	}
	const T& top()
	{
		if (empty())
			throw"stack empty";
		return array[t];
	}

	~stackarray()
	{}
};
template<typename T>
void stackarray<T>::push(const T& value)
{
	if (t + 1 == capacity)
		throw"stack overflow";
	else
	{
		array[++t] = value;
	}
}
template<>
inline void stackarray<string>::push(const string& value)
{
	if (t + 1 == capacity)
		throw"stack overflow";
	else
	{
		array[++t] = value;
	}
}
template<>
inline void stackarray<int>::push(const int& value)
{
	if (t + 1 == capacity)
		throw"stack overflow";
	else
	{
		array[++t] = value;
	}
}
#endif // !STACKARRAY_H

