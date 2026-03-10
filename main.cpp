// Goal: to use templates to generalize Vector2, Vector3, and Vector4 classes
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

int main()
{
	{
		vec2f a{ 1.0f, 2.0f };
		vec2f b{ 3.0f, 4.0f };
		vec2f c = a + b;
		vec2f d = a - b;
		vec2f e = a * 2.0f;
		vec2f f = a / 2.0f;
	}

	{
		vec2d a{ 1.0f, 2.0f };
		vec2d b{ 3.0f, 4.0f };
		vec2d c = a + b;
		vec2d d = a - b;
		vec2d e = a * 2.0f;
		vec2d f = a / 2.0f;
	}
	
	// Note the difference in solutions for integers vs floats!
	{
		vec2i a{ 1, 2 };
		vec2i b{ 3, 4 };
		vec2i c = a + b;
		vec2i d = a - b;
		vec2i e = a * 2;
		vec2i f = a / 2;
	}

	return 0;
}
