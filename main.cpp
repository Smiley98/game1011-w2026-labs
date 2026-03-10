#include "vec2.h" // User-defined header included with quotes ("") instead of angle brackets (<>)

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
