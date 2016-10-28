#include <iostream>

#include "Globals.h"
#include "String.h"
#include "JQuadTree.h"
#include "GameObject.h"

int main(int argc, char** argv)
{
	LOG("Hi!");

	JQuadTree* tree = new JQuadTree();

	if (!tree)
		return 1;

	AABB box(float3(10, 10, 10), float3(50, 50, 50));
	tree->setRoot(box);

	GameObject* obj[50];

	for (int i = 0; i < 50; ++i)
	{
		obj[i] = new GameObject();
		AABB a(float3(i, i, i), float3(i, i, i));
		obj[i]->aabb = a;

		tree->insert(obj[i]);
	}

	system("PAUSE");

	tree->clear();
	if (tree)
		delete(tree);

	for (int i = 0; i < 50; ++i)
	{
		if (obj[i])
			delete(obj[i]);
	}

	return 0;
}