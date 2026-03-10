// User-defined header included with quotes ("") instead of angle brackets (<>)
#include "vec.h"
//#include "vec2.h"
//#include "vec3.h"
//#include "vec4.h"
#include <iostream>

void TestVec2();
void TestVec3();
void TestVec4();

int main()
{
	TestVec2();
	TestVec3();
	TestVec4();
	return 0;
}

void TestVec2()
{
	{
		vec2f a{ 1.0f, 2.0f };
		vec2f b{ 3.0f, 4.0f };
		vec2f c = a + b;
		vec2f d = a - b;
		vec2f e = a * 2.0f;
		vec2f f = a / 2.0f;
		printf("vec2f\n");
	}

	{
		vec2d a{ 1.0, 2.0 };
		vec2d b{ 3.0, 4.0 };
		vec2d c = a + b;
		vec2d d = a - b;
		vec2d e = a * 2.0;
		vec2d f = a / 2.0;
		printf("vec2d\n");
	}

	// Note the difference in solutions for integers vs floats!
	{
		vec2i a{ 1, 2 };
		vec2i b{ 3, 4 };
		vec2i c = a + b;
		vec2i d = a - b;
		vec2i e = a * 2;
		vec2i f = a / 2;
		printf("vec2i\n");
	}
}

void TestVec3()
{
	{
		vec3f a{ 1.0f, 2.0f, 3.0f };
		vec3f b{ 3.0f, 4.0f, 5.0f };
		vec3f c = a + b;
		vec3f d = a - b;
		vec3f e = a * 2.0f;
		vec3f f = a / 2.0f;
		printf("vec3f\n");
	}

	{
		vec3d a{ 1.0, 2.0, 3.0 };
		vec3d b{ 3.0, 4.0, 5.0 };
		vec3d c = a + b;
		vec3d d = a - b;
		vec3d e = a * 2.0;
		vec3d f = a / 2.0;
		printf("vec3d\n");
	}

	// Note the difference in solutions for integers vs floats!
	{
		vec3i a{ 1, 2, 3 };
		vec3i b{ 3, 4, 5 };
		vec3i c = a + b;
		vec3i d = a - b;
		vec3i e = a * 2;
		vec3i f = a / 2;
		printf("vec3i\n");
	}
}

void TestVec4()
{
	{
		vec4f a{ 1.0f, 2.0f, 3.0f, 4.0f };
		vec4f b{ 3.0f, 4.0f, 5.0f, 6.0f };
		vec4f c = a + b;
		vec4f d = a - b;
		vec4f e = a * 2.0f;
		vec4f f = a / 2.0f;
		printf("vec3f\n");
	}

	{
		vec4d a{ 1.0, 2.0, 3.0, 4.0 };
		vec4d b{ 3.0, 4.0, 5.0, 6.0 };
		vec4d c = a + b;
		vec4d d = a - b;
		vec4d e = a * 2.0;
		vec4d f = a / 2.0;
		printf("vec3d\n");
	}

	// Note the difference in solutions for integers vs floats!
	{
		vec4i a{ 1, 2, 3, 4 };
		vec4i b{ 3, 4, 5, 6 };
		vec4i c = a + b;
		vec4i d = a - b;
		vec4i e = a * 2;
		vec4i f = a / 2;
		printf("vec3i\n");
	}
}
