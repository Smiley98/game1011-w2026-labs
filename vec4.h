#pragma once
template<typename T>
struct Vector4
{
	T x;
	T y;
	T z;
	T w;
};

template<typename T>
Vector4<T> operator+(Vector4<T> a, Vector4<T> b)
{
	Vector4<T> v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	v.w = a.w + b.w;
	return v;
}

template<typename T>
Vector4<T> operator-(Vector4<T> a, Vector4<T> b)
{
	Vector4<T> v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	v.w = a.w - b.w;
	return v;
}

template<typename T>
Vector4<T> operator*(Vector4<T> v, float s)
{
	Vector4<T> r;
	r.x = v.x * s;
	r.y = v.y * s;
	r.z = v.z * s;
	r.w = v.w * s;
	return r;
}

template<typename T>
Vector4<T> operator/(Vector4<T> v, float s)
{
	Vector4<T> r;
	r.x = v.x / s;
	r.y = v.y / s;
	r.z = v.z / s;
	r.w = v.w / s;
	return r;
}

using vec4f = Vector4<float>;	// Compiler replaces "vec2f" with "Vector2<float>"
using vec4d = Vector4<double>;	// Compiler replaces "vec2D" with "Vector2<double>"
using vec4i = Vector4<int>;		// Compiler replaces "vec2I" with "Vector2<int>"
