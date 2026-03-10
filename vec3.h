#pragma once
template<typename T>
struct Vector2
{
	T x;
	T y;
};

template<typename T>
Vector2<T> operator+(Vector2<T> a, Vector2<T> b)
{
	Vector2<T> v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	return v;
}

template<typename T>
Vector2<T> operator-(Vector2<T> a, Vector2<T> b)
{
	Vector2<T> v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	return v;
}

template<typename T>
Vector2<T> operator*(Vector2<T> v, float s)
{
	Vector2<T> r;
	r.x = v.x * s;
	r.y = v.y * s;
	return r;
}

template<typename T>
Vector2<T> operator/(Vector2<T> v, float s)
{
	Vector2<T> r;
	r.x = v.x / s;
	r.y = v.y / s;
	return r;
}

using vec2f = Vector2<float>;	// Compiler replaces "vec2f" with "Vector2<float>"
using vec2d = Vector2<double>;	// Compiler replaces "vec2D" with "Vector2<double>"
using vec2i = Vector2<int>;		// Compiler replaces "vec2I" with "Vector2<int>"
