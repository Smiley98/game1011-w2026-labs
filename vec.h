#pragma once
template<typename T/*Type*/, int C/*Count*/>
struct Vector
{
	T data[C];
};

template<typename T, int C>
Vector<T, C> operator+(Vector<T, C> a, Vector<T, C> b)
{
	Vector<T, C> v;
	for (int i = 0; i < C; i++)
		v.data[i] = a.data[i] + b.data[i];
	return v;
}

template<typename T, int C>
Vector<T, C> operator-(Vector<T, C> a, Vector<T, C> b)
{
	Vector<T, C> v;
	for (int i = 0; i < C; i++)
		v.data[i] = a.data[i] - b.data[i];
	return v;
}

template<typename T, int C>
Vector<T, C> operator*(Vector<T, C> v, float s)
{
	Vector<T, C> r;
	for (int i = 0; i < C; i++)
		r.data[i] = v.data[i] * s;
	return r;
}

template<typename T, int C>
Vector<T, C> operator/(Vector<T, C> v, float s)
{
	Vector<T, C> r;
	for (int i = 0; i < C; i++)
		r.data[i] = v.data[i] / s;
	return r;
}

using vec2f = Vector<float, 2>;
using vec2d = Vector<double, 2>;
using vec2i = Vector<int, 2>;

using vec3f = Vector<float, 3>;
using vec3d = Vector<double, 3>;
using vec3i = Vector<int, 3>;

using vec4f = Vector<float, 4>;
using vec4d = Vector<double, 4>;
using vec4i = Vector<int, 4>;
