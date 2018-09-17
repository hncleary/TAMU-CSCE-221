#ifndef KEY_VALUE_H
#define KEY_VALUE_H

#include <iostream>

template <typename T, typename E>
struct key_value{
	T key;
	E value;
	key_value(T k = T(), E v = E())
	: key(k), value(v)
	{}  
};

template <typename T, typename E>
bool operator> (const key_value<T, E> &left, const key_value<T, E> &right)
{
    return left.key > right.key;
}

template <typename T, typename E>
bool operator>= (const key_value<T, E> &left, const key_value<T, E> &right)
{
    return left.key >= right.key;
}

template <typename T, typename E>
bool operator< (const key_value<T, E> &left, const key_value<T, E> &right)
{
    return left.key < right.key;
}

template <typename T, typename E>
bool operator<= (const key_value<T, E> &left, const key_value<T, E> &right)
{
    return left.key <= right.key;
}

template <typename T, typename E>
bool operator== (const key_value<T, E> &left, const key_value<T, E> &right)
{
    return left.key == right.key;
}

template <typename T, typename E>
bool operator!= (const key_value<T, E> &left, const key_value<T, E> &right)
{
    return left.key != right.key;
}

template <typename T, typename E>
std::ostream& operator<<(std::ostream& out, const key_value<T, E>& kvp)
{
	
	return out << kvp.key << " " << kvp.value;
}

#endif