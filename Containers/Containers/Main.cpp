#include <iostream>

#include "Globals.h"
#include "String.h"
#include "Vector.h"
#include "JQuadTree.h"
#include "GameObject.h"

int main(int argc, char** argv)
{
	LOG("Hi!");

	Vector<int> vec;
	Vector<int> vec2(15);
	Vector<int> vec3(vec2);

	LOG("Vec1: %d-%d.", vec.capacity(), vec.length());
	LOG("Vec2: %d-%d.", vec2.capacity(), vec2.length());
	LOG("Vec3: %d-%d.", vec3.capacity(), vec3.length());

	system("PAUSE");

	return 0;
}