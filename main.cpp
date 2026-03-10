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

//Vector2 operator-(Vector2 a, Vector2 b)
//{
//	Vector2 v;
//	v.x = a.x - b.x;
//	v.y = a.y - b.y;
//	return v;
//}
//
//Vector2 operator*(Vector2 v, float s)
//{
//	Vector2 r;
//	r.x = v.x * s;
//	r.y = v.y * s;
//	return r;
//}
//
//Vector2 operator/(Vector2 v, float s)
//{
//	Vector2 r;
//	r.x = v.x / s;
//	r.y = v.y / s;
//	return r;
//}

int main()
{
	Vector2<float> a{ 1.0f, 2.0f };
	Vector2<float> b{ 3.0f, 4.0f };
	Vector2<float> c = a + b;

	return 0;
}
