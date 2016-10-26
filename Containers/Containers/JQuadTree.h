/** Quadtree with AABB boxes and gameobjects, created to use on the game engine: JayEngine. */
#ifndef __J_QUADTREE__
#define __J_QUADTREE__

#include "Globals.h"
#include "Math.h"
#include <list>

class GameObject;

class TreeNode
{
public:
	TreeNode(const AABB& box);
	~TreeNode();

	void insert(GameObject* object);
	void erase(GameObject* object);

	void delSons();

public:
	AABB box;
	TreeNode* parent = nullptr;
	std::list<GameObject*> objects;
	TreeNode* childs[4];
};

class JQuadTree
{
public:
	JQuadTree();
	virtual ~JQuadTree();

	void setRoot(const AABB& box);
	void insert(GameObject* object);
	void erase(GameObject* object);

	void clear();


public:
	TreeNode* rootNode = nullptr;
};

#endif // !__J_QUADTREE__