#pragma once
template<typename T>
struct Vector3
{
	T x;
	T y;
	T z;
};

template<typename T>
Vector3<T> operator+(Vector3<T> a, Vector3<T> b)
{
	Vector3<T> v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return v;
}

template<typename T>
Vector3<T> operator-(Vector3<T> a, Vector3<T> b)
{
	Vector3<T> v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return v;
}

template<typename T>
Vector3<T> operator*(Vector3<T> v, float s)
{
	Vector3<T> r;
	r.x = v.x * s;
	r.y = v.y * s;
	r.z = v.z * s;
	return r;
}

template<typename T>
Vector3<T> operator/(Vector3<T> v, float s)
{
	Vector3<T> r;
	r.x = v.x / s;
	r.y = v.y / s;
	r.z = v.z / s;
	return r;
}

using vec3f = Vector3<float>;	// Compiler replaces "vec2f" with "Vector2<float>"
using vec3d = Vector3<double>;	// Compiler replaces "vec2D" with "Vector2<double>"
using vec3i = Vector3<int>;		// Compiler replaces "vec2I" with "Vector2<int>"
