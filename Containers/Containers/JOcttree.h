/** Quadtree with AABB boxes and gameobjects, created to use on the game engine: JayEngine. */
#ifndef __JOCTTREE__
#define __JOCTTREE__

#include "Math.h"
#include <list>
#include <vector>

class GameObject;

//---------------------------------------------------
//---------------TreeNode----------------------------
//---------------------------------------------------

class oTreeNode
{
public:
	oTreeNode(const AABB& _box);
	~oTreeNode();

	void insert(GameObject* obj);
	void erase(GameObject* obj);

	void coollectBoxes(std::vector<AABB>& vec);
	void coollectGO(std::vector<GameObject*>& vec);
	//TODO: intersection funct(template for primitives)


	void divideNode();
	void ajustNode();
	bool intersectsAllChilds(const AABB& _box);

	/*template<class TYPE>
	void collectCandidates(std::vector<GameObject*>& vec, const TYPE& primitive);*/

	void collectCandidates(std::vector<GameObject*>& vec, const Frustum& frustum);

public:
	AABB box;
	std::list<GameObject*> objects;
	oTreeNode* parent = nullptr;
	oTreeNode* childs[8];
};

//---------------------------------------------------
//---------------JQuadTree---------------------------
//---------------------------------------------------

class JOctTree
{
public:
	JOctTree();
	virtual ~JOctTree();

	void insert(GameObject* obj);
	void erase(GameObject* obj);

	void setRoot(const AABB& _box);
	void clear();

	/*template<class TYPE>
	void collectCandidates(std::vector<GameObject*>& vec, const TYPE& primitive);*/

	void collectCandidates(std::vector<GameObject*>& vec, const Frustum& primitive);

public:
	oTreeNode* rootNode = nullptr;
};


#endif // !__JOCTTREE__