#include <iostream>

#include "Globals.h"
#include "Point2D.h"
#include "String.h"
#include "Vector.h"
#include "JQuadTree.h"
#include "GameObject.h"

using namespace std;

int main(int argc, char** argv)
{
	LOG("Hi!");

	iPoint p1;
	iPoint p2(1, 4);
	iPoint p3(p2);
	fPoint p4 = p3.convToFloat();

	cout << "Point 1: " << p1.x << "," << p1.y << endl;
	cout << "Point 2: " << p2.x << "," << p2.y << endl;
	cout << "Point 3: " << p3.x << "," << p3.y << endl;
	cout << "Point 4: " << p4.x << "," << p4.y << endl;

	LOG("=======================================");
	LOG("=======================================");
	LOG("=======================================");

	Vector<int> vec;
	Vector<int> vec2(15);
	Vector<int> vec3(vec2);

	LOG("Vec1: %d-%d.", vec.capacity(), vec.length());
	LOG("Vec2: %d-%d.", vec2.capacity(), vec2.length());
	LOG("Vec3: %d-%d.", vec3.capacity(), vec3.length());

	system("PAUSE");

	return 0;
}