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

int main()
{
	{
		Vector2<double> a{ 1.0f, 2.0f };
		Vector2<double> b{ 3.0f, 4.0f };
		Vector2<double> c = a + b;
		Vector2<double> d = a - b;
		Vector2<double> e = a * 2.0f;
		Vector2<double> f = a / 2.0f;
	}

	{
		Vector2<float> a{ 1.0f, 2.0f };
		Vector2<float> b{ 3.0f, 4.0f };
		Vector2<float> c = a + b;
		Vector2<float> d = a - b;
		Vector2<float> e = a * 2.0f;
		Vector2<float> f = a / 2.0f;
	}
	
	// Note the difference in solutions for integers vs floats!
	{
		Vector2<int> a{ 1, 2 };
		Vector2<int> b{ 3, 4 };
		Vector2<int> c = a + b;
		Vector2<int> d = a - b;
		Vector2<int> e = a * 2;
		Vector2<int> f = a / 2;
	}

	return 0;
}
